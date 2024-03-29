/*****************************************************************************
*
* Copyright (c) 2000 - 2017, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//  File: CracksClipperPluginInfo.h
// ************************************************************************* //

#ifndef CRACKSCLIPPER_PLUGIN_INFO_H
#define CRACKSCLIPPER_PLUGIN_INFO_H
#include <OperatorPluginInfo.h>
#include <operator_plugin_exports.h>

class CracksClipperAttributes;

// ****************************************************************************
//  Class: CracksClipperPluginInfo
//
//  Purpose:
//    Five classes that provide all the information about an CracksClipper operator
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
//  Modifications:
//
// ****************************************************************************

class CracksClipperGeneralPluginInfo : public virtual GeneralOperatorPluginInfo
{
  public:
    virtual const char *GetName() const;
    virtual const char *GetVersion() const;
    virtual const char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual const char *GetCategoryName() const;
};

class CracksClipperCommonPluginInfo : public virtual CommonOperatorPluginInfo, public virtual CracksClipperGeneralPluginInfo
{
  public:
    virtual AttributeSubject *AllocAttributes();
    virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
    virtual ExpressionList *GetCreatedExpressions(const avtDatabaseMetaData *);
};

class CracksClipperGUIPluginInfo : public virtual GUIOperatorPluginInfo, public virtual CracksClipperCommonPluginInfo
{
  public:
    virtual QString *GetMenuName() const;
    virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
        AttributeSubject *attr, const QString &caption, const QString &shortName,
        QvisNotepadArea *notepad);
};

class CracksClipperViewerEnginePluginInfo : public virtual ViewerEngineOperatorPluginInfo, public virtual CracksClipperCommonPluginInfo
{
  public:
    virtual AttributeSubject *GetClientAtts();
    virtual AttributeSubject *GetDefaultAtts();
    virtual void SetClientAtts(AttributeSubject *atts);
    virtual void GetClientAtts(AttributeSubject *atts);

    virtual void InitializeOperatorAtts(AttributeSubject *atts,
                                        const avtPlotMetaData &plot,
                                        const bool fromDefault);
    virtual void UpdateOperatorAtts(AttributeSubject *atts,
                                    const avtPlotMetaData &plot);
    virtual const char *GetMenuName() const;

    static void InitializeGlobalObjects();
  private:
    static CracksClipperAttributes *defaultAtts;
    static CracksClipperAttributes *clientAtts;
};

class CracksClipperViewerPluginInfo : public virtual ViewerOperatorPluginInfo, public virtual CracksClipperViewerEnginePluginInfo
{
  public:
};

class CracksClipperEnginePluginInfo : public virtual EngineOperatorPluginInfo, public virtual CracksClipperViewerEnginePluginInfo
{
  public:
    virtual avtPluginFilter *AllocAvtPluginFilter();
};

class CracksClipperScriptingPluginInfo : public virtual ScriptingOperatorPluginInfo, public virtual CracksClipperCommonPluginInfo
{
  public:
    virtual void InitializePlugin(AttributeSubject *subj, void *data);
    virtual void *GetMethodTable(int *nMethods);
    virtual bool TypesMatch(void *pyobject);
    virtual char *GetLogString();
    virtual void SetDefaults(const AttributeSubject *atts);
};

#endif
