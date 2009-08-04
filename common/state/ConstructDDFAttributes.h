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

#ifndef CONSTRUCTDDFATTRIBUTES_H
#define CONSTRUCTDDFATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: ConstructDDFAttributes
//
// Purpose:
//    Attributes for constructing DDFs
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API ConstructDDFAttributes : public AttributeSubject
{
public:
    enum BinningScheme
    {
        Uniform,
        Unknown
    };
    enum StatisticalOperator
    {
        Average,
        Minimum,
        Maximum,
        StandardDeviation,
        Variance,
        Percentile,
        Median,
        InterquartileRange,
        Sum,
        Count
    };

    ConstructDDFAttributes();
    ConstructDDFAttributes(const ConstructDDFAttributes &obj);
    virtual ~ConstructDDFAttributes();

    virtual ConstructDDFAttributes& operator = (const ConstructDDFAttributes &obj);
    virtual bool operator == (const ConstructDDFAttributes &obj) const;
    virtual bool operator != (const ConstructDDFAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectDdfName();
    void SelectVarnames();
    void SelectRanges();
    void SelectCodomainName();
    void SelectNumSamples();

    // Property setting methods
    void SetDdfName(const std::string &ddfName_);
    void SetVarnames(const stringVector &varnames_);
    void SetRanges(const doubleVector &ranges_);
    void SetCodomainName(const std::string &codomainName_);
    void SetStatisticalOperator(StatisticalOperator statisticalOperator_);
    void SetPercentile(double percentile_);
    void SetUndefinedValue(double undefinedValue_);
    void SetBinningScheme(BinningScheme binningScheme_);
    void SetNumSamples(const intVector &numSamples_);
    void SetOverTime(bool overTime_);
    void SetTimeStart(int timeStart_);
    void SetTimeEnd(int timeEnd_);
    void SetTimeStride(int timeStride_);

    // Property getting methods
    const std::string  &GetDdfName() const;
          std::string  &GetDdfName();
    const stringVector &GetVarnames() const;
          stringVector &GetVarnames();
    const doubleVector &GetRanges() const;
          doubleVector &GetRanges();
    const std::string  &GetCodomainName() const;
          std::string  &GetCodomainName();
    StatisticalOperator GetStatisticalOperator() const;
    double             GetPercentile() const;
    double             GetUndefinedValue() const;
    BinningScheme      GetBinningScheme() const;
    const intVector    &GetNumSamples() const;
          intVector    &GetNumSamples();
    bool               GetOverTime() const;
    int                GetTimeStart() const;
    int                GetTimeEnd() const;
    int                GetTimeStride() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string BinningScheme_ToString(BinningScheme);
    static bool BinningScheme_FromString(const std::string &, BinningScheme &);
protected:
    static std::string BinningScheme_ToString(int);
public:
    static std::string StatisticalOperator_ToString(StatisticalOperator);
    static bool StatisticalOperator_FromString(const std::string &, StatisticalOperator &);
protected:
    static std::string StatisticalOperator_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_ddfName = 0,
        ID_varnames,
        ID_ranges,
        ID_codomainName,
        ID_statisticalOperator,
        ID_percentile,
        ID_undefinedValue,
        ID_binningScheme,
        ID_numSamples,
        ID_overTime,
        ID_timeStart,
        ID_timeEnd,
        ID_timeStride
    };

private:
    std::string  ddfName;
    stringVector varnames;
    doubleVector ranges;
    std::string  codomainName;
    int          statisticalOperator;
    double       percentile;
    double       undefinedValue;
    int          binningScheme;
    intVector    numSamples;
    bool         overTime;
    int          timeStart;
    int          timeEnd;
    int          timeStride;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
};

#endif
