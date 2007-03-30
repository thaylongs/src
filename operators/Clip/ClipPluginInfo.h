// ************************************************************************* //
//  File: ClipPluginInfo.h
// ************************************************************************* //

#ifndef CLIP_PLUGIN_INFO_H
#define CLIP_PLUGIN_INFO_H
#include <OperatorPluginInfo.h>
#include <operator_plugin_exports.h>

class ClipAttributes;

// ****************************************************************************
//  Class: ClipPluginInfo
//
//  Purpose:
//    Five classes that provide all the information about an Clip operator
//
//  Programmer: whitlocb -- generated by xml2info
//  Creation:   Thu Mar 13 14:08:07 PST 2003
//
//  Modifications:
//
// ****************************************************************************

class ClipGeneralPluginInfo : public virtual GeneralOperatorPluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
};

class ClipCommonPluginInfo : public virtual CommonOperatorPluginInfo, public virtual ClipGeneralPluginInfo
{
  public:
    virtual AttributeSubject *AllocAttributes();
    virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
};

class ClipGUIPluginInfo : public virtual GUIOperatorPluginInfo, public virtual ClipCommonPluginInfo
{
  public:
    virtual const char *GetMenuName() const;
    virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
        AttributeSubject *attr, QvisNotepadArea *notepad);
    virtual const char **XPMIconData() const;
};

class ClipViewerPluginInfo : public virtual ViewerOperatorPluginInfo, public virtual ClipCommonPluginInfo
{
  public:
    virtual AttributeSubject *GetClientAtts();
    virtual AttributeSubject *GetDefaultAtts();
    virtual void SetClientAtts(AttributeSubject *atts);
    virtual void GetClientAtts(AttributeSubject *atts);

    virtual void InitializeOperatorAtts(AttributeSubject *atts,
                                        const ViewerPlot *plot);
    virtual const char **XPMIconData() const;

    static void InitializeGlobalObjects();
  private:
    static ClipAttributes *defaultAtts;
    static ClipAttributes *clientAtts;
};

class ClipEnginePluginInfo : public virtual EngineOperatorPluginInfo, public virtual ClipCommonPluginInfo
{
  public:
    virtual avtPluginFilter *AllocAvtPluginFilter();
};

class ClipScriptingPluginInfo : public virtual ScriptingOperatorPluginInfo, public virtual ClipCommonPluginInfo
{
  public:
    virtual void InitializePlugin(AttributeSubject *subj, FILE *log);
    virtual void *GetMethodTable(int *nMethods);
    virtual bool TypesMatch(void *pyobject);
    virtual void SetLogging(bool val);
    virtual void SetDefaults(const AttributeSubject *atts);
};

#endif
