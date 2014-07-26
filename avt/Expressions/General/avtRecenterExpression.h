/*****************************************************************************
*
* Copyright (c) 2000 - 2014, Lawrence Livermore National Security, LLC
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
//                        avtRecenterExpression.h                            //
// ************************************************************************* //

#ifndef AVT_RECENTER_FILTER_H
#define AVT_RECENTER_FILTER_H

#include <avtSingleInputExpressionFilter.h>


// ****************************************************************************
//  Class: avtRecenterExpression
//
//  Purpose:
//      Recenters a variable.
//          
//  Programmer: Hank Childs
//  Creation:   December 10, 2003
//
//  Modifications:
//
//    Hank Childs, Thu Feb  5 17:11:06 PST 2004
//    Moved inlined constructor and destructor definitions to .C files
//    because certain compilers have problems with them.
//
//    Hank Childs, Thu Oct  6 15:41:21 PDT 2005
//    Added support for recentering vectors ['6637].
//    
//    Sean Ahern, Wed Sep 10 12:01:43 EDT 2008
//    Added optional argument to specify explicit centering.
//
//    Jeremy Meredith, Tue Apr 28 13:52:59 EDT 2009
//    Add singleton support, now that the base avtExpressionFilter class'
//    Recenter method also supports singletons.
//
// ****************************************************************************

class EXPRESSION_API avtRecenterExpression : public avtSingleInputExpressionFilter
{
  public:
                              avtRecenterExpression();
    virtual                  ~avtRecenterExpression();

    virtual const char       *GetType(void) { return "avtRecenterExpression"; };
    virtual const char       *GetDescription(void) {return "Recentering";};
    virtual void              ProcessArguments(ArgsExpr*, ExprPipelineState *);

    typedef enum {
        Toggle,
        Nodal,
        Zonal
    } RecenterType;

  protected:
    virtual vtkDataArray     *DeriveVariable(vtkDataSet *, int currentDomainsIndex);
    virtual bool              IsPointVariable(void);
    virtual int               GetVariableDimension(void);
    virtual bool              CanHandleSingletonConstants(void) {return true;}

    RecenterType              recenterMode;
};


#endif


