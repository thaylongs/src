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

#ifndef NAMESCHEMEATTRIBUTES_H
#define NAMESCHEMEATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>

#include <map>
#include <Namescheme.h>
#include <vector>
#include <snprintf.h>

// ****************************************************************************
// Class: NameschemeAttributes
//
// Purpose:
//    Information and methods to manage nameschemes
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API NameschemeAttributes : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    NameschemeAttributes();
    NameschemeAttributes(const NameschemeAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    NameschemeAttributes(private_tmfs_t tmfs);
    NameschemeAttributes(const NameschemeAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~NameschemeAttributes();

    virtual NameschemeAttributes& operator = (const NameschemeAttributes &obj);
    virtual bool operator == (const NameschemeAttributes &obj) const;
    virtual bool operator != (const NameschemeAttributes &obj) const;
private:
    void Init();
    void Copy(const NameschemeAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectNamescheme();
    void SelectExternalArrayNames();
    void SelectExternalArrayOffsets();
    void SelectExternalArrayData();
    void SelectAllExplicitNames();
    void SelectExplicitIds();
    void SelectExplicitNames();

    // Property setting methods
    void SetNamescheme(const std::string &namescheme_);
    void SetExternalArrayNames(const stringVector &externalArrayNames_);
    void SetExternalArrayOffsets(const intVector &externalArrayOffsets_);
    void SetExternalArrayData(const intVector &externalArrayData_);
    void SetAllExplicitNames(const stringVector &allExplicitNames_);
    void SetExplicitIds(const intVector &explicitIds_);
    void SetExplicitNames(const stringVector &explicitNames_);

    // Property getting methods
    const std::string  &GetNamescheme() const;
          std::string  &GetNamescheme();
    const stringVector &GetExternalArrayNames() const;
          stringVector &GetExternalArrayNames();
    const intVector    &GetExternalArrayOffsets() const;
          intVector    &GetExternalArrayOffsets();
    const intVector    &GetExternalArrayData() const;
          intVector    &GetExternalArrayData();
    const stringVector &GetAllExplicitNames() const;
          stringVector &GetAllExplicitNames();
    const intVector    &GetExplicitIds() const;
          intVector    &GetExplicitIds();
    const stringVector &GetExplicitNames() const;
          stringVector &GetExplicitNames();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    void AddExternalArray(const char *name, const int *data, int len);
    void AddExternalArray(const std::string &name, const std::vector<int> &data);
    void SetAllNames(const char *const *const names, int count);
    void SetName(int i, const char *name);
    void SetName(int i, const std::string &n);
    const char *GetName(int n) const;
    void SetAllNames(const std::vector<std::string> &names);
    void CheckIfGetNameCalled();

    // IDs that can be used to identify fields in case statements
    enum {
        ID_namescheme = 0,
        ID_externalArrayNames,
        ID_externalArrayOffsets,
        ID_externalArrayData,
        ID_allExplicitNames,
        ID_explicitIds,
        ID_explicitNames,
        ID__LAST
    };

private:
    std::string  namescheme;
    stringVector externalArrayNames;
    intVector    externalArrayOffsets;
    intVector    externalArrayData;
    stringVector allExplicitNames;
    intVector    explicitIds;
    stringVector explicitNames;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define NAMESCHEMEATTRIBUTES_TMFS "ss*i*i*s*i*s*"

#endif
