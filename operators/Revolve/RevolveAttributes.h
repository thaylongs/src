#ifndef REVOLVEATTRIBUTES_H
#define REVOLVEATTRIBUTES_H
#include <AttributeSubject.h>

// ****************************************************************************
// Class: RevolveAttributes
//
// Purpose:
//    This class contains attributes for the revolve operator.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Wed Jul 23 13:22:38 PST 2003
//
// Modifications:
//   
// ****************************************************************************

class RevolveAttributes : public AttributeSubject
{
public:
    RevolveAttributes();
    RevolveAttributes(const RevolveAttributes &obj);
    virtual ~RevolveAttributes();

    virtual void operator = (const RevolveAttributes &obj);
    virtual bool operator == (const RevolveAttributes &obj) const;
    virtual bool operator != (const RevolveAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectAxis();

    // Property setting methods
    void SetAxis(const double *axis_);
    void SetStartAngle(double startAngle_);
    void SetStopAngle(double stopAngle_);
    void SetSteps(int steps_);

    // Property getting methods
    const double *GetAxis() const;
          double *GetAxis();
    double       GetStartAngle() const;
    double       GetStopAngle() const;
    int          GetSteps() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    double axis[3];
    double startAngle;
    double stopAngle;
    int    steps;
};

#endif
