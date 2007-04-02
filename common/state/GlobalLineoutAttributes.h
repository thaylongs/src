/*****************************************************************************
*
* Copyright (c) 2000 - 2006, The Regents of the University of California
* Produced at the Lawrence Livermore National Laboratory
* All rights reserved.
*
* This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
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
*    documentation and/or materials provided with the distribution.
*  - Neither the name of the UC/LLNL nor  the names of its contributors may be
*    used to  endorse or  promote products derived from  this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
* CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
* ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef GLOBALLINEOUTATTRIBUTES_H
#define GLOBALLINEOUTATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: GlobalLineoutAttributes
//
// Purpose:
//    This file contains global attributes controlling Lineouts.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Thu Nov 2 10:38:10 PDT 2006
//
// Modifications:
//   
// ****************************************************************************

class STATE_API GlobalLineoutAttributes : public AttributeSubject
{
public:
    enum CurveOptions
    {
        UpdateCurve,
        CreateCurve
    };
    enum ColorOptions
    {
        RepeatColor,
        CreateColor
    };

    GlobalLineoutAttributes();
    GlobalLineoutAttributes(const GlobalLineoutAttributes &obj);
    virtual ~GlobalLineoutAttributes();

    virtual GlobalLineoutAttributes& operator = (const GlobalLineoutAttributes &obj);
    virtual bool operator == (const GlobalLineoutAttributes &obj) const;
    virtual bool operator != (const GlobalLineoutAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetDynamic(bool Dynamic_);
    void SetCreateWindow(bool createWindow_);
    void SetWindowId(int windowId_);
    void SetSamplingOn(bool samplingOn_);
    void SetNumSamples(int numSamples_);
    void SetCreateReflineLabels(bool createReflineLabels_);
    void SetCurveOption(CurveOptions curveOption_);
    void SetColorOption(ColorOptions colorOption_);
    void SetFreezeInTime(bool freezeInTime_);

    // Property getting methods
    bool GetDynamic() const;
    bool GetCreateWindow() const;
    int  GetWindowId() const;
    bool GetSamplingOn() const;
    int  GetNumSamples() const;
    bool GetCreateReflineLabels() const;
    CurveOptions GetCurveOption() const;
    ColorOptions GetColorOption() const;
    bool GetFreezeInTime() const;

    // Enum conversion functions
    static std::string CurveOptions_ToString(CurveOptions);
    static bool CurveOptions_FromString(const std::string &, CurveOptions &);
protected:
    static std::string CurveOptions_ToString(int);
public:
    static std::string ColorOptions_ToString(ColorOptions);
    static bool ColorOptions_FromString(const std::string &, ColorOptions &);
protected:
    static std::string ColorOptions_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    bool Dynamic;
    bool createWindow;
    int  windowId;
    bool samplingOn;
    int  numSamples;
    bool createReflineLabels;
    int  curveOption;
    int  colorOption;
    bool freezeInTime;
};

#endif
