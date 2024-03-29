/*****************************************************************************
*
* Copyright (c) 2000 - 2017, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//                    avtIndividualRayLengthDistributionQuery.C              //
// ************************************************************************* //

#include <avtIndividualRayLengthDistributionQuery.h>

#include <stdio.h>
#include <math.h>

#include <vtkCellData.h>
#include <vtkExecutive.h>
#include <vtkIdList.h>
#include <vtkPolyData.h>

#include <avtLineScanFilter.h>
#include <avtParallel.h>
#include <avtSourceFromAVTDataset.h>
#include <avtOriginatingSource.h>
#include <avtWeightedVariableSummationQuery.h>

#include <DebugStream.h>
#include <VisItException.h>

#include <vector>

// ****************************************************************************
//  Method: avtIndividualRayLengthDistributionQuery constructor
//
//  Purpose:
//      Defines the constructor.  Note: this should not be inlined in the header
//      because it causes problems for certain compilers.
//
//  Programmer: Hank Childs
//  Creation:   August 28, 2006
//
// ****************************************************************************

avtIndividualRayLengthDistributionQuery::avtIndividualRayLengthDistributionQuery()
{
    count = new double[numBins];
}


// ****************************************************************************
//  Method: avtIndividualRayLengthDistributionQuery destructor
//
//  Purpose:
//      Defines the destructor.  Note: this should not be inlined in the header
//      because it causes problems for certain compilers.
//
//  Programmer: Hank Childs
//  Creation:   August 28, 2006
//
// ****************************************************************************

avtIndividualRayLengthDistributionQuery::~avtIndividualRayLengthDistributionQuery()
{
    delete [] count;
}


// ****************************************************************************
//  Method: avtIndividualRayLengthDistributionQuery::PreExecute
//
//  Purpose:
//      Does some initialization work before the query executes.
//
//  Programmer: Hank Childs
//  Creation:   August 28, 2006
//
// ****************************************************************************

void
avtIndividualRayLengthDistributionQuery::PreExecute(void)
{
    avtLineScanQuery::PreExecute();

    if (minLength != 0.)
    {
        EXCEPTION1(VisItException, "This query only makes sense with minimum "
                     "lengths of 0.  Please try again with that length.");
    }

    delete [] count;
    count = new double[numBins];
    for (int i = 0 ; i < numBins ; i++)
        count[i] = 0.;
}


// ****************************************************************************
//  Method: avtIndividualRayLengthDistributionQuery::PostExecute
//
//  Purpose:
//      Outputs the probability distribution of encountering specific masses.
//
//  Programmer: Hank Childs
//  Creation:   August 28, 2006
//
//  Modifications:
//    Eric Brugger, Thu Mar 25 09:48:31 PDT 2010
//    I changed the name of the curve in the ultra file to avoid using
//    special characters.
//
//    Kathleen Biagas, Tue Feb 25 08:58:52 PST 2014
//    Add XML results, and ResultValues, allowing them to be set even if
//    output file could not be opened.
//
// ****************************************************************************

void
avtIndividualRayLengthDistributionQuery::PostExecute(void)
{
    int   i;

    int times = 0;
    char name[1024];
    sprintf(name, "rld_i%d.ult", times++);

    if (PAR_Rank() == 0)
    {
        bool lookingForUnused = true;
        while (lookingForUnused)
        {
            ifstream ifile(name);
            if (ifile.fail())
                lookingForUnused = false;
            else
                sprintf(name, "rld_i%d.ult", times++);
        }
    }

    char msg[1024];
    sprintf(msg, "The ray length distribution has been outputted as an "
                 "Ultra file (%s), which can then be imported into VisIt.",
                 name);
    SetResultMessage(msg);
    SetResultValue(0.);

    double *m2 = new double[numBins];
    SumDoubleArrayAcrossAllProcessors(count, m2, numBins);
    delete [] count;
    count = m2;

    double    totalCount = 0;
    for (i = 0 ; i < numBins ; i++)
        totalCount += count[i];

    if (PAR_Rank() == 0)
    {
        if (totalCount == 0.)
        {
            sprintf(msg, "The ray length distribution could not be calculated"
                    " because none of the lines intersected the data set."
                    "  If you have used a fairly large number of lines, then "
                    "this may be indicative of an error state.");
            SetResultMessage(msg);
            return;
        }
        ofstream ofile(name);
        if (ofile.fail())
        {
            sprintf(msg, "Unable to write out file containing distribution.");
            SetResultMessage(msg);
        }
        if (!ofile.fail())
            ofile << "# Ray length distribution - individual" << endl;

        MapNode result_node;
        doubleVector curve;

        double binWidth = (maxLength) / numBins;
        for (int i = 0 ; i < numBins ; i++)
        {
            double x1 = (i)*binWidth;
            double x2 = (i+1)*binWidth;
            double y = (count[i]) / (totalCount*binWidth); 
            curve.push_back(x1);
            curve.push_back(y);
            curve.push_back(x2);
            curve.push_back(y);
            if (!ofile.fail())
            {
                ofile << x1 << " " << y << endl;
                ofile << x2 << " " << y << endl;
            }
        }
        result_node["ray_length_distribution_individual"] = curve;
        SetXmlResult(result_node.ToXML());
        SetResultValues(curve);
    }
}


// ****************************************************************************
//  Method: avtIndividualRayLengthDistributionQuery::ExecuteLineScan
//
//  Purpose:
//      Examines the input data.  Note that the line scan filter will organize
//      the data so that all of the contributions from a given line will be in
//      the same vtkPolyData input.
//
//  Programmer: Hank Childs
//  Creation:   August 28, 2006
//
// ****************************************************************************

void
avtIndividualRayLengthDistributionQuery::ExecuteLineScan(vtkPolyData *pd)
{
    //Get array of cast lines
    vtkIntArray *lineids = (vtkIntArray *) 
                                  pd->GetCellData()->GetArray("avtLineID");
    if (lineids == NULL)
        EXCEPTION0(ImproperUseException);
        
    int npts = pd->GetNumberOfPoints();
    std::vector<bool> usedPoint(npts, false);
    
    vtkDataArray *arr = pd->GetCellData()->GetArray(varname.c_str());

    pd->BuildLinks();
    pd->BuildCells();

    int extraMsg = 100;
    int totalProg = totalNodes * extraMsg;
    int amtPerMsg = npts / extraMsg + 1;
    UpdateProgress(extraMsg*currentNode+2*extraMsg/3, totalProg);
    int lastMilestone = 0;

    for (int i = 0 ; i < npts ; i++)
    {
        // glue segments into one long line
        if (usedPoint[i])
            continue;
        int seg1 = 0, seg2 = 0;
        int numMatches = GetCellsForPoint(i, pd, lineids, -1, seg1, seg2);
        if (numMatches == 0)
            continue;
        if (numMatches > 2)
        {
            // We found an error condition.  Give up on this line.  This
            // happens infrequently enough that it should not affect our
            // statistics.
            continue;
        }
        int oneSide = i;
        int otherSide = i;
        int lineid = lineids->GetValue(seg1);
        if (numMatches == 1)
        {
            oneSide   = i;
            otherSide = WalkChain(pd, i, seg1, usedPoint, lineids, lineid);
        }
        else if (numMatches == 2)
        {
            oneSide   = WalkChain(pd, i, seg1, usedPoint, lineids, lineid);
            otherSide = WalkChain(pd, i, seg2, usedPoint, lineids, lineid);
        }
        if (oneSide == -1 || otherSide == -1)
        {
            // We found an error condition.  Give up on this line.  This
            // happens infrequently enough that it should not affect our
            // statistics.
            continue;
        }

        // Drop values from the line into the appropriate mass bins
        WalkLine(oneSide, otherSide, pd, lineids, lineid, arr);
        WalkLine(otherSide, oneSide, pd, lineids, lineid, arr);

        int currentMilestone = (int)(((float) i) / amtPerMsg);
        if (currentMilestone > lastMilestone)
        {
            UpdateProgress((int)(
                        extraMsg*currentNode+2*extraMsg/3.+currentMilestone/3),
                           extraMsg*totalNodes);
            lastMilestone = currentMilestone;
        }
    }
}



// ****************************************************************************
//  Method: avtIndividualRayLengthDistributionQuery::WalkLine
//
//  Purpose:
//
//  Programmer: Hank Childs
//  Creation:   August 28, 2006
//
// ****************************************************************************

void
avtIndividualRayLengthDistributionQuery::WalkLine(int startPtId, int endPtId, 
                                     vtkPolyData *output, vtkIntArray *lineids, 
                                     int lineid, vtkDataArray *arr)
{
    int curPtId = startPtId;
    int curCellId, dummyCellId;
    double pt1[3];
    double pt2[3];

    GetCellsForPoint(curPtId, output, lineids, -1, curCellId, dummyCellId);
    output->GetPoint(startPtId, pt1);
    output->GetPoint(endPtId, pt2);
    double massEncounteredSoFar = 0.0;
    double binSize = (maxLength) / (double)numBins;

    // Walk segments in the line
    while (curPtId != endPtId)
    {
        double curSegDen = (arr != NULL ? arr->GetTuple1(curCellId) : 1.);
        int newPtId, newCellId;
        WalkChain1(output, curPtId, curCellId, lineids, lineid, 
                   newPtId, newCellId);
        output->GetPoint(curPtId, pt1);
        output->GetPoint(newPtId, pt2);
        double dist = sqrt((pt2[0]-pt1[0])*(pt2[0]-pt1[0]) + 
                           (pt2[1]-pt1[1])*(pt2[1]-pt1[1]) + 
                           (pt2[2]-pt1[2])*(pt2[2]-pt1[2]));

        // Walk bins that overlap this segment, first with respect to the start point,
        // then with respect to the end point.
        double massForThisSegment = dist*curSegDen;
        double massAfterThisSegment = massEncounteredSoFar+massForThisSegment;
    
        int startBin = (int)floor(massEncounteredSoFar / binSize);
        int endBin   = (int)floor(massAfterThisSegment / binSize);

        for (int currBin = startBin ; currBin <= endBin ; currBin++) 
        {
            int bin = (currBin < 0 ? 0 : (currBin >= numBins ? numBins-1
                            : currBin));
            if (currBin == startBin && startBin == endBin)
            {
                count[bin] += curSegDen*dist;
            }
            else if (currBin == startBin)
            {
                double massForNextBin = (currBin+1)*binSize;
                double massContrib = massForNextBin - massEncounteredSoFar;
                count[bin] += massContrib;
            }
            else if (currBin == endBin) 
            {
                double massThroughStartOfBin = (currBin)*binSize;
                double massLeft = massAfterThisSegment - massThroughStartOfBin;
                count[bin] += massLeft;
            }
            else
            {
                count[bin] += curSegDen*binSize;
            }
        }
        massEncounteredSoFar += massForThisSegment;

        curPtId   = newPtId;
        curCellId = newCellId;

        if (curCellId == -1 && curPtId != endPtId)
        {
            debug1 << "INTERNAL ERROR: path could not be reproduced." 
                   << endl;
            return;
        }
    }
}



