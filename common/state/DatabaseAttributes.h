#ifndef DATABASEATTRIBUTES_H
#define DATABASEATTRIBUTES_H
#include <state_exports.h>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: DatabaseAttributes
//
// Purpose:
//    This class contains the database attributes.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Wed Jul 23 11:29:57 PDT 2003
//
// Modifications:
//   
// ****************************************************************************

class STATE_API DatabaseAttributes : public AttributeSubject
{
public:
    DatabaseAttributes();
    DatabaseAttributes(const DatabaseAttributes &obj);
    virtual ~DatabaseAttributes();

    virtual void operator = (const DatabaseAttributes &obj);
    virtual bool operator == (const DatabaseAttributes &obj) const;
    virtual bool operator != (const DatabaseAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetState(int state_);

    // Property getting methods
    int GetState() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    int state;
};

#endif
