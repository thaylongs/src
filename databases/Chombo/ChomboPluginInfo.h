// ****************************************************************************
//                               ChomboPluginInfo.h
// ****************************************************************************

#ifndef CHOMBO_PLUGIN_INFO_H
#define CHOMBO_PLUGIN_INFO_H
#include <DatabasePluginInfo.h>
#include <database_plugin_exports.h>

class avtDatabase;
class avtDatabaseWriter;

// ****************************************************************************
//  Class: ChomboDatabasePluginInfo
//
//  Purpose:
//    Classes that provide all the information about the Chombo plugin.
//    Portions are separated into pieces relevant to the appropriate
//    components of VisIt.
//
//  Programmer: childs -- generated by xml2info
//  Creation:   Thu Jan 19 11:17:13 PDT 2006
//
//  Modifications:
//
// ****************************************************************************

class ChomboGeneralPluginInfo : public virtual GeneralDatabasePluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual bool  HasWriter() const;
};

class ChomboCommonPluginInfo : public virtual CommonDatabasePluginInfo, public virtual ChomboGeneralPluginInfo
{
  public:
    virtual DatabaseType              GetDatabaseType();
    virtual std::vector<std::string>  GetDefaultExtensions();
    virtual avtDatabase              *SetupDatabase(const char * const *list,
                                                    int nList, int nBlock);
};

class ChomboMDServerPluginInfo : public virtual MDServerDatabasePluginInfo, public virtual ChomboCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

class ChomboEnginePluginInfo : public virtual EngineDatabasePluginInfo, public virtual ChomboCommonPluginInfo
{
  public:
    virtual avtDatabaseWriter        *GetWriter(void);
};

#endif
