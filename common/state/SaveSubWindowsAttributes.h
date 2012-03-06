/*****************************************************************************
*
* Copyright (c) 2000 - 2012, Lawrence Livermore National Security, LLC
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

#ifndef SAVESUBWINDOWSATTRIBUTES_H
#define SAVESUBWINDOWSATTRIBUTES_H
#include <state_exports.h>
#include <AttributeSubject.h>

#include <SaveSubWindowAttributes.h>
#include <VisItException.h>

// ****************************************************************************
// Class: SaveSubWindowsAttributes
//
// Purpose:
//    
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API SaveSubWindowsAttributes : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    SaveSubWindowsAttributes();
    SaveSubWindowsAttributes(const SaveSubWindowsAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    SaveSubWindowsAttributes(private_tmfs_t tmfs);
    SaveSubWindowsAttributes(const SaveSubWindowsAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~SaveSubWindowsAttributes();

    virtual SaveSubWindowsAttributes& operator = (const SaveSubWindowsAttributes &obj);
    virtual bool operator == (const SaveSubWindowsAttributes &obj) const;
    virtual bool operator != (const SaveSubWindowsAttributes &obj) const;
private:
    void Init();
    void Copy(const SaveSubWindowsAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectWin1();
    void SelectWin2();
    void SelectWin3();
    void SelectWin4();
    void SelectWin5();
    void SelectWin6();
    void SelectWin7();
    void SelectWin8();
    void SelectWin9();
    void SelectWin10();
    void SelectWin11();
    void SelectWin12();
    void SelectWin13();
    void SelectWin14();
    void SelectWin15();
    void SelectWin16();

    // Property setting methods
    void SetWin1(const SaveSubWindowAttributes &win1_);
    void SetWin2(const SaveSubWindowAttributes &win2_);
    void SetWin3(const SaveSubWindowAttributes &win3_);
    void SetWin4(const SaveSubWindowAttributes &win4_);
    void SetWin5(const SaveSubWindowAttributes &win5_);
    void SetWin6(const SaveSubWindowAttributes &win6_);
    void SetWin7(const SaveSubWindowAttributes &win7_);
    void SetWin8(const SaveSubWindowAttributes &win8_);
    void SetWin9(const SaveSubWindowAttributes &win9_);
    void SetWin10(const SaveSubWindowAttributes &win10_);
    void SetWin11(const SaveSubWindowAttributes &win11_);
    void SetWin12(const SaveSubWindowAttributes &win12_);
    void SetWin13(const SaveSubWindowAttributes &win13_);
    void SetWin14(const SaveSubWindowAttributes &win14_);
    void SetWin15(const SaveSubWindowAttributes &win15_);
    void SetWin16(const SaveSubWindowAttributes &win16_);

    // Property getting methods
    const SaveSubWindowAttributes &GetWin1() const;
          SaveSubWindowAttributes &GetWin1();
    const SaveSubWindowAttributes &GetWin2() const;
          SaveSubWindowAttributes &GetWin2();
    const SaveSubWindowAttributes &GetWin3() const;
          SaveSubWindowAttributes &GetWin3();
    const SaveSubWindowAttributes &GetWin4() const;
          SaveSubWindowAttributes &GetWin4();
    const SaveSubWindowAttributes &GetWin5() const;
          SaveSubWindowAttributes &GetWin5();
    const SaveSubWindowAttributes &GetWin6() const;
          SaveSubWindowAttributes &GetWin6();
    const SaveSubWindowAttributes &GetWin7() const;
          SaveSubWindowAttributes &GetWin7();
    const SaveSubWindowAttributes &GetWin8() const;
          SaveSubWindowAttributes &GetWin8();
    const SaveSubWindowAttributes &GetWin9() const;
          SaveSubWindowAttributes &GetWin9();
    const SaveSubWindowAttributes &GetWin10() const;
          SaveSubWindowAttributes &GetWin10();
    const SaveSubWindowAttributes &GetWin11() const;
          SaveSubWindowAttributes &GetWin11();
    const SaveSubWindowAttributes &GetWin12() const;
          SaveSubWindowAttributes &GetWin12();
    const SaveSubWindowAttributes &GetWin13() const;
          SaveSubWindowAttributes &GetWin13();
    const SaveSubWindowAttributes &GetWin14() const;
          SaveSubWindowAttributes &GetWin14();
    const SaveSubWindowAttributes &GetWin15() const;
          SaveSubWindowAttributes &GetWin15();
    const SaveSubWindowAttributes &GetWin16() const;
          SaveSubWindowAttributes &GetWin16();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    SaveSubWindowAttributes &GetAttsForWindow(int);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_win1 = 0,
        ID_win2,
        ID_win3,
        ID_win4,
        ID_win5,
        ID_win6,
        ID_win7,
        ID_win8,
        ID_win9,
        ID_win10,
        ID_win11,
        ID_win12,
        ID_win13,
        ID_win14,
        ID_win15,
        ID_win16,
        ID__LAST
    };

private:
    SaveSubWindowAttributes win1;
    SaveSubWindowAttributes win2;
    SaveSubWindowAttributes win3;
    SaveSubWindowAttributes win4;
    SaveSubWindowAttributes win5;
    SaveSubWindowAttributes win6;
    SaveSubWindowAttributes win7;
    SaveSubWindowAttributes win8;
    SaveSubWindowAttributes win9;
    SaveSubWindowAttributes win10;
    SaveSubWindowAttributes win11;
    SaveSubWindowAttributes win12;
    SaveSubWindowAttributes win13;
    SaveSubWindowAttributes win14;
    SaveSubWindowAttributes win15;
    SaveSubWindowAttributes win16;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define SAVESUBWINDOWSATTRIBUTES_TMFS "aaaaaaaaaaaaaaaa"

#endif
