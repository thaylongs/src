#ifndef ATTRIBUTEGROUP_H
#define ATTRIBUTEGROUP_H
#include <state_exports.h>
#include <vector>
#include <string>
#include <exception>
#include <iostream.h>
#include <Connection.h>

// Forward declaration
class AttributeGroup;
class DataNode;

// ****************************************************************************
// Class: AttributeGroup
//
// Purpose:
//   This is the base class for state objects that can be transmitted
//   across a connection.
//
// Notes:      
//
// Programmer: Brad Whitlock
// Creation:   Fri Aug 4 16:37:48 PST 2000
//
// Modifications:
//    Jeremy Meredith, Mon Feb 26 16:02:31 PST 2001
//    Added unsigned chars.
//
//    Brad Whitlock, Tue Oct 9 15:36:19 PST 2001
//    Added methods for returning the type name and copying objects.
//
//    Jeremy Meredith, Wed May  8 10:56:32 PDT 2002
//    Added methods needed for keyframing, mostly relating
//    to individual fields.
//
//    Eric Brugger, Fri Nov 15 12:48:02 PST 2002
//    Add the method Interpolate.
//
//    Brad Whitlock, Fri Dec 27 15:11:40 PST 2002
//    I added a few more methods to the typeInfo class to get rid of some
//    memory leaks in purify.
//
//    Jeremy Meredith, Thu Jan 16 12:42:22 PST 2003
//    Changed things a bit for keyframing enhancements.
//
//    Brad Whitlock, Fri Mar 21 09:44:44 PDT 2003
//    I added a virtual function that can modify the DataNode that is read
//    from the config file so that we can handle old versions. I also added
//    a static method for version comparison.
//
//    Brad Whitlock, Tue May 20 08:54:38 PDT 2003
//    I added a second argument to CreateNode.
//
// ****************************************************************************

class STATE_API AttributeGroup
{
public:
    enum FieldType {
        FieldType_unknown,
        FieldType_int,
        FieldType_intArray,
        FieldType_intVector,
        FieldType_bool,
        FieldType_float,
        FieldType_floatArray,
        FieldType_double,
        FieldType_doubleArray,
        FieldType_doubleVector,
        FieldType_uchar,
        FieldType_ucharArray,
        FieldType_ucharVector,
        FieldType_string,
        FieldType_stringVector,
        FieldType_colortable,
        FieldType_color,
        FieldType_opacity,
        FieldType_linestyle,
        FieldType_linewidth,
        FieldType_att,
        FieldType_attVector,
        FieldType_enum        
    };

public:
    AttributeGroup(const char *formatString);
    virtual ~AttributeGroup();

    void Write(Connection &conn);
    void Read(Connection &conn);
    int  CalculateMessageSize(Connection &conn);

    int  NumAttributes() const;
    int  NumAttributesSelected() const;
    bool IsSelected(int i) const;

    void SetGuido(int);
    int  GetGuido();

    // Selects all of the attributes in the AttributeGroup
    virtual void SelectAll() = 0;
    void Select(int index, void *address, int length = 0);
    void UnSelectAll();

    virtual bool CreateNode(DataNode *node, bool);
    virtual void SetFromNode(DataNode *node);
    virtual void ProcessOldVersions(DataNode *node, const char *configVersion);

    friend ostream& operator<<(ostream& os, const AttributeGroup&);

    virtual bool CopyAttributes(const AttributeGroup *atts);
    virtual void InterpolateConst(const AttributeGroup *atts1,
                                  const AttributeGroup *atts2, double f);
    virtual void InterpolateLinear(const AttributeGroup *atts1,
                                   const AttributeGroup *atts2, double f);
    virtual bool EqualTo(const AttributeGroup *atts) const;
    virtual const std::string TypeName() const;

    virtual std::string GetFieldName(int index) const;
    virtual FieldType   GetFieldType(int index) const;
    virtual std::string GetFieldTypeName(int index) const;
    virtual bool        FieldsEqual(int index, const AttributeGroup*) const;

    static bool VersionLessThan(const char *configVersion, const char *version);
protected:
    // Used to instantiate a new sub attribute.
    virtual AttributeGroup *CreateSubAttributeGroup(int attrId);

    // These are used to declare the AttributeGroup's component types.
    void DeclareChar();
    void DeclareUnsignedChar();
    void DeclareInt();
    void DeclareLong();
    void DeclareFloat();
    void DeclareDouble();
    void DeclareString();
    void DeclareAttributeGroup();
    void DeclareBool();

    void DeclareListChar();
    void DeclareListUnsignedChar();
    void DeclareListInt();
    void DeclareListLong();
    void DeclareListFloat();
    void DeclareListDouble();
    void DeclareListString();
    void DeclareListAttributeGroup();
    void DeclareListBool();

    void DeclareVectorChar();
    void DeclareVectorUnsignedChar();
    void DeclareVectorInt();
    void DeclareVectorLong();
    void DeclareVectorFloat();
    void DeclareVectorDouble();
    void DeclareVectorString();
    void DeclareVectorAttributeGroup();
private:
    class STATE_API typeInfo
    {
    public:
        typeInfo();
        typeInfo(const typeInfo &);
        typeInfo(unsigned char tcode);
        virtual ~typeInfo();
        void operator = (const typeInfo &);

        unsigned char typeCode;
        bool selected;
        void *address;
        int  length;
    };

    typedef std::vector<typeInfo> typeInfoVector;

    // Support methods
    void CreateTypeMap(const char *formatString);
    void WriteType(Connection &conn, typeInfo &info);
    void ReadType(Connection &conn, int attrId, typeInfo &info);
private:
    typeInfoVector typeMap;  // Holds typemap for the whole class
    int guido;
};

ostream& operator<<(ostream& os, const AttributeGroup&);

// Some vector typedefs.
#include <vectortypes.h>
typedef std::vector<AttributeGroup *> AttributeGroupVector;

// An exception class
class BadDeclareFormatString : public std::exception { };

#endif
