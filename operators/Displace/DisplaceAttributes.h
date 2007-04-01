#ifndef DISPLACEATTRIBUTES_H
#define DISPLACEATTRIBUTES_H
#include <string>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: DisplaceAttributes
//
// Purpose:
//    This class contains attributes for the displace operator.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Thu Dec 9 15:01:07 PST 2004
//
// Modifications:
//   
// ****************************************************************************

class DisplaceAttributes : public AttributeSubject
{
public:
    DisplaceAttributes();
    DisplaceAttributes(const DisplaceAttributes &obj);
    virtual ~DisplaceAttributes();

    virtual DisplaceAttributes& operator = (const DisplaceAttributes &obj);
    virtual bool operator == (const DisplaceAttributes &obj) const;
    virtual bool operator != (const DisplaceAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectVariable();

    // Property setting methods
    void SetFactor(double factor_);
    void SetVariable(const std::string &variable_);

    // Property getting methods
    double            GetFactor() const;
    const std::string &GetVariable() const;
          std::string &GetVariable();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    double      factor;
    std::string variable;
};

#endif
