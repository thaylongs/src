#ifndef SLICEATTRIBUTES_H
#define SLICEATTRIBUTES_H
#include <string>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: SliceAttributes
//
// Purpose:
//    This class contains attributes for the arbitrary slice.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Tue Jan 25 16:57:05 PST 2005
//
// Modifications:
//   
// ****************************************************************************

class SliceAttributes : public AttributeSubject
{
public:
    enum AxisType
    {
        XAxis,
        YAxis,
        ZAxis,
        Arbitrary
    };
    enum OriginType
    {
        Point,
        Intercept,
        Percent,
        Zone,
        Node
    };

    SliceAttributes();
    SliceAttributes(const SliceAttributes &obj);
    virtual ~SliceAttributes();

    virtual SliceAttributes& operator = (const SliceAttributes &obj);
    virtual bool operator == (const SliceAttributes &obj) const;
    virtual bool operator != (const SliceAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectOriginPoint();
    void SelectNormal();
    void SelectUpAxis();
    void SelectMeshName();

    // Property setting methods
    void SetOriginType(OriginType originType_);
    void SetOriginPoint(const double *originPoint_);
    void SetOriginIntercept(double originIntercept_);
    void SetOriginPercent(double originPercent_);
    void SetOriginZone(int originZone_);
    void SetOriginNode(int originNode_);
    void SetNormal(const double *normal_);
    void SetAxisType(AxisType axisType_);
    void SetUpAxis(const double *upAxis_);
    void SetProject2d(bool project2d_);
    void SetInteractive(bool interactive_);
    void SetFlip(bool flip_);
    void SetOriginZoneDomain(int originZoneDomain_);
    void SetOriginNodeDomain(int originNodeDomain_);
    void SetMeshName(const std::string &meshName_);

    // Property getting methods
    OriginType        GetOriginType() const;
    const double      *GetOriginPoint() const;
          double      *GetOriginPoint();
    double            GetOriginIntercept() const;
    double            GetOriginPercent() const;
    int               GetOriginZone() const;
    int               GetOriginNode() const;
    const double      *GetNormal() const;
          double      *GetNormal();
    AxisType          GetAxisType() const;
    const double      *GetUpAxis() const;
          double      *GetUpAxis();
    bool              GetProject2d() const;
    bool              GetInteractive() const;
    bool              GetFlip() const;
    int               GetOriginZoneDomain() const;
    int               GetOriginNodeDomain() const;
    const std::string &GetMeshName() const;
          std::string &GetMeshName();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string AxisType_ToString(AxisType);
    static bool AxisType_FromString(const std::string &, AxisType &);
protected:
    static std::string AxisType_ToString(int);
public:
    static std::string OriginType_ToString(OriginType);
    static bool OriginType_FromString(const std::string &, OriginType &);
protected:
    static std::string OriginType_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    void UpdateOrthogonalAxes();
private:
    int         originType;
    double      originPoint[3];
    double      originIntercept;
    double      originPercent;
    int         originZone;
    int         originNode;
    double      normal[3];
    int         axisType;
    double      upAxis[3];
    bool        project2d;
    bool        interactive;
    bool        flip;
    int         originZoneDomain;
    int         originNodeDomain;
    std::string meshName;
};

#endif
