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

#ifndef CURVEATTRIBUTES_H
#define CURVEATTRIBUTES_H
#include <string>
#include <AttributeSubject.h>

#include <ColorAttribute.h>
#include <visitstream.h>

// ****************************************************************************
// Class: CurveAttributes
//
// Purpose:
//    Attributes for the xy plot
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class CurveAttributes : public AttributeSubject
{
public:
    enum CurveColor
    {
        Cycle,
        Custom
    };
    enum FillMode
    {
        Static,
        Dynamic
    };
    enum SymbolTypes
    {
        Point,
        TriangleUp,
        TriangleDown,
        Square,
        Circle,
        Plus,
        X
    };
    enum CurveFillMode
    {
        NoFill,
        Solid,
        HorizontalGradient,
        VerticalGradient
    };
    enum PolarCoordinateOrder
    {
        R_Theta,
        Theta_R
    };
    enum AngleUnits
    {
        Radians,
        Degrees
    };

    // These constructors are for objects of this class
    CurveAttributes();
    CurveAttributes(const CurveAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    CurveAttributes(private_tmfs_t tmfs);
    CurveAttributes(const CurveAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~CurveAttributes();

    virtual CurveAttributes& operator = (const CurveAttributes &obj);
    virtual bool operator == (const CurveAttributes &obj) const;
    virtual bool operator != (const CurveAttributes &obj) const;
private:
    void Init();
    void Copy(const CurveAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectCurveColor();
    void SelectDesignator();
    void SelectBallTimeCueColor();
    void SelectLineTimeCueColor();
    void SelectFillColor1();
    void SelectFillColor2();

    // Property setting methods
    void SetShowLines(bool showLines_);
    void SetLineStyle(int lineStyle_);
    void SetLineWidth(int lineWidth_);
    void SetShowPoints(bool showPoints_);
    void SetSymbol(SymbolTypes symbol_);
    void SetPointSize(double pointSize_);
    void SetPointFillMode(FillMode pointFillMode_);
    void SetPointStride(int pointStride_);
    void SetSymbolDensity(int symbolDensity_);
    void SetCurveColorSource(CurveColor curveColorSource_);
    void SetCurveColor(const ColorAttribute &curveColor_);
    void SetShowLegend(bool showLegend_);
    void SetShowLabels(bool showLabels_);
    void SetDesignator(const std::string &designator_);
    void SetDoBallTimeCue(bool doBallTimeCue_);
    void SetBallTimeCueColor(const ColorAttribute &ballTimeCueColor_);
    void SetTimeCueBallSize(double timeCueBallSize_);
    void SetDoLineTimeCue(bool doLineTimeCue_);
    void SetLineTimeCueColor(const ColorAttribute &lineTimeCueColor_);
    void SetLineTimeCueWidth(int lineTimeCueWidth_);
    void SetDoCropTimeCue(bool doCropTimeCue_);
    void SetTimeForTimeCue(double timeForTimeCue_);
    void SetFillMode(CurveFillMode fillMode_);
    void SetFillColor1(const ColorAttribute &fillColor1_);
    void SetFillColor2(const ColorAttribute &fillColor2_);
    void SetPolarToCartesian(bool polarToCartesian_);
    void SetPolarCoordinateOrder(PolarCoordinateOrder polarCoordinateOrder_);
    void SetAngleUnits(AngleUnits angleUnits_);

    // Property getting methods
    bool                 GetShowLines() const;
    int                  GetLineStyle() const;
    int                  GetLineWidth() const;
    bool                 GetShowPoints() const;
    SymbolTypes          GetSymbol() const;
    double               GetPointSize() const;
    FillMode             GetPointFillMode() const;
    int                  GetPointStride() const;
    int                  GetSymbolDensity() const;
    CurveColor           GetCurveColorSource() const;
    const ColorAttribute &GetCurveColor() const;
          ColorAttribute &GetCurveColor();
    bool                 GetShowLegend() const;
    bool                 GetShowLabels() const;
    const std::string    &GetDesignator() const;
          std::string    &GetDesignator();
    bool                 GetDoBallTimeCue() const;
    const ColorAttribute &GetBallTimeCueColor() const;
          ColorAttribute &GetBallTimeCueColor();
    double               GetTimeCueBallSize() const;
    bool                 GetDoLineTimeCue() const;
    const ColorAttribute &GetLineTimeCueColor() const;
          ColorAttribute &GetLineTimeCueColor();
    int                  GetLineTimeCueWidth() const;
    bool                 GetDoCropTimeCue() const;
    double               GetTimeForTimeCue() const;
    CurveFillMode        GetFillMode() const;
    const ColorAttribute &GetFillColor1() const;
          ColorAttribute &GetFillColor1();
    const ColorAttribute &GetFillColor2() const;
          ColorAttribute &GetFillColor2();
    bool                 GetPolarToCartesian() const;
    PolarCoordinateOrder GetPolarCoordinateOrder() const;
    AngleUnits           GetAngleUnits() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string CurveColor_ToString(CurveColor);
    static bool CurveColor_FromString(const std::string &, CurveColor &);
protected:
    static std::string CurveColor_ToString(int);
public:
    static std::string FillMode_ToString(FillMode);
    static bool FillMode_FromString(const std::string &, FillMode &);
protected:
    static std::string FillMode_ToString(int);
public:
    static std::string SymbolTypes_ToString(SymbolTypes);
    static bool SymbolTypes_FromString(const std::string &, SymbolTypes &);
protected:
    static std::string SymbolTypes_ToString(int);
public:
    static std::string CurveFillMode_ToString(CurveFillMode);
    static bool CurveFillMode_FromString(const std::string &, CurveFillMode &);
protected:
    static std::string CurveFillMode_ToString(int);
public:
    static std::string PolarCoordinateOrder_ToString(PolarCoordinateOrder);
    static bool PolarCoordinateOrder_FromString(const std::string &, PolarCoordinateOrder &);
protected:
    static std::string PolarCoordinateOrder_ToString(int);
public:
    static std::string AngleUnits_ToString(AngleUnits);
    static bool AngleUnits_FromString(const std::string &, AngleUnits &);
protected:
    static std::string AngleUnits_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    bool ChangesRequireRecalculation(const CurveAttributes &) const;
    virtual void  ProcessOldVersions(DataNode *parentNode, const char *configVersion);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_showLines = 0,
        ID_lineStyle,
        ID_lineWidth,
        ID_showPoints,
        ID_symbol,
        ID_pointSize,
        ID_pointFillMode,
        ID_pointStride,
        ID_symbolDensity,
        ID_curveColorSource,
        ID_curveColor,
        ID_showLegend,
        ID_showLabels,
        ID_designator,
        ID_doBallTimeCue,
        ID_ballTimeCueColor,
        ID_timeCueBallSize,
        ID_doLineTimeCue,
        ID_lineTimeCueColor,
        ID_lineTimeCueWidth,
        ID_doCropTimeCue,
        ID_timeForTimeCue,
        ID_fillMode,
        ID_fillColor1,
        ID_fillColor2,
        ID_polarToCartesian,
        ID_polarCoordinateOrder,
        ID_angleUnits,
        ID__LAST
    };

private:
    bool           showLines;
    int            lineStyle;
    int            lineWidth;
    bool           showPoints;
    int            symbol;
    double         pointSize;
    int            pointFillMode;
    int            pointStride;
    int            symbolDensity;
    int            curveColorSource;
    ColorAttribute curveColor;
    bool           showLegend;
    bool           showLabels;
    std::string    designator;
    bool           doBallTimeCue;
    ColorAttribute ballTimeCueColor;
    double         timeCueBallSize;
    bool           doLineTimeCue;
    ColorAttribute lineTimeCueColor;
    int            lineTimeCueWidth;
    bool           doCropTimeCue;
    double         timeForTimeCue;
    int            fillMode;
    ColorAttribute fillColor1;
    ColorAttribute fillColor2;
    bool           polarToCartesian;
    int            polarCoordinateOrder;
    int            angleUnits;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define CURVEATTRIBUTES_TMFS "biibidiiiiabbsbadbaibdiaabii"

#endif
