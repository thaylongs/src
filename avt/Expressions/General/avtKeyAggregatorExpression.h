/*****************************************************************************
*
* Copyright (c) 2000 - 2012, Lawrence Livermore National Security, LLC
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
//                         avtKeyAggregatorExpression.h                      //
// ************************************************************************* //

#ifndef AVT_KEY_AGGREGATOR_EXPRESSION_H
#define AVT_KEY_AGGREGATOR_EXPRESSION_H

#include <avtExpressionFilter.h>

#include <string>
#include <vector>

class vtkDataArray;
class vtkFloatArray;

// ****************************************************************************
//  Class: avtKeyAggregatorExpression
//
//  Purpose:
//      This expression allows an user to aggregate values by a set of 
//      contigious interger keys. The keys and values are cell fields passed 
//      to the expression. 
//
//
//  Programmer: Cyrus Harrison
//  Creation:   March 26, 2009
//
//  Modifications:
//   Cyrus Harrison, Thu Oct 29 10:26:42 PDT 2009
//   Switch to generic use of vtkDataArray to support non integer key types.
//
// ****************************************************************************

class EXPRESSION_API avtKeyAggregatorExpression : public avtExpressionFilter
{
  public:
                              avtKeyAggregatorExpression();
    virtual                  ~avtKeyAggregatorExpression();

    virtual void              AddInputVariableName(const char *var);

    virtual const char       *GetType(void)
                                     { return "avtKeyAggregatorExpression"; };
    virtual const char       *GetDescription(void)
                                      {return "Aggregating values per key.";};


    virtual int               NumVariableArguments() { return 2; };
    virtual int               GetVariableDimension();

    virtual bool              IsPointVariable(void) { return false; }

  protected:
    virtual void              Execute(void);

  private:
    int                       FindMaxKey(std::vector<vtkDataArray*> &key_arrays);

    void                      Aggregate(std::vector<vtkDataArray*>   &key_arrays,
                                        std::vector<vtkDataArray*> &val_arrays,
                                        int num_keys, int num_val_comps,
                                        std::vector<float> &key_results);

    vtkFloatArray            *CreateResultArray(vtkDataArray *keys,
                                                std::vector<float> &key_results,
                                                int num_val_comps);

    std::vector<std::string>  inputVarNames;
};


#endif


