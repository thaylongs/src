#ifndef GLOBALLINEOUTATTRIBUTES_H
#define GLOBALLINEOUTATTRIBUTES_H
#include <state_exports.h>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: GlobalLineoutAttributes
//
// Purpose:
//    This file contains global attributes controlling Lineouts.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Tue May 20 13:39:52 PST 2003
//
// Modifications:
//   
// ****************************************************************************

class STATE_API GlobalLineoutAttributes : public AttributeSubject
{
public:
    GlobalLineoutAttributes();
    GlobalLineoutAttributes(const GlobalLineoutAttributes &obj);
    virtual ~GlobalLineoutAttributes();

    virtual void operator = (const GlobalLineoutAttributes &obj);
    virtual bool operator == (const GlobalLineoutAttributes &obj) const;
    virtual bool operator != (const GlobalLineoutAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetDynamic(bool Dynamic_);

    // Property getting methods
    bool GetDynamic() const;


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    bool Dynamic;
};

#endif
