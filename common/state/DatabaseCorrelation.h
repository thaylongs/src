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

#ifndef DATABASECORRELATION_H
#define DATABASECORRELATION_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>
#include <visitstream.h>

// ****************************************************************************
// Class: DatabaseCorrelation
//
// Purpose:
//    This class encapsulates a database correlation, which is a mapping of one or more databases to a set of indices that go from 0 to N.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API DatabaseCorrelation : public AttributeSubject
{
public:
    enum CorrelationMethod
    {
        IndexForIndexCorrelation,
        StretchedIndexCorrelation,
        TimeCorrelation,
        CycleCorrelation,
        UserDefinedCorrelation
    };

    DatabaseCorrelation();
    DatabaseCorrelation(const DatabaseCorrelation &obj);
    virtual ~DatabaseCorrelation();

    virtual DatabaseCorrelation& operator = (const DatabaseCorrelation &obj);
    virtual bool operator == (const DatabaseCorrelation &obj) const;
    virtual bool operator != (const DatabaseCorrelation &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectName();
    void SelectDatabaseNames();
    void SelectDatabaseNStates();
    void SelectDatabaseTimes();
    void SelectDatabaseCycles();
    void SelectIndices();
    void SelectCondensedTimes();
    void SelectCondensedCycles();

    // Property setting methods
    void SetName(const std::string &name_);
    void SetNumStates(int numStates_);
    void SetMethod(CorrelationMethod method_);
    void SetDatabaseNames(const stringVector &databaseNames_);
    void SetDatabaseNStates(const intVector &databaseNStates_);
    void SetDatabaseTimes(const doubleVector &databaseTimes_);
    void SetDatabaseCycles(const intVector &databaseCycles_);
    void SetIndices(const intVector &indices_);
    void SetCondensedTimes(const doubleVector &condensedTimes_);
    void SetCondensedCycles(const intVector &condensedCycles_);

    // Property getting methods
    const std::string  &GetName() const;
          std::string  &GetName();
    int                GetNumStates() const;
    CorrelationMethod  GetMethod() const;
    const stringVector &GetDatabaseNames() const;
          stringVector &GetDatabaseNames();
    const intVector    &GetDatabaseNStates() const;
          intVector    &GetDatabaseNStates();
    const doubleVector &GetDatabaseTimes() const;
          doubleVector &GetDatabaseTimes();
    const intVector    &GetDatabaseCycles() const;
          intVector    &GetDatabaseCycles();
    const intVector    &GetIndices() const;
          intVector    &GetIndices();
    const doubleVector &GetCondensedTimes() const;
          doubleVector &GetCondensedTimes();
    const intVector    &GetCondensedCycles() const;
          intVector    &GetCondensedCycles();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string CorrelationMethod_ToString(CorrelationMethod);
    static bool CorrelationMethod_FromString(const std::string &, CorrelationMethod &);
protected:
    static std::string CorrelationMethod_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    bool GetCorrelatedTimeStates(int state, intVector &states) const;
    void AddDatabase(const std::string &database, int nStates, const doubleVector &times, const intVector &cycles);
    bool UsesDatabase(const std::string &database) const;
    int GetNumDatabases() const;
    int GetCorrelatedTimeState(const std::string &db, int state) const;
    int GetInverseCorrelatedTimeState(const std::string &db, int state) const;
    int GetCondensedCycleForState(int state) const;
    double GetCondensedTimeForState(int state) const;
    const char *GetMethodName() const;
    static const char *GetMethodNameFromMethod(int m);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_name = 0,
        ID_numStates,
        ID_method,
        ID_databaseNames,
        ID_databaseNStates,
        ID_databaseTimes,
        ID_databaseCycles,
        ID_indices,
        ID_condensedTimes,
        ID_condensedCycles
    };

private:
    std::string  name;
    int          numStates;
    int          method;
    stringVector databaseNames;
    intVector    databaseNStates;
    doubleVector databaseTimes;
    intVector    databaseCycles;
    intVector    indices;
    doubleVector condensedTimes;
    intVector    condensedCycles;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
};

// User-defined functions
STATE_API ostream& operator << (ostream &os, const DatabaseCorrelation &);
#endif
