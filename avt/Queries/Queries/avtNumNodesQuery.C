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
//                            avtNumNodesQuery.C                             //
// ************************************************************************* //

#include <avtNumNodesQuery.h>

#include <avtDatasetExaminer.h>
#include <avtParallel.h>
#include <snprintf.h>

// ****************************************************************************
//  Method: avtNumNodesQuery constructor
//
//  Programmer: Kathleen Bonnell 
//  Creation:   February 18, 2004 
//
//  Modifications:
//
// ****************************************************************************

avtNumNodesQuery::avtNumNodesQuery() : avtDatasetQuery() 
{
}


// ****************************************************************************
//  Method: avtNumNodesQuery destructor
//
//  Programmer: Kathleen Bonnell 
//  Creation:   February 18, 2004 
//
//  Modifications:
//
// ****************************************************************************
avtNumNodesQuery::~avtNumNodesQuery() 
{
}


// ****************************************************************************
//  Method: avtNumNodesQuery::GetDefaultInputParams
//
//  Programmer: Kathleen Biagas 
//  Creation:   July 26, 2011
//
//  Modifications:
//
// ****************************************************************************

void
avtNumNodesQuery::GetDefaultInputParams(MapNode &params)
{
    params["use_actual_data"] = 0;
}


// ****************************************************************************
//  Method: avtNumNodesQuery::PerformQuery
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
//    Kathleen Bonnell, Tue Jul 29 10:01:29 PDT 2008
//    Ensure ghost nodes aren't counted in the 'real' count by calling the
//    appropriate avtDatasetExaminer method in the presence of ghost zones.
//
//    Hank Childs, Sat Nov 21 13:25:42 PST 2009
//    Add long long support.
//
//    Kathleen Biagas, Wed Feb 12 08:17:21 PST 2014
//    Add xml results.
//
//    Kathleen Biagas, Thu Sep 11 09:13:45 PDT 2014
//    Added flag to count original nodes only (may be needed for arbpoly
//    data that was split by the DB reader.
//
// ****************************************************************************

void
avtNumNodesQuery::PerformQuery(QueryAttributes *qA)
{
    queryAtts = *qA;
    Init(); 

    UpdateProgress(0, 0);

    avtDataObject_p dob = ApplyFilters(GetInput());

    SetTypedInput(dob);

    int usedDomains = 
        GetInput()->GetInfo().GetValidity().GetHasEverOwnedAnyDomain() ? 1 : 0;

    avtGhostType gzt = 
        GetInput()->GetInfo().GetAttributes().GetContainsGhostZones();

    bool countOriginalOnly = OriginalData() &&
            !GetInput()->GetInfo().GetValidity().GetZonesPreserved() &&
             GetInput()->GetInfo().GetAttributes().GetContainsOriginalNodes();

    VISIT_LONG_LONG totalNodes[2] = {0, 0};
    VISIT_LONG_LONG tn[2] = {0, 0};
    char msg[200];
    if (usedDomains)
    {
        avtDataset_p input = GetTypedInput();
        if (gzt != AVT_HAS_GHOSTS)
        {
            totalNodes[0] = avtDatasetExaminer::GetNumberOfNodes(input,
                                                 countOriginalOnly);
        }
        else 
        {
            avtDatasetExaminer::GetNumberOfNodes(input, totalNodes[0], 
                                                 totalNodes[1],
                                                 countOriginalOnly);
        }
    }

    SumLongLongArrayAcrossAllProcessors(totalNodes, tn, 2);

    MapNode result_node;
    result_node["num_nodes"] = (int)tn[0];
    if (OriginalData())
        SNPRINTF(msg, 200, "The original number of nodes is %lld.", tn[0]);
    else 
        SNPRINTF(msg, 200, "The actual number of nodes is %lld.", tn[0]);


    if (gzt != AVT_HAS_GHOSTS)
    {
        qA->SetResultsValue((double)tn[0]);
        qA->SetResultsMessage(msg);
    }
    else
    {
        char msg2[200];
        SNPRINTF(msg2, 200, "%s\nThe number of ghost nodes is %lld.", msg, tn[1]);
        double results[2] = {(double) tn[0], (double) tn[1]};
        qA->SetResultsValues(results, 2);
        qA->SetResultsMessage(msg2);
        result_node["num_ghost_nodes"] = (int)tn[1];
    }
    qA->SetXmlResult(result_node.ToXML());
    UpdateProgress(1, 0);
}

