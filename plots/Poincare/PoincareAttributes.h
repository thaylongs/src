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

#ifndef POINCAREATTRIBUTES_H
#define POINCAREATTRIBUTES_H
#include <string>
#include <AttributeSubject.h>
#include <ColorAttribute.h>

// ****************************************************************************
// Class: PoincareAttributes
//
// Purpose:
//    Attributes for the Poincare plot
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class PoincareAttributes : public AttributeSubject
{
public:
    enum ColoringMethod
    {
        Solid,
        ColorBySpeed,
        ColorByVorticity,
        ColorByLength,
        ColorByTime,
        ColorBySeedPointID
    };
    enum TerminationType
    {
        Distance,
        Time
    };
    enum SourceType
    {
        PointSource,
        LineSource,
        PlaneSource
    };

    PoincareAttributes();
    PoincareAttributes(const PoincareAttributes &obj);
    virtual ~PoincareAttributes();

    virtual PoincareAttributes& operator = (const PoincareAttributes &obj);
    virtual bool operator == (const PoincareAttributes &obj) const;
    virtual bool operator != (const PoincareAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectPointSource();
    void SelectLineSourceStart();
    void SelectLineSourceEnd();
    void SelectPlaneSourcePoint();
    void SelectPlaneSourceNormal();
    void SelectPlaneSourceUpVec();
    void SelectClipPlaneOrigin();
    void SelectClipPlaneNormal();
    void SelectColorTableName();
    void SelectSingleColor();

    // Property setting methods
    void SetTermination(double termination_);
    void SetTerminationType(TerminationType terminationType_);
    void SetStreamlineSource(SourceType streamlineSource_);
    void SetShowStreamlines(bool showStreamlines_);
    void SetShowPoints(bool showPoints_);
    void SetPointDensity(int pointDensity_);
    void SetSourceRadius(double sourceRadius_);
    void SetPointSource(const double *pointSource_);
    void SetLineSourceStart(const double *lineSourceStart_);
    void SetLineSourceEnd(const double *lineSourceEnd_);
    void SetPlaneSourcePoint(const double *planeSourcePoint_);
    void SetPlaneSourceNormal(const double *planeSourceNormal_);
    void SetPlaneSourceUpVec(const double *planeSourceUpVec_);
    void SetClipPlaneOrigin(const double *clipPlaneOrigin_);
    void SetClipPlaneNormal(const double *clipPlaneNormal_);
    void SetColorTableName(const std::string &colorTableName_);
    void SetSingleColor(const ColorAttribute &singleColor_);
    void SetLegendFlag(bool legendFlag_);
    void SetLightingFlag(bool lightingFlag_);
    void SetRelTol(double relTol_);
    void SetAbsTol(double absTol_);
    void SetMaxStepLength(double maxStepLength_);

    // Property getting methods
    double               GetTermination() const;
    TerminationType      GetTerminationType() const;
    SourceType           GetStreamlineSource() const;
    bool                 GetShowStreamlines() const;
    bool                 GetShowPoints() const;
    int                  GetPointDensity() const;
    double               GetSourceRadius() const;
    const double         *GetPointSource() const;
          double         *GetPointSource();
    const double         *GetLineSourceStart() const;
          double         *GetLineSourceStart();
    const double         *GetLineSourceEnd() const;
          double         *GetLineSourceEnd();
    const double         *GetPlaneSourcePoint() const;
          double         *GetPlaneSourcePoint();
    const double         *GetPlaneSourceNormal() const;
          double         *GetPlaneSourceNormal();
    const double         *GetPlaneSourceUpVec() const;
          double         *GetPlaneSourceUpVec();
    const double         *GetClipPlaneOrigin() const;
          double         *GetClipPlaneOrigin();
    const double         *GetClipPlaneNormal() const;
          double         *GetClipPlaneNormal();
    const std::string    &GetColorTableName() const;
          std::string    &GetColorTableName();
    const ColorAttribute &GetSingleColor() const;
          ColorAttribute &GetSingleColor();
    bool                 GetLegendFlag() const;
    bool                 GetLightingFlag() const;
    double               GetRelTol() const;
    double               GetAbsTol() const;
    double               GetMaxStepLength() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string ColoringMethod_ToString(ColoringMethod);
    static bool ColoringMethod_FromString(const std::string &, ColoringMethod &);
protected:
    static std::string ColoringMethod_ToString(int);
public:
    static std::string TerminationType_ToString(TerminationType);
    static bool TerminationType_FromString(const std::string &, TerminationType &);
protected:
    static std::string TerminationType_ToString(int);
public:
    static std::string SourceType_ToString(SourceType);
    static bool SourceType_FromString(const std::string &, SourceType &);
protected:
    static std::string SourceType_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_termination = 0,
        ID_terminationType,
        ID_streamlineSource,
        ID_showStreamlines,
        ID_showPoints,
        ID_pointDensity,
        ID_sourceRadius,
        ID_pointSource,
        ID_lineSourceStart,
        ID_lineSourceEnd,
        ID_planeSourcePoint,
        ID_planeSourceNormal,
        ID_planeSourceUpVec,
        ID_clipPlaneOrigin,
        ID_clipPlaneNormal,
        ID_colorTableName,
        ID_singleColor,
        ID_legendFlag,
        ID_lightingFlag,
        ID_relTol,
        ID_absTol,
        ID_maxStepLength
    };

private:
    double         termination;
    int            terminationType;
    int            streamlineSource;
    bool           showStreamlines;
    bool           showPoints;
    int            pointDensity;
    double         sourceRadius;
    double         pointSource[3];
    double         lineSourceStart[3];
    double         lineSourceEnd[3];
    double         planeSourcePoint[3];
    double         planeSourceNormal[3];
    double         planeSourceUpVec[3];
    double         clipPlaneOrigin[3];
    double         clipPlaneNormal[3];
    std::string    colorTableName;
    ColorAttribute singleColor;
    bool           legendFlag;
    bool           lightingFlag;
    double         relTol;
    double         absTol;
    double         maxStepLength;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
};

#endif
