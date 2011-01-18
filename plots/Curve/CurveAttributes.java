// ***************************************************************************
//
// Copyright (c) 2000 - 2011, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory
// LLNL-CODE-442911
// All rights reserved.
//
// This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
// full copyright notice is contained in the file COPYRIGHT located at the root
// of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
//
// Redistribution  and  use  in  source  and  binary  forms,  with  or  without
// modification, are permitted provided that the following conditions are met:
//
//  - Redistributions of  source code must  retain the above  copyright notice,
//    this list of conditions and the disclaimer below.
//  - Redistributions in binary form must reproduce the above copyright notice,
//    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
//    documentation and/or other materials provided with the distribution.
//  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
//    be used to endorse or promote products derived from this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
// LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
// DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ***************************************************************************

package llnl.visit.plots;

import llnl.visit.AttributeSubject;
import llnl.visit.CommunicationBuffer;
import llnl.visit.Plugin;
import llnl.visit.ColorAttribute;

// ****************************************************************************
// Class: CurveAttributes
//
// Purpose:
//    Attributes for the xy plot
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class CurveAttributes extends AttributeSubject implements Plugin
{
    private static int CurveAttributes_numAdditionalAtts = 22;

    // Enum values
    public final static int CURVECOLOR_CYCLE = 0;
    public final static int CURVECOLOR_CUSTOM = 1;

    public final static int FILLMODE_STATIC = 0;
    public final static int FILLMODE_DYNAMIC = 1;

    public final static int SYMBOLTYPES_POINT = 0;
    public final static int SYMBOLTYPES_TRIANGLEUP = 1;
    public final static int SYMBOLTYPES_TRIANGLEDOWN = 2;
    public final static int SYMBOLTYPES_SQUARE = 3;
    public final static int SYMBOLTYPES_CIRCLE = 4;
    public final static int SYMBOLTYPES_PLUS = 5;
    public final static int SYMBOLTYPES_X = 6;


    public CurveAttributes()
    {
        super(CurveAttributes_numAdditionalAtts);

        showLines = true;
        lineStyle = 0;
        lineWidth = 0;
        showPoints = false;
        symbol = SYMBOLTYPES_POINT;
        pointSize = 5;
        pointFillMode = FILLMODE_STATIC;
        pointStride = 1;
        symbolDensity = 50;
        curveColorSource = CURVECOLOR_CYCLE;
        curveColor = new ColorAttribute(0, 0, 0);
        showLegend = true;
        showLabels = true;
        designator = new String("");
        doBallTimeCue = false;
        ballTimeCueColor = new ColorAttribute(0, 0, 0);
        timeCueBallSize = 0.01;
        doLineTimeCue = false;
        lineTimeCueColor = new ColorAttribute(0, 0, 0);
        lineTimeCueWidth = 0;
        doCropTimeCue = false;
        timeForTimeCue = 0;
    }

    public CurveAttributes(int nMoreFields)
    {
        super(CurveAttributes_numAdditionalAtts + nMoreFields);

        showLines = true;
        lineStyle = 0;
        lineWidth = 0;
        showPoints = false;
        symbol = SYMBOLTYPES_POINT;
        pointSize = 5;
        pointFillMode = FILLMODE_STATIC;
        pointStride = 1;
        symbolDensity = 50;
        curveColorSource = CURVECOLOR_CYCLE;
        curveColor = new ColorAttribute(0, 0, 0);
        showLegend = true;
        showLabels = true;
        designator = new String("");
        doBallTimeCue = false;
        ballTimeCueColor = new ColorAttribute(0, 0, 0);
        timeCueBallSize = 0.01;
        doLineTimeCue = false;
        lineTimeCueColor = new ColorAttribute(0, 0, 0);
        lineTimeCueWidth = 0;
        doCropTimeCue = false;
        timeForTimeCue = 0;
    }

    public CurveAttributes(CurveAttributes obj)
    {
        super(CurveAttributes_numAdditionalAtts);

        showLines = obj.showLines;
        lineStyle = obj.lineStyle;
        lineWidth = obj.lineWidth;
        showPoints = obj.showPoints;
        symbol = obj.symbol;
        pointSize = obj.pointSize;
        pointFillMode = obj.pointFillMode;
        pointStride = obj.pointStride;
        symbolDensity = obj.symbolDensity;
        curveColorSource = obj.curveColorSource;
        curveColor = new ColorAttribute(obj.curveColor);
        showLegend = obj.showLegend;
        showLabels = obj.showLabels;
        designator = new String(obj.designator);
        doBallTimeCue = obj.doBallTimeCue;
        ballTimeCueColor = new ColorAttribute(obj.ballTimeCueColor);
        timeCueBallSize = obj.timeCueBallSize;
        doLineTimeCue = obj.doLineTimeCue;
        lineTimeCueColor = new ColorAttribute(obj.lineTimeCueColor);
        lineTimeCueWidth = obj.lineTimeCueWidth;
        doCropTimeCue = obj.doCropTimeCue;
        timeForTimeCue = obj.timeForTimeCue;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return CurveAttributes_numAdditionalAtts;
    }

    public boolean equals(CurveAttributes obj)
    {
        // Create the return value
        return ((showLines == obj.showLines) &&
                (lineStyle == obj.lineStyle) &&
                (lineWidth == obj.lineWidth) &&
                (showPoints == obj.showPoints) &&
                (symbol == obj.symbol) &&
                (pointSize == obj.pointSize) &&
                (pointFillMode == obj.pointFillMode) &&
                (pointStride == obj.pointStride) &&
                (symbolDensity == obj.symbolDensity) &&
                (curveColorSource == obj.curveColorSource) &&
                (curveColor == obj.curveColor) &&
                (showLegend == obj.showLegend) &&
                (showLabels == obj.showLabels) &&
                (designator.equals(obj.designator)) &&
                (doBallTimeCue == obj.doBallTimeCue) &&
                (ballTimeCueColor == obj.ballTimeCueColor) &&
                (timeCueBallSize == obj.timeCueBallSize) &&
                (doLineTimeCue == obj.doLineTimeCue) &&
                (lineTimeCueColor == obj.lineTimeCueColor) &&
                (lineTimeCueWidth == obj.lineTimeCueWidth) &&
                (doCropTimeCue == obj.doCropTimeCue) &&
                (timeForTimeCue == obj.timeForTimeCue));
    }

    public String GetName() { return "Curve"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetShowLines(boolean showLines_)
    {
        showLines = showLines_;
        Select(0);
    }

    public void SetLineStyle(int lineStyle_)
    {
        lineStyle = lineStyle_;
        Select(1);
    }

    public void SetLineWidth(int lineWidth_)
    {
        lineWidth = lineWidth_;
        Select(2);
    }

    public void SetShowPoints(boolean showPoints_)
    {
        showPoints = showPoints_;
        Select(3);
    }

    public void SetSymbol(int symbol_)
    {
        symbol = symbol_;
        Select(4);
    }

    public void SetPointSize(double pointSize_)
    {
        pointSize = pointSize_;
        Select(5);
    }

    public void SetPointFillMode(int pointFillMode_)
    {
        pointFillMode = pointFillMode_;
        Select(6);
    }

    public void SetPointStride(int pointStride_)
    {
        pointStride = pointStride_;
        Select(7);
    }

    public void SetSymbolDensity(int symbolDensity_)
    {
        symbolDensity = symbolDensity_;
        Select(8);
    }

    public void SetCurveColorSource(int curveColorSource_)
    {
        curveColorSource = curveColorSource_;
        Select(9);
    }

    public void SetCurveColor(ColorAttribute curveColor_)
    {
        curveColor = curveColor_;
        Select(10);
    }

    public void SetShowLegend(boolean showLegend_)
    {
        showLegend = showLegend_;
        Select(11);
    }

    public void SetShowLabels(boolean showLabels_)
    {
        showLabels = showLabels_;
        Select(12);
    }

    public void SetDesignator(String designator_)
    {
        designator = designator_;
        Select(13);
    }

    public void SetDoBallTimeCue(boolean doBallTimeCue_)
    {
        doBallTimeCue = doBallTimeCue_;
        Select(14);
    }

    public void SetBallTimeCueColor(ColorAttribute ballTimeCueColor_)
    {
        ballTimeCueColor = ballTimeCueColor_;
        Select(15);
    }

    public void SetTimeCueBallSize(double timeCueBallSize_)
    {
        timeCueBallSize = timeCueBallSize_;
        Select(16);
    }

    public void SetDoLineTimeCue(boolean doLineTimeCue_)
    {
        doLineTimeCue = doLineTimeCue_;
        Select(17);
    }

    public void SetLineTimeCueColor(ColorAttribute lineTimeCueColor_)
    {
        lineTimeCueColor = lineTimeCueColor_;
        Select(18);
    }

    public void SetLineTimeCueWidth(int lineTimeCueWidth_)
    {
        lineTimeCueWidth = lineTimeCueWidth_;
        Select(19);
    }

    public void SetDoCropTimeCue(boolean doCropTimeCue_)
    {
        doCropTimeCue = doCropTimeCue_;
        Select(20);
    }

    public void SetTimeForTimeCue(double timeForTimeCue_)
    {
        timeForTimeCue = timeForTimeCue_;
        Select(21);
    }

    // Property getting methods
    public boolean        GetShowLines() { return showLines; }
    public int            GetLineStyle() { return lineStyle; }
    public int            GetLineWidth() { return lineWidth; }
    public boolean        GetShowPoints() { return showPoints; }
    public int            GetSymbol() { return symbol; }
    public double         GetPointSize() { return pointSize; }
    public int            GetPointFillMode() { return pointFillMode; }
    public int            GetPointStride() { return pointStride; }
    public int            GetSymbolDensity() { return symbolDensity; }
    public int            GetCurveColorSource() { return curveColorSource; }
    public ColorAttribute GetCurveColor() { return curveColor; }
    public boolean        GetShowLegend() { return showLegend; }
    public boolean        GetShowLabels() { return showLabels; }
    public String         GetDesignator() { return designator; }
    public boolean        GetDoBallTimeCue() { return doBallTimeCue; }
    public ColorAttribute GetBallTimeCueColor() { return ballTimeCueColor; }
    public double         GetTimeCueBallSize() { return timeCueBallSize; }
    public boolean        GetDoLineTimeCue() { return doLineTimeCue; }
    public ColorAttribute GetLineTimeCueColor() { return lineTimeCueColor; }
    public int            GetLineTimeCueWidth() { return lineTimeCueWidth; }
    public boolean        GetDoCropTimeCue() { return doCropTimeCue; }
    public double         GetTimeForTimeCue() { return timeForTimeCue; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteBool(showLines);
        if(WriteSelect(1, buf))
            buf.WriteInt(lineStyle);
        if(WriteSelect(2, buf))
            buf.WriteInt(lineWidth);
        if(WriteSelect(3, buf))
            buf.WriteBool(showPoints);
        if(WriteSelect(4, buf))
            buf.WriteInt(symbol);
        if(WriteSelect(5, buf))
            buf.WriteDouble(pointSize);
        if(WriteSelect(6, buf))
            buf.WriteInt(pointFillMode);
        if(WriteSelect(7, buf))
            buf.WriteInt(pointStride);
        if(WriteSelect(8, buf))
            buf.WriteInt(symbolDensity);
        if(WriteSelect(9, buf))
            buf.WriteInt(curveColorSource);
        if(WriteSelect(10, buf))
            curveColor.Write(buf);
        if(WriteSelect(11, buf))
            buf.WriteBool(showLegend);
        if(WriteSelect(12, buf))
            buf.WriteBool(showLabels);
        if(WriteSelect(13, buf))
            buf.WriteString(designator);
        if(WriteSelect(14, buf))
            buf.WriteBool(doBallTimeCue);
        if(WriteSelect(15, buf))
            ballTimeCueColor.Write(buf);
        if(WriteSelect(16, buf))
            buf.WriteDouble(timeCueBallSize);
        if(WriteSelect(17, buf))
            buf.WriteBool(doLineTimeCue);
        if(WriteSelect(18, buf))
            lineTimeCueColor.Write(buf);
        if(WriteSelect(19, buf))
            buf.WriteInt(lineTimeCueWidth);
        if(WriteSelect(20, buf))
            buf.WriteBool(doCropTimeCue);
        if(WriteSelect(21, buf))
            buf.WriteDouble(timeForTimeCue);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetShowLines(buf.ReadBool());
            break;
        case 1:
            SetLineStyle(buf.ReadInt());
            break;
        case 2:
            SetLineWidth(buf.ReadInt());
            break;
        case 3:
            SetShowPoints(buf.ReadBool());
            break;
        case 4:
            SetSymbol(buf.ReadInt());
            break;
        case 5:
            SetPointSize(buf.ReadDouble());
            break;
        case 6:
            SetPointFillMode(buf.ReadInt());
            break;
        case 7:
            SetPointStride(buf.ReadInt());
            break;
        case 8:
            SetSymbolDensity(buf.ReadInt());
            break;
        case 9:
            SetCurveColorSource(buf.ReadInt());
            break;
        case 10:
            curveColor.Read(buf);
            Select(10);
            break;
        case 11:
            SetShowLegend(buf.ReadBool());
            break;
        case 12:
            SetShowLabels(buf.ReadBool());
            break;
        case 13:
            SetDesignator(buf.ReadString());
            break;
        case 14:
            SetDoBallTimeCue(buf.ReadBool());
            break;
        case 15:
            ballTimeCueColor.Read(buf);
            Select(15);
            break;
        case 16:
            SetTimeCueBallSize(buf.ReadDouble());
            break;
        case 17:
            SetDoLineTimeCue(buf.ReadBool());
            break;
        case 18:
            lineTimeCueColor.Read(buf);
            Select(18);
            break;
        case 19:
            SetLineTimeCueWidth(buf.ReadInt());
            break;
        case 20:
            SetDoCropTimeCue(buf.ReadBool());
            break;
        case 21:
            SetTimeForTimeCue(buf.ReadDouble());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + boolToString("showLines", showLines, indent) + "\n";
        str = str + intToString("lineStyle", lineStyle, indent) + "\n";
        str = str + intToString("lineWidth", lineWidth, indent) + "\n";
        str = str + boolToString("showPoints", showPoints, indent) + "\n";
        str = str + indent + "symbol = ";
        if(symbol == SYMBOLTYPES_POINT)
            str = str + "SYMBOLTYPES_POINT";
        if(symbol == SYMBOLTYPES_TRIANGLEUP)
            str = str + "SYMBOLTYPES_TRIANGLEUP";
        if(symbol == SYMBOLTYPES_TRIANGLEDOWN)
            str = str + "SYMBOLTYPES_TRIANGLEDOWN";
        if(symbol == SYMBOLTYPES_SQUARE)
            str = str + "SYMBOLTYPES_SQUARE";
        if(symbol == SYMBOLTYPES_CIRCLE)
            str = str + "SYMBOLTYPES_CIRCLE";
        if(symbol == SYMBOLTYPES_PLUS)
            str = str + "SYMBOLTYPES_PLUS";
        if(symbol == SYMBOLTYPES_X)
            str = str + "SYMBOLTYPES_X";
        str = str + "\n";
        str = str + doubleToString("pointSize", pointSize, indent) + "\n";
        str = str + indent + "pointFillMode = ";
        if(pointFillMode == FILLMODE_STATIC)
            str = str + "FILLMODE_STATIC";
        if(pointFillMode == FILLMODE_DYNAMIC)
            str = str + "FILLMODE_DYNAMIC";
        str = str + "\n";
        str = str + intToString("pointStride", pointStride, indent) + "\n";
        str = str + intToString("symbolDensity", symbolDensity, indent) + "\n";
        str = str + indent + "curveColorSource = ";
        if(curveColorSource == CURVECOLOR_CYCLE)
            str = str + "CURVECOLOR_CYCLE";
        if(curveColorSource == CURVECOLOR_CUSTOM)
            str = str + "CURVECOLOR_CUSTOM";
        str = str + "\n";
        str = str + indent + "curveColor = {" + curveColor.Red() + ", " + curveColor.Green() + ", " + curveColor.Blue() + ", " + curveColor.Alpha() + "}\n";
        str = str + boolToString("showLegend", showLegend, indent) + "\n";
        str = str + boolToString("showLabels", showLabels, indent) + "\n";
        str = str + stringToString("designator", designator, indent) + "\n";
        str = str + boolToString("doBallTimeCue", doBallTimeCue, indent) + "\n";
        str = str + indent + "ballTimeCueColor = {" + ballTimeCueColor.Red() + ", " + ballTimeCueColor.Green() + ", " + ballTimeCueColor.Blue() + ", " + ballTimeCueColor.Alpha() + "}\n";
        str = str + doubleToString("timeCueBallSize", timeCueBallSize, indent) + "\n";
        str = str + boolToString("doLineTimeCue", doLineTimeCue, indent) + "\n";
        str = str + indent + "lineTimeCueColor = {" + lineTimeCueColor.Red() + ", " + lineTimeCueColor.Green() + ", " + lineTimeCueColor.Blue() + ", " + lineTimeCueColor.Alpha() + "}\n";
        str = str + intToString("lineTimeCueWidth", lineTimeCueWidth, indent) + "\n";
        str = str + boolToString("doCropTimeCue", doCropTimeCue, indent) + "\n";
        str = str + doubleToString("timeForTimeCue", timeForTimeCue, indent) + "\n";
        return str;
    }


    // Attributes
    private boolean        showLines;
    private int            lineStyle;
    private int            lineWidth;
    private boolean        showPoints;
    private int            symbol;
    private double         pointSize;
    private int            pointFillMode;
    private int            pointStride;
    private int            symbolDensity;
    private int            curveColorSource;
    private ColorAttribute curveColor;
    private boolean        showLegend;
    private boolean        showLabels;
    private String         designator;
    private boolean        doBallTimeCue;
    private ColorAttribute ballTimeCueColor;
    private double         timeCueBallSize;
    private boolean        doLineTimeCue;
    private ColorAttribute lineTimeCueColor;
    private int            lineTimeCueWidth;
    private boolean        doCropTimeCue;
    private double         timeForTimeCue;
}

