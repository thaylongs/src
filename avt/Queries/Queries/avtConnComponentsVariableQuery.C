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
//                      avtConnComponentsVariableQuery.C                     //
// ************************************************************************* //


#include <avtConnComponentsVariableQuery.h>

#include <avtCallback.h>
#include <avtConnComponentsExpression.h>
#include <avtParallel.h>
#include <avtSourceFromAVTDataset.h>

#include <vtkCell.h>
#include <vtkCellData.h>
#include <vtkDataSet.h>
#include <vtkIntArray.h>
#include <vtkPoints.h>
#include <vtkPointData.h>
#include <vtkPointDataToCellData.h>
#include <vtkVisItUtility.h>

#include <DebugStream.h>
#include <InvalidVariableException.h>
#include <InvalidDimensionsException.h>
#include <snprintf.h>

#include <string>

// ****************************************************************************
//  Method: avtConnComponentsVariableQuery constructor
//
//  Programmer: Cyrus Harrison
//  Creation:   February 8, 2007
//
// ****************************************************************************

avtConnComponentsVariableQuery::avtConnComponentsVariableQuery()
{
    // Base class creates the connected components filter
}


// ****************************************************************************
//  Method: avtConnComponentsVariableQuery  destructor
//
//  Programmer: Cyrus Harrison
//  Creation:   February 8, 2007
//
// ****************************************************************************

avtConnComponentsVariableQuery::~avtConnComponentsVariableQuery()
{
    ;
}


// ****************************************************************************
//  Method: avtConnComponentsVariableQuery::PreExecute
//
//
//  Purpose:
//      This is called before all of the domains are executed to obtain the
//      number of components and initialize component sums.
//
//  Programmer: Cyrus Harrison
//  Creation:   February 7, 2007
//
// ****************************************************************************

void
avtConnComponentsVariableQuery::PreExecute(void)
{
    // let base class get the # of connected components
    avtConnComponentsQuery::PreExecute();

    // prepare component arrays 
    sumPerComp.resize(nComps);
    for(int i=0;i<nComps;i++)
    {
        sumPerComp[i] = 0;
    }
}


// ****************************************************************************
//  Method: avtConnComponentsVariableQuery::PostExecute
//
//  Purpose:
//      This is called after all of the domains are executed to collect
//      info from all processors and finalize component sums. 
//
//  Programmer: Cyrus Harrison
//  Creation:   February 8, 2007
//
//  Modifications:
//    Cyrus Harrison, Tue Sep 18 09:41:09 PDT 2007
//    Added support for user settable floating point format string
//
//    Cyrus Harrison, Tue Mar 31 08:26:51 PDT 2009
//    Only set results on the root processor.
//
//    Kathleen Biagas, Wed Feb 26 11:38:10 PST 2014
//    Add Xml results.
//
// ****************************************************************************

void
avtConnComponentsVariableQuery::PostExecute(void)
{
    // get per component variable sum (from all processors)
    double *sum_res_dbl = new double[nComps];
    SumDoubleArrayAcrossAllProcessors(&sumPerComp[0], sum_res_dbl, nComps);
    memcpy(&sumPerComp[0],sum_res_dbl,nComps * sizeof(double));

    delete [] sum_res_dbl;

    // create output message
    if(PAR_Rank() == 0)
    {
        std::string msg = "";
        char buff[2048];

        if(nComps == 1)
        {SNPRINTF(buff,2048,"Found %d connected component\n",nComps);}
        else
        {SNPRINTF(buff,2048,"Found %d connected components\n",nComps);}

        msg += buff;

        std::string format  =  "Component %d Sum = ("
                                  + queryAtts.GetFloatFormat() +")\n";

        for(int i=0;i<nComps;i++)
        {
            SNPRINTF(buff,1024,
                     format.c_str(),
                     i,
                    sumPerComp[i]);

            msg += buff;
        }

        // set output message
        SetResultMessage(msg);
        // set output values
        SetResultValues(sumPerComp);
        // set xml result
        MapNode result_node;
        result_node["connected_component_count"] = nComps;
        result_node["sums"] = sumPerComp;
        SetXmlResult(result_node.ToXML());
    }
}


// ****************************************************************************
//  Method: avtConnComponentsVariableQuery::Execute
//
//  Purpose:
//      Processes a single input domain to update the per component sums.
//
//  Arguments:
//      ds       Input dataset
//      dom      Input domain number
//
//  Programmer: Cyrus Harrison
//  Creation:   February 8, 2007
//
// ****************************************************************************

void
avtConnComponentsVariableQuery::Execute(vtkDataSet *ds, const int dom)
{
    const char *var = variableName.c_str();    
    bool own_values_array = false;
    // get the number of cells to process
    int ncells = ds->GetNumberOfCells();

    // get the component labels array
    vtkIntArray  *labels =(vtkIntArray*)ds->GetCellData()->GetArray("avt_ccl");
    // get the variable values array
    vtkDataArray *values =ds->GetCellData()->GetArray(var);

    // make sure labels and values are valid arrays
    if (labels == NULL)
    {
        EXCEPTION1(InvalidVariableException, "avt_ccl");
    }

    if (values  == NULL)
    {
         // if we have point data convert it to cell data
        values = ds->GetPointData()->GetArray(var);
        if( values != NULL)
        {
            vtkDataSet *new_ds = (vtkDataSet*) ds->NewInstance();
            new_ds->CopyStructure(ds);
            new_ds->GetPointData()->AddArray(
                                      ds->GetPointData()->GetArray(var));
            vtkPointDataToCellData *pd2cd = vtkPointDataToCellData::New();
            pd2cd->SetInputData(new_ds);
            pd2cd->Update();
            values = pd2cd->GetOutput()->GetCellData()->GetArray(var);
            values->Register(NULL);
            own_values_array =true;
            new_ds->Delete();
            pd2cd->Delete();

        }
        else
        {EXCEPTION1(InvalidVariableException, var);}
    }


    // loop over all cells
    for (int i = 0 ; i < ncells ; i++)
    {
        // get the component label
        int      comp_id = labels->GetValue(i);

        // get cell area
        double val = (double) values->GetTuple1(i);

        // add to total component sum
        sumPerComp[comp_id] += val;
    }
    
    if(own_values_array)
        values->Delete();
}


// ****************************************************************************
//  Method: avtConnComponentsVariableQuery::VerifyInput
//
//  Purpose: Obtains the variable name 
//
//  Programmer: Cyrus Harrison
//  Creation:   February 7, 2007
//
// ****************************************************************************

void
avtConnComponentsVariableQuery::VerifyInput(void)
{
    // call base class verify
    avtConnComponentsQuery::VerifyInput();

    avtDataRequest_p dataRequest = GetInput()->GetOriginatingSource()
                                     ->GetFullDataRequest();

    // get the variable name
    variableName = dataRequest->GetVariable();
}

