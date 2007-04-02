#ifndef WINDOWATTRIBUTES_H
#define WINDOWATTRIBUTES_H
#include <state_exports.h>
#include <AttributeSubject.h>
#include <ViewCurveAttributes.h>
#include <View2DAttributes.h>
#include <View3DAttributes.h>
#include <LightList.h>
#include <RenderingAttributes.h>
#include <ColorTableAttributes.h>

// ****************************************************************************
// Class: WindowAttributes
//
// Purpose:
//    This class contains the attributes for a visualization window.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Fri Mar 17 14:55:40 PST 2006
//
// Modifications:
//   
// ****************************************************************************

class STATE_API WindowAttributes : public AttributeSubject
{
public:
    WindowAttributes();
    WindowAttributes(const WindowAttributes &obj);
    virtual ~WindowAttributes();

    virtual WindowAttributes& operator = (const WindowAttributes &obj);
    virtual bool operator == (const WindowAttributes &obj) const;
    virtual bool operator != (const WindowAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectViewCurve();
    void SelectView2D();
    void SelectView3D();
    void SelectLights();
    void SelectRenderAtts();
    void SelectColorTables();
    void SelectSize();
    void SelectBackground();
    void SelectForeground();
    void SelectGradBG1();
    void SelectGradBG2();

    // Property setting methods
    void SetViewCurve(const ViewCurveAttributes &viewCurve_);
    void SetView2D(const View2DAttributes &view2D_);
    void SetView3D(const View3DAttributes &view3D_);
    void SetLights(const LightList &lights_);
    void SetRenderAtts(const RenderingAttributes &renderAtts_);
    void SetColorTables(const ColorTableAttributes &colorTables_);
    void SetSize(const int *size_);
    void SetBackground(const unsigned char *background_);
    void SetForeground(const unsigned char *foreground_);
    void SetBackgroundMode(int backgroundMode_);
    void SetGradBG1(const double *gradBG1_);
    void SetGradBG2(const double *gradBG2_);

    // Property getting methods
    const ViewCurveAttributes  &GetViewCurve() const;
          ViewCurveAttributes  &GetViewCurve();
    const View2DAttributes     &GetView2D() const;
          View2DAttributes     &GetView2D();
    const View3DAttributes     &GetView3D() const;
          View3DAttributes     &GetView3D();
    const LightList            &GetLights() const;
          LightList            &GetLights();
    const RenderingAttributes  &GetRenderAtts() const;
          RenderingAttributes  &GetRenderAtts();
    const ColorTableAttributes &GetColorTables() const;
          ColorTableAttributes &GetColorTables();
    const int                  *GetSize() const;
          int                  *GetSize();
    const unsigned char        *GetBackground() const;
          unsigned char        *GetBackground();
    const unsigned char        *GetForeground() const;
          unsigned char        *GetForeground();
    int                        GetBackgroundMode() const;
    const double               *GetGradBG1() const;
          double               *GetGradBG1();
    const double               *GetGradBG2() const;
          double               *GetGradBG2();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    ViewCurveAttributes  viewCurve;
    View2DAttributes     view2D;
    View3DAttributes     view3D;
    LightList            lights;
    RenderingAttributes  renderAtts;
    ColorTableAttributes colorTables;
    int                  size[2];
    unsigned char        background[3];
    unsigned char        foreground[3];
    int                  backgroundMode;
    double               gradBG1[3];
    double               gradBG2[3];
};

#endif
