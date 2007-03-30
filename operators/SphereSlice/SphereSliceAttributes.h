#ifndef SPHERESLICEATTRIBUTES_H
#define SPHERESLICEATTRIBUTES_H
#include <AttributeSubject.h>

// ****************************************************************************
// Class: SphereSliceAttributes
//
// Purpose:
//    This class contains attributes for the spherical slice.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Tue May 20 14:50:33 PST 2003
//
// Modifications:
//   
// ****************************************************************************

class SphereSliceAttributes : public AttributeSubject
{
public:
    SphereSliceAttributes();
    SphereSliceAttributes(const SphereSliceAttributes &obj);
    virtual ~SphereSliceAttributes();

    virtual void operator = (const SphereSliceAttributes &obj);
    virtual bool operator == (const SphereSliceAttributes &obj) const;
    virtual bool operator != (const SphereSliceAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectOrigin();

    // Property setting methods
    void SetOrigin(const double *origin_);
    void SetRadius(double radius_);

    // Property getting methods
    const double *GetOrigin() const;
          double *GetOrigin();
    double       GetRadius() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    double origin[3];
    double radius;
};

#endif
