/*****************************************************************************
*
* Copyright (c) 2000 - 2009, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400124
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

#ifndef RESAMPLEATTRIBUTES_H
#define RESAMPLEATTRIBUTES_H
#include <string>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: ResampleAttributes
//
// Purpose:
//    Atts for Resample operator
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class ResampleAttributes : public AttributeSubject
{
public:
    enum TieResolver
    {
        random,
        largest,
        smallest
    };

    ResampleAttributes();
    ResampleAttributes(const ResampleAttributes &obj);
    virtual ~ResampleAttributes();

    virtual ResampleAttributes& operator = (const ResampleAttributes &obj);
    virtual bool operator == (const ResampleAttributes &obj) const;
    virtual bool operator != (const ResampleAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectTieResolverVariable();

    // Property setting methods
    void SetUseExtents(bool useExtents_);
    void SetStartX(double startX_);
    void SetEndX(double endX_);
    void SetSamplesX(int samplesX_);
    void SetStartY(double startY_);
    void SetEndY(double endY_);
    void SetSamplesY(int samplesY_);
    void SetIs3D(bool is3D_);
    void SetStartZ(double startZ_);
    void SetEndZ(double endZ_);
    void SetSamplesZ(int samplesZ_);
    void SetTieResolver(TieResolver tieResolver_);
    void SetTieResolverVariable(const std::string &tieResolverVariable_);
    void SetDefaultValue(double defaultValue_);
    void SetDistributedResample(bool distributedResample_);

    // Property getting methods
    bool              GetUseExtents() const;
    double            GetStartX() const;
    double            GetEndX() const;
    int               GetSamplesX() const;
    double            GetStartY() const;
    double            GetEndY() const;
    int               GetSamplesY() const;
    bool              GetIs3D() const;
    double            GetStartZ() const;
    double            GetEndZ() const;
    int               GetSamplesZ() const;
    TieResolver       GetTieResolver() const;
    const std::string &GetTieResolverVariable() const;
          std::string &GetTieResolverVariable();
    double            GetDefaultValue() const;
    bool              GetDistributedResample() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string TieResolver_ToString(TieResolver);
    static bool TieResolver_FromString(const std::string &, TieResolver &);
protected:
    static std::string TieResolver_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    virtual bool SetValue(const std::string &name, const double &value);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_useExtents = 0,
        ID_startX,
        ID_endX,
        ID_samplesX,
        ID_startY,
        ID_endY,
        ID_samplesY,
        ID_is3D,
        ID_startZ,
        ID_endZ,
        ID_samplesZ,
        ID_tieResolver,
        ID_tieResolverVariable,
        ID_defaultValue,
        ID_distributedResample
    };

private:
    bool        useExtents;
    double      startX;
    double      endX;
    int         samplesX;
    double      startY;
    double      endY;
    int         samplesY;
    bool        is3D;
    double      startZ;
    double      endZ;
    int         samplesZ;
    int         tieResolver;
    std::string tieResolverVariable;
    double      defaultValue;
    bool        distributedResample;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
};

#endif
