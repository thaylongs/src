// ****************************************************************************
//                               KullLitePluginInfo.h
// ****************************************************************************

#ifndef KULLLITE_PLUGIN_INFO_H
#define KULLLITE_PLUGIN_INFO_H
#include <DatabasePluginInfo.h>
#include <database_plugin_exports.h>

class avtDatabase;

// ****************************************************************************
//  Class: KullLiteDatabasePluginInfo
//
//  Purpose:
//    Classes that provide all the information about the KullLite plugin.
//    Portions are separated into pieces relevant to the appropriate
//    components of VisIt.
//
//  Programmer: childs -- generated by xml2info
//  Creation:   Mon Oct 14 09:53:07 PDT 2002
//
//  Modifications:
//
// ****************************************************************************

class KullLiteGeneralPluginInfo : public virtual GeneralDatabasePluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
};

class KullLiteCommonPluginInfo : public virtual CommonDatabasePluginInfo, public virtual KullLiteGeneralPluginInfo
{
  public:
    virtual DatabaseType              GetDatabaseType();
    virtual std::vector<std::string>  GetDefaultExtensions();
    virtual avtDatabase              *SetupDatabase(const char * const *list,
                                                    int nList, int nBlock);
};

class KullLiteMDServerPluginInfo : public virtual MDServerDatabasePluginInfo, public virtual KullLiteCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

class KullLiteEnginePluginInfo : public virtual EngineDatabasePluginInfo, public virtual KullLiteCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

#endif
