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
//                                avtParallel.h                              //
// ************************************************************************* //

#ifndef AVT_PARALLEL_H
#define AVT_PARALLEL_H

#include<pipeline_exports.h>

#include <vector>
#include <string>
class AttributeGroup;

PIPELINE_API void    Barrier(void);
PIPELINE_API bool    Collect(float *, int);
PIPELINE_API bool    Collect(int *, int);
PIPELINE_API void    PAR_Exit(void);
PIPELINE_API void    PAR_Init(int &argc, char **&argv);
PIPELINE_API int     PAR_Rank(void);
PIPELINE_API int     PAR_Size(void);
PIPELINE_API bool    PAR_UIProcess(void);
PIPELINE_API void    SumIntAcrossAllProcessors(int&);
PIPELINE_API void    SumFloatAcrossAllProcessors(float&);
PIPELINE_API void    SumFloatArrayAcrossAllProcessors(float *, float *, int);
PIPELINE_API void    SumDoubleAcrossAllProcessors(double&);
PIPELINE_API void    SumDoubleArrayAcrossAllProcessors(double *, double *,int);
PIPELINE_API void    SumIntArrayAcrossAllProcessors(int *, int *, int);
PIPELINE_API bool    ThisProcessorHasMinimumValue(double);
PIPELINE_API bool    ThisProcessorHasMaximumValue(double);
PIPELINE_API void    UnifyMinMax(double *, int, int=0);
PIPELINE_API int     UnifyMaximumValue(int);
PIPELINE_API void    UnifyMaximumValue(std::vector<int>&, std::vector<int>&);
PIPELINE_API void    UnifyMinimumFloatArrayAcrossAllProcessors(float *, float *, int);
PIPELINE_API void    UnifyMaximumFloatArrayAcrossAllProcessors(float *, float *, int);

PIPELINE_API void    BroadcastInt(int &i);
PIPELINE_API void    BroadcastBool(bool &b);
PIPELINE_API void    BroadcastIntVector(std::vector<int>&, int myrank);
PIPELINE_API void    BroadcastDouble(double &i);
PIPELINE_API void    BroadcastDoubleVector(std::vector<double>&, int myrank);
PIPELINE_API void    BroadcastString(std::string &s, int myrank);
PIPELINE_API void    BroadcastStringVector(std::vector<std::string>&,
                                           int myrank);
PIPELINE_API void    BroadcastStringVectorVector(std::vector<std::vector<std::string> >&,
                                                 int myrank);
PIPELINE_API bool    GetListToRootProc(std::vector<std::string> &, int);

PIPELINE_API int     GetUniqueMessageTag();
PIPELINE_API int     GetUniqueStaticMessageTag();

PIPELINE_API void    GetAttToRootProc(AttributeGroup &, int);
PIPELINE_API void    GetFloatArrayToRootProc(float *, int, bool &);
PIPELINE_API void    GetDoubleArrayToRootProc(double *, int, bool &);

#endif


