// ****************************************************************************
//                               HexPluginInfo.h
// ****************************************************************************

#ifndef HEX_PLUGIN_INFO_H
#define HEX_PLUGIN_INFO_H
#include <DatabasePluginInfo.h>
#include <database_plugin_exports.h>

class avtDatabase;
class avtDatabaseWriter;

// ****************************************************************************
//  Class: HexDatabasePluginInfo
//
//  Purpose:
//    Classes that provide all the information about the Hex plugin.
//    Portions are separated into pieces relevant to the appropriate
//    components of VisIt.
//
//  Programmer: meredith -- generated by xml2info
//  Creation:   Tue Feb 22 14:38:59 PST 2005
//
//  Modifications:
//
// ****************************************************************************

class HexGeneralPluginInfo : public virtual GeneralDatabasePluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual bool  HasWriter() const;
};

class HexCommonPluginInfo : public virtual CommonDatabasePluginInfo, public virtual HexGeneralPluginInfo
{
  public:
    virtual DatabaseType              GetDatabaseType();
    virtual std::vector<std::string>  GetDefaultExtensions();
    virtual avtDatabase              *SetupDatabase(const char * const *list,
                                                    int nList, int nBlock);
};

class HexMDServerPluginInfo : public virtual MDServerDatabasePluginInfo, public virtual HexCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

class HexEnginePluginInfo : public virtual EngineDatabasePluginInfo, public virtual HexCommonPluginInfo
{
  public:
    virtual avtDatabaseWriter        *GetWriter(void);
};

#endif
