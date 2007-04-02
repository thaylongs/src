/*****************************************************************************
*
* Copyright (c) 2000 - 2006, The Regents of the University of California
* Produced at the Lawrence Livermore National Laboratory
* All rights reserved.
*
* This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
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
*    documentation and/or materials provided with the distribution.
*  - Neither the name of the UC/LLNL nor  the names of its contributors may be
*    used to  endorse or  promote products derived from  this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
* CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
* ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//  File: avtThresholdFilter.h
// ************************************************************************* //

#ifndef AVT_Threshold_FILTER_H
#define AVT_Threshold_FILTER_H

#include <avtPluginStructuredChunkStreamer.h>
#include <ThresholdAttributes.h>

#include <avtGhostData.h>

class     vtkDataSet;


// ****************************************************************************
//  Class: avtThresholdFilter
//
//  Purpose:
//      A plugin operator for Threshold.
//
//  Programmer: childs -- generated by xml2info
//  Creation:   Tue Oct 23 16:38:18 PST 2001
//
//  Modifications:
//
//    Hank Childs, Sat Mar 19 10:18:52 PST 2005
//    Add support for structured chunking.
//
//    Hank Childs, Sun Mar 27 11:34:04 PST 2005
//    Inherit from new base type that supports structured chunking.
//
//    Hank Childs, Tue Sep 13 09:07:05 PDT 2005
//    Add support for PointsOnly mode.
//
// ****************************************************************************

class avtThresholdFilter : public avtPluginStructuredChunkStreamer
{
  public:
                         avtThresholdFilter();
    virtual             ~avtThresholdFilter() {;};

    static avtFilter    *Create();

    virtual const char  *GetType(void)  { return "avtThresholdFilter"; };
    virtual const char  *GetDescription(void)
                             { return "Thresholding"; };

    virtual void         SetAtts(const AttributeGroup*);
    virtual bool         Equivalent(const AttributeGroup*);

  protected:
    ThresholdAttributes   atts;

    virtual avtPipelineSpecification_p
                          PerformRestriction(avtPipelineSpecification_p);

    virtual vtkDataSet   *ProcessOneChunk(vtkDataSet *, int, std::string,bool);
    virtual void          GetAssignments(vtkDataSet *, const int *,
                      std::vector<avtStructuredMeshChunker::ZoneDesignation>&);

    virtual void          RefashionDataObjectInfo(void);
    virtual void          PreExecute(void);

    vtkDataArray         *GetThresholdVariable(vtkDataSet *, bool &);
    vtkDataSet           *ThresholdToPointMesh(vtkDataSet *);
};


#endif
