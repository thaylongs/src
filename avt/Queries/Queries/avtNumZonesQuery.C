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
//                            avtNumZonesQuery.C                             //
// ************************************************************************* //

#include <avtNumZonesQuery.h>

#include <avtDatasetExaminer.h>
#include <snprintf.h>
#include <avtParallel.h>


// ****************************************************************************
//  Method: avtNumZonesQuery constructor
//
//  Programmer: Kathleen Bonnell 
//  Creation:   February 18, 2004 
//
//  Modifications:
//
// ****************************************************************************

avtNumZonesQuery::avtNumZonesQuery() : avtDatasetQuery() 
{
}


// ****************************************************************************
//  Method: avtNumZonesQuery destructor
//
//  Programmer: Kathleen Bonnell 
//  Creation:   February 18, 2004 
//
//  Modifications:
//
// ****************************************************************************
avtNumZonesQuery::~avtNumZonesQuery() 
{
}


// ****************************************************************************
//  Method: avtNumZonesQuery::GetDefaultInputParams
//
//  Programmer: Kathleen Biagas 
//  Creation:   July 26, 2011
//
//  Modifications:
//
// ****************************************************************************

void
avtNumZonesQuery::GetDefaultInputParams(MapNode &params)
{
    params["use_actual_data"] = 0;
}


// ****************************************************************************
//  Method: avtNumZonesQuery::PerformQuery
//
//  Purpose:
//    Perform the requested query. 
//
//  Programmer: Kathleen Bonnell 
//  Creation:   February 18, 2004 
//
//  Modifications:
//    Brad Whitlock, Mon Feb 23 12:11:02 PDT 2004
//    I made it use SNPRINTF to get it to build on Linux.
//    
//    Kathleen Bonnell, Fri Mar  5 15:36:23 PST 2004 
//    Rewrote code to work correctly in parallel when some processors have
//    not done any work and thus have a different value for ghost type. 
//    
//    Kathleen Bonnell, Tue Apr 20 12:49:46 PDT 2004 
//    Modified msg creation so that it works properly on all platforms. 
//
//    Mark C. Miller, Wed Jun  9 21:50:12 PDT 2004
//    Eliminated use of MPI_ANY_TAG and modified to use GetUniqueMessageTags
//
//    Kathleen Bonnell, Tue Jul  6 14:32:06 PDT 2004 
//    Removed MPI calls, use SumIntArrayAcrossAllProcessors from avtParallel. 
//
//    Hank Childs, Sat Nov 21 13:10:43 PST 2009
//    Change counter to long long.
//
//    Kathleen Biagas, Wed Feb 12 09:07:34 PST 2014
//    Add xml results.
//
//    Kathleen Biagas, Thu Sep 11 09:13:45 PDT 2014
//    Added flag to count original zones only (may be needed for arbpoly
//    data that was split by the DB reader.
//
// ****************************************************************************

void
avtNumZonesQuery::PerformQuery(QueryAttributes *qA)
{
    queryAtts = *qA;
    Init(); 

    UpdateProgress(0, 0);

    avtDataObject_p dob = ApplyFilters(GetInput());
    SetTypedInput(dob);

    int usedDomains = 
        GetInput()->GetInfo().GetValidity().GetHasEverOwnedAnyDomain() ? 1 : 0;

    bool countOriginalOnly = OriginalData() &&
            !GetInput()->GetInfo().GetValidity().GetZonesPreserved() &&
             GetInput()->GetInfo().GetAttributes().GetContainsOriginalCells();

    avtGhostType gt = GetInput()->GetInfo().GetAttributes().GetContainsGhostZones();
    VISIT_LONG_LONG totalZones [2] = {0, 0};
    char msg[200];
    if (usedDomains)
    {
        avtDataset_p input = GetTypedInput();

        if (gt != AVT_HAS_GHOSTS)
        {
            totalZones[0] = avtDatasetExaminer::GetNumberOfZones(input, countOriginalOnly);
        }
        else 
        {
            avtDatasetExaminer::GetNumberOfZones(input, totalZones[0], totalZones[1],
                                                 countOriginalOnly);
        }
    }

    VISIT_LONG_LONG tz[2] = {0, 0};
    SumLongLongArrayAcrossAllProcessors(totalZones, tz, 2);

    MapNode result_node;
    result_node["num_zones"] = (int)tz[0];
 
    if (OriginalData())
        SNPRINTF(msg, 200, "The original number of zones is %lld.", tz[0]);
    else 
        SNPRINTF(msg, 200, "The actual number of zones is %lld.", tz[0]);
    
    if (gt != AVT_HAS_GHOSTS)
    {
        qA->SetResultsValue((double)tz[0]);
        qA->SetResultsMessage(msg);
    }
    else
    {
        char msg2[200];
        SNPRINTF(msg2, 200, "%s\nThe number of ghost zones is %lld.", msg, tz[1]);
        double results[2] = {(double) tz[0], (double) tz[1]};
        qA->SetResultsValues(results, 2);
        qA->SetResultsMessage(msg2);
        result_node["num_ghost_zones"] = (int)tz[1];
    }
    qA->SetXmlResult(result_node.ToXML());

    UpdateProgress(1, 0);
}

