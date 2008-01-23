/*****************************************************************************
*
* Copyright (c) 2000 - 2008, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400142
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

#ifndef VIEWERWINDOWMANAGERATTRIBUTES_H
#define VIEWERWINDOWMANAGERATTRIBUTES_H
#include <AttributeSubject.h>
class ActionGroupDescription;
#include "ViewerRPC.h"

// ****************************************************************************
// Class: ViewerWindowManagerAttributes
//
// Purpose:
//    This class contains the attributes that dictate where viewer windows are positioned, etc.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Wed Jan 23 11:41:04 PDT 2008
//
// Modifications:
//   
// ****************************************************************************

class ViewerWindowManagerAttributes : public AttributeSubject
{
public:
    ViewerWindowManagerAttributes();
    ViewerWindowManagerAttributes(const ViewerWindowManagerAttributes &obj);
    virtual ~ViewerWindowManagerAttributes();

    virtual ViewerWindowManagerAttributes& operator = (const ViewerWindowManagerAttributes &obj);
    virtual bool operator == (const ViewerWindowManagerAttributes &obj) const;
    virtual bool operator != (const ViewerWindowManagerAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectActionConfigurations();

    // Property setting methods
    void SetToolbarsVisible(bool toolbarsVisible_);
    void SetLargeIcons(bool largeIcons_);

    // Property getting methods
    const AttributeGroupVector &GetActionConfigurations() const;
          AttributeGroupVector &GetActionConfigurations();
    bool GetToolbarsVisible() const;
    bool GetLargeIcons() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Attributegroup convenience methods
    void AddActionConfigurations(const ActionGroupDescription &);
    void ClearActionConfigurations();
    void RemoveActionConfigurations(int i);
    int  GetNumActionConfigurations() const;
    ActionGroupDescription &GetActionConfigurations(int i);
    const ActionGroupDescription &GetActionConfigurations(int i) const;

    ActionGroupDescription &operator [] (int i);
    const ActionGroupDescription &operator [] (int i) const;


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    virtual void ProcessOldVersions(DataNode *parentNode, const char *configVersion);
    void RemoveActionFromNode(DataNode *, const char *, ViewerRPC::ViewerRPCType);
    void RemoveActionFromNode(DataNode *, const char *, const char *);
    void AddAction(DataNode *, const char *, ViewerRPC::ViewerRPCType);
    void AddActionGroup(DataNode *, ActionGroupDescription &);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_actionConfigurations = 0,
        ID_toolbarsVisible,
        ID_largeIcons
    };

protected:
    AttributeGroup *CreateSubAttributeGroup(int index);
private:
    AttributeGroupVector actionConfigurations;
    bool                 toolbarsVisible;
    bool                 largeIcons;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
};

#endif
