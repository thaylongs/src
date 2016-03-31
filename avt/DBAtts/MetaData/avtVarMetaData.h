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

#ifndef AVTVARMETADATA_H
#define AVTVARMETADATA_H
#include <dbatts_exports.h>
#include <avtTypes.h>
#include <string>
#include <avtBaseVarMetaData.h>

#include <vector>

// ****************************************************************************
// Class: avtVarMetaData
//
// Purpose:
//    Contains metadata attributes associated with all mesh variables
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class DBATTS_API avtVarMetaData : public avtBaseVarMetaData
{
public:
    // These constructors are for objects of this class
    avtVarMetaData();
    avtVarMetaData(const avtVarMetaData &obj);
protected:
    // These constructors are for objects derived from this class
    avtVarMetaData(private_tmfs_t tmfs);
    avtVarMetaData(const avtVarMetaData &obj, private_tmfs_t tmfs);
public:
    virtual ~avtVarMetaData();

    virtual avtVarMetaData& operator = (const avtVarMetaData &obj);
    virtual bool operator == (const avtVarMetaData &obj) const;
    virtual bool operator != (const avtVarMetaData &obj) const;
private:
    void Init();
    void Copy(const avtVarMetaData &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    avtVarMetaData(private_tmfs_t, std::string, std::string, avtCentering);
    avtVarMetaData(private_tmfs_t, std::string, std::string, avtCentering, double, double);
    void SetExtents(const double *);
    void UnsetExtents();
    void Print(ostream &, int = 0) const;

    // IDs that can be used to identify fields in case statements
    enum {
        ID_centering = avtBaseVarMetaData::ID__LAST,
        ID_hasUnits,
        ID_units,
        ID_hasDataExtents,
        ID_minDataExtents,
        ID_maxDataExtents,
        ID_matRestricted,
        ID__LAST
    };

public:
    avtCentering centering;
    bool         hasUnits;
    std::string  units;
    bool         hasDataExtents;
    double       minDataExtents;
    double       maxDataExtents;
    intVector    matRestricted;

private:
    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define AVTVARMETADATA_TMFS AVTBASEVARMETADATA_TMFS "ibsbddi*"

#endif
