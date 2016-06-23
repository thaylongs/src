/*****************************************************************************
 *
 * Copyright (c) 2000 - 2016, Lawrence Livermore National Security, LLC
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
//  File: avtSPHResampleFilter.h
// ************************************************************************* //

#ifndef AVT_SPHResample_FILTER_H
#define AVT_SPHResample_FILTER_H


#include <avtPluginDataTreeIterator.h>
#include <SPHResampleAttributes.h>
#include <avtPluginDatasetToDatasetFilter.h>

class vtkRectilinearGrid;

struct tensorStruct{
    tensorStruct(){
        xx = xy = xz = yx = yy = yz = zx = zy = zz = 0.0;
    }
    double xx;
    double xy;
    double xz;
    double yx;
    double yy;
    double yz;
    double zx;
    double zy;
    double zz;
};

struct ghostCell {
    ghostCell(int dim) {
        globalLatticeIdx = -1;
        m0 = 0;
        m1.resize(dim, 0.0);
        value = 0;
        A = 0;
        B.resize(dim, 0.0);
    }
    
    int globalLatticeIdx;
    double m0;
    std::vector<double> m1;
    tensorStruct m2;
    double value;
    
    double A;
    std::vector<double> B;
};

struct sphData {
    sphData(int size, int dim) {
        totalCells = size;
        indices.resize(dim*2, 0);
        
        dset = NULL;
        
        m0.resize(size,0.0);
        m2.resize(size);
        A.resize(size, 0.0);
        
        for(int i=0; i<size; i++)
        {
            m1.push_back(std::vector<double>(dim,0.0));
            B.push_back(std::vector<double>(dim,0.0));
        }
        
        scalarValues.resize(size, 0.0);
        globalLatticeIndices.resize(size, 0);
    }
    
    int totalCells;
    std::vector<int> globalLatticeIndices;
    std::vector<int> indices;
    
    // Dataset
    vtkDataSet *dset;
    double bounds[6];
    
    // Ghost Cells
    std::vector<ghostCell> ghostCells;
    std::map<int, int> ghostZoneIdMap;
    
    // RK Moments
    std::vector<double> m0;
    std::vector<std::vector<double> > m1;
    std::vector<tensorStruct> m2;
    std::vector<double> A;
    std::vector<std::vector<double> > B;
    std::vector<double> scalarValues;
};

// ****************************************************************************
//  Class: avtSPHResampleFilter
//
//  Purpose:
//      A plugin operator for SPHResample.
//
//  Programmer: harrison37 -- generated by xml2avt
//  Creation:   Fri Dec 5 13:50:31 PST 2014
//
// ****************************************************************************

class avtSPHResampleFilter : public avtPluginDatasetToDatasetFilter
{
public:
    avtSPHResampleFilter();
    virtual             ~avtSPHResampleFilter();
    
    static avtFilter    *Create();
    
    virtual const char  *GetType(void)  { return "avtSPHResampleFilter"; };
    virtual const char  *GetDescription(void)
    { return "SPH Resample"; };
    
    virtual void         SetAtts(const AttributeGroup*);
    virtual bool         Equivalent(const AttributeGroup*);
    
    virtual avtContract_p   ModifyContract(avtContract_p);
    virtual void            UpdateDataObjectInfo(void);
protected:
    SPHResampleAttributes   atts;
    std::string             resampleVarName;
    std::string             supportVarName;
    std::string             weightVarName;
    
    bool                    keepNodeZone;
    int                     nDim;
    
    virtual void Execute();
    
    vtkRectilinearGrid                  *CreateOutputGrid(const double *const, const std::vector<double>  &);
    template <int Dim> tensorStruct     *CreateTensorStruct(vtkDataArray* const, const int);
    
    
    template <int Dim> void Sample(std::vector<sphData>&);
    template <int Dim> void SampleNMS(std::vector<double>&);
    
    // Return the kernel weight for a given normalized distance or position.
    template <int Dim> double kernelValue(double etaMagnitude, double Hdet);
    
    // Return the gradient value for a given normalized distance or position.
    template <int Dim> double kernelGradValue(double etaMagnitude, double Hdet);
    
private:
    void    ExecuteNMS();
    void    CheckInputVariables(const vtkDataArray* const, const vtkDataArray* const, const vtkDataArray* const);
    int     GetGhostCellIndex(const std::vector<ghostCell> &, int);
    std::vector<double> GetStepSizeXYZ(void);
    int     GetLocalIndex(const sphData &, int);
    void    SynchMoments(sphData &);
    void    SynchScalars(sphData &);
    std::vector<int> GetParticipatingIndices(vtkDataSet **, const int);
    void    GetDimensions(std::vector<int> &, std::vector<double> &, std::vector<double> &, const std::vector<double> &, const double *const);
};

#endif
