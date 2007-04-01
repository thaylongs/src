// ****************************************************************************
//                               SimDBPluginInfo.h
// ****************************************************************************

#ifndef SIMDB_PLUGIN_INFO_H
#define SIMDB_PLUGIN_INFO_H
#include <DatabasePluginInfo.h>
#include <database_plugin_exports.h>

class avtDatabase;
class avtDatabaseWriter;

// ****************************************************************************
//  Class: SimDBDatabasePluginInfo
//
//  Purpose:
//    Classes that provide all the information about the SimDB plugin.
//    Portions are separated into pieces relevant to the appropriate
//    components of VisIt.
//
//  Programmer: meredith -- generated by xml2info
//  Creation:   Tue Feb 22 14:47:22 PST 2005
//
//  Modifications:
//
// ****************************************************************************

class SimDBGeneralPluginInfo : public virtual GeneralDatabasePluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual bool  HasWriter() const;
};

class SimDBCommonPluginInfo : public virtual CommonDatabasePluginInfo, public virtual SimDBGeneralPluginInfo
{
  public:
    virtual DatabaseType              GetDatabaseType();
    virtual std::vector<std::string>  GetDefaultExtensions();
    virtual avtDatabase              *SetupDatabase(const char * const *list,
                                                    int nList, int nBlock);
};

class SimDBMDServerPluginInfo : public virtual MDServerDatabasePluginInfo, public virtual SimDBCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

class SimDBEnginePluginInfo : public virtual EngineDatabasePluginInfo, public virtual SimDBCommonPluginInfo
{
  public:
    virtual avtDatabaseWriter        *GetWriter(void);
};

#endif
