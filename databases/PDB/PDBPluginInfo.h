// ****************************************************************************
//                               PDBPluginInfo.h
// ****************************************************************************

#ifndef PDB_PLUGIN_INFO_H
#define PDB_PLUGIN_INFO_H
#include <DatabasePluginInfo.h>
#include <database_plugin_exports.h>

class avtDatabase;

// ****************************************************************************
//  Class: PDBDatabasePluginInfo
//
//  Purpose:
//    Classes that provide all the information about the PDB plugin.
//    Portions are separated into pieces relevant to the appropriate
//    components of VisIt.
//
//  Programmer: whitlocb -- generated by xml2info
//  Creation:   Tue Apr 29 14:06:11 PST 2003
//
//  Modifications:
//
// ****************************************************************************

class PDBGeneralPluginInfo : public virtual GeneralDatabasePluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
};

class PDBCommonPluginInfo : public virtual CommonDatabasePluginInfo, public virtual PDBGeneralPluginInfo
{
  public:
    virtual DatabaseType              GetDatabaseType();
    virtual std::vector<std::string>  GetDefaultExtensions();
    virtual avtDatabase              *SetupDatabase(const char * const *list,
                                                    int nList, int nBlock);
};

class PDBMDServerPluginInfo : public virtual MDServerDatabasePluginInfo, public virtual PDBCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

class PDBEnginePluginInfo : public virtual EngineDatabasePluginInfo, public virtual PDBCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

#endif
