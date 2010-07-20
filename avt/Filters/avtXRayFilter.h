/*****************************************************************************
*
* Copyright (c) 2000 - 2010, Lawrence Livermore National Security, LLC
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
//                               avtXRayFilter.h                             //
// ************************************************************************* //

#ifndef AVT_XRAY_FILTER_H
#define AVT_XRAY_FILTER_H


#include <avtDatasetToDatasetFilter.h>
#include <avtVector.h>
#include <filters_exports.h>
#include <string>


// ****************************************************************************
//  Class: avtXRayFilter
//
//  Purpose:
//      This should really be a query, not a filter.  It creates an x ray
//      image using an absorbtivity and emissivity.
//
//  Programmer: Eric Brugger
//  Creation:   June 30, 2010
//
//  Modifications:
//    Eric Brugger, Fri Jul 16 12:22:55 PDT 2010
//    I modified the filter to handle the case where some of the processors
//    didn't have any data sets when executing in parallel.
//
// ****************************************************************************

class AVTFILTERS_API avtXRayFilter : public avtDatasetToDatasetFilter
{
  public:
                                    avtXRayFilter();
    virtual                        ~avtXRayFilter();

    virtual const char             *GetType(void)
                                       { return "avtXRayFilter"; };
    virtual const char             *GetDescription(void)
                                       { return "Performing x ray filter"; };
    virtual void                    UpdateDataObjectInfo(void);

    void                            SetVariableNames(std::string abs,
                                                     std::string emis)
                                       { absVarName = abs;
                                         emisVarName = emis; };

    void                            SetNumberOfLines(int);

    virtual void                    SetInitialLine(int iLine)
                                       { initialLine = iLine; };

    virtual void                    SetImageProperties(float *pos_,
                                                       float  theta_,
                                                       float  phi_,
                                                       float  dx_,
                                                       float  dy_,
                                                       int    nx_,
                                                       int    ny_);

  protected:
    std::string                     absVarName;
    std::string                     emisVarName;

    int                             nLines;
    int                             initialLine;
    double                         *lines;

    int                             currentNode;
    int                             totalNodes;

    avtVector                       pos;
    float                           theta, phi;
    float                           dx, dy;
    int                             nx, ny;

    virtual void                    Execute(void);

    virtual void                    PreExecute(void);
    virtual void                    PostExecute(void);

    virtual void                    CartesianExecute(vtkDataSet *, int &,
                                        vector<double>&, vector<int>&,
                                        float **&);
    virtual void                    CylindricalExecute(vtkDataSet *, int &,
                                        vector<double>&, vector<int>&,
                                        float **&);

    void                            RedistributeLines(int, int *,
                                        vector<double> *, vector<int> *,
                                        int, string *, int,  float ***);

};


#endif


