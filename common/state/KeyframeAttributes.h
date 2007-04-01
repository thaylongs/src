#ifndef KEYFRAMEATTRIBUTES_H
#define KEYFRAMEATTRIBUTES_H
#include <state_exports.h>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: KeyframeAttributes
//
// Purpose:
//    This class contains the attributes used for keyframing.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Tue Apr 6 23:39:58 PST 2004
//
// Modifications:
//   
// ****************************************************************************

class STATE_API KeyframeAttributes : public AttributeSubject
{
public:
    KeyframeAttributes();
    KeyframeAttributes(const KeyframeAttributes &obj);
    virtual ~KeyframeAttributes();

    virtual void operator = (const KeyframeAttributes &obj);
    virtual bool operator == (const KeyframeAttributes &obj) const;
    virtual bool operator != (const KeyframeAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetEnabled(bool enabled_);
    void SetNFrames(int nFrames_);
    void SetNFramesWasUserSet(bool nFramesWasUserSet_);

    // Property getting methods
    bool GetEnabled() const;
    int  GetNFrames() const;
    bool GetNFramesWasUserSet() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    bool enabled;
    int  nFrames;
    bool nFramesWasUserSet;
};

#endif
