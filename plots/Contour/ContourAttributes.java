// ***************************************************************************
//
// Copyright (c) 2000 - 2017, Lawrence Livermore National Security, LLC
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
import llnl.visit.ColorControlPointList;
import java.lang.Byte;
import java.util.Vector;
import llnl.visit.ColorAttribute;
import llnl.visit.ColorAttributeList;
import java.lang.Double;

// ****************************************************************************
// Class: ContourAttributes
//
// Purpose:
//    This class contains the plot attributes for the contour plot.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class ContourAttributes extends AttributeSubject implements Plugin
{
    private static int ContourAttributes_numAdditionalAtts = 20;

    // Enum values
    public final static int SELECT_BY_LEVEL = 0;
    public final static int SELECT_BY_VALUE = 1;
    public final static int SELECT_BY_PERCENT = 2;

    public final static int SCALING_LINEAR = 0;
    public final static int SCALING_LOG = 1;

    public final static int COLORINGMETHOD_COLORBYSINGLECOLOR = 0;
    public final static int COLORINGMETHOD_COLORBYMULTIPLECOLORS = 1;
    public final static int COLORINGMETHOD_COLORBYCOLORTABLE = 2;


    public ContourAttributes()
    {
        super(ContourAttributes_numAdditionalAtts);

        defaultPalette = new ColorControlPointList();
        changedColors = new Vector();
        colorType = COLORINGMETHOD_COLORBYMULTIPLECOLORS;
        colorTableName = new String("Default");
        invertColorTable = false;
        legendFlag = true;
        lineStyle = 0;
        lineWidth = 0;
        singleColor = new ColorAttribute(255, 0, 0);
        multiColor = new ColorAttributeList();
        contourNLevels = 10;
        contourValue = new Vector();
        contourPercent = new Vector();
        contourMethod = SELECT_BY_LEVEL;
        minFlag = false;
        maxFlag = false;
        min = 0;
        max = 1;
        scaling = SCALING_LINEAR;
        wireframe = false;
    }

    public ContourAttributes(int nMoreFields)
    {
        super(ContourAttributes_numAdditionalAtts + nMoreFields);

        defaultPalette = new ColorControlPointList();
        changedColors = new Vector();
        colorType = COLORINGMETHOD_COLORBYMULTIPLECOLORS;
        colorTableName = new String("Default");
        invertColorTable = false;
        legendFlag = true;
        lineStyle = 0;
        lineWidth = 0;
        singleColor = new ColorAttribute(255, 0, 0);
        multiColor = new ColorAttributeList();
        contourNLevels = 10;
        contourValue = new Vector();
        contourPercent = new Vector();
        contourMethod = SELECT_BY_LEVEL;
        minFlag = false;
        maxFlag = false;
        min = 0;
        max = 1;
        scaling = SCALING_LINEAR;
        wireframe = false;
    }

    public ContourAttributes(ContourAttributes obj)
    {
        super(ContourAttributes_numAdditionalAtts);

        int i;

        defaultPalette = new ColorControlPointList(obj.defaultPalette);
        changedColors = new Vector(obj.changedColors.size());
        for(i = 0; i < obj.changedColors.size(); ++i)
        {
            Byte bv = (Byte)obj.changedColors.elementAt(i);
            changedColors.addElement(new Byte(bv.byteValue()));
        }

        colorType = obj.colorType;
        colorTableName = new String(obj.colorTableName);
        invertColorTable = obj.invertColorTable;
        legendFlag = obj.legendFlag;
        lineStyle = obj.lineStyle;
        lineWidth = obj.lineWidth;
        singleColor = new ColorAttribute(obj.singleColor);
        multiColor = new ColorAttributeList(obj.multiColor);
        contourNLevels = obj.contourNLevels;
        contourValue = new Vector(obj.contourValue.size());
        for(i = 0; i < obj.contourValue.size(); ++i)
        {
            Double dv = (Double)obj.contourValue.elementAt(i);
            contourValue.addElement(new Double(dv.doubleValue()));
        }

        contourPercent = new Vector(obj.contourPercent.size());
        for(i = 0; i < obj.contourPercent.size(); ++i)
        {
            Double dv = (Double)obj.contourPercent.elementAt(i);
            contourPercent.addElement(new Double(dv.doubleValue()));
        }

        contourMethod = obj.contourMethod;
        minFlag = obj.minFlag;
        maxFlag = obj.maxFlag;
        min = obj.min;
        max = obj.max;
        scaling = obj.scaling;
        wireframe = obj.wireframe;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return ContourAttributes_numAdditionalAtts;
    }

    public boolean equals(ContourAttributes obj)
    {
        int i;

        // Compare the elements in the contourValue vector.
        boolean contourValue_equal = (obj.contourValue.size() == contourValue.size());
        for(i = 0; (i < contourValue.size()) && contourValue_equal; ++i)
        {
            // Make references to Double from Object.
            Double contourValue1 = (Double)contourValue.elementAt(i);
            Double contourValue2 = (Double)obj.contourValue.elementAt(i);
            contourValue_equal = contourValue1.equals(contourValue2);
        }
        // Compare the elements in the contourPercent vector.
        boolean contourPercent_equal = (obj.contourPercent.size() == contourPercent.size());
        for(i = 0; (i < contourPercent.size()) && contourPercent_equal; ++i)
        {
            // Make references to Double from Object.
            Double contourPercent1 = (Double)contourPercent.elementAt(i);
            Double contourPercent2 = (Double)obj.contourPercent.elementAt(i);
            contourPercent_equal = contourPercent1.equals(contourPercent2);
        }
        // Create the return value
        return (true /* can ignore defaultPalette */ &&
                true /* can ignore changedColors */ &&
                (colorType == obj.colorType) &&
                (colorTableName.equals(obj.colorTableName)) &&
                (invertColorTable == obj.invertColorTable) &&
                (legendFlag == obj.legendFlag) &&
                (lineStyle == obj.lineStyle) &&
                (lineWidth == obj.lineWidth) &&
                (singleColor == obj.singleColor) &&
                (multiColor.equals(obj.multiColor)) &&
                (contourNLevels == obj.contourNLevels) &&
                contourValue_equal &&
                contourPercent_equal &&
                (contourMethod == obj.contourMethod) &&
                (minFlag == obj.minFlag) &&
                (maxFlag == obj.maxFlag) &&
                (min == obj.min) &&
                (max == obj.max) &&
                (scaling == obj.scaling) &&
                (wireframe == obj.wireframe));
    }

    public String GetName() { return "Contour"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetDefaultPalette(ColorControlPointList defaultPalette_)
    {
        defaultPalette = defaultPalette_;
        Select(0);
    }

    public void SetChangedColors(Vector changedColors_)
    {
        changedColors = changedColors_;
        Select(1);
    }

    public void SetColorType(int colorType_)
    {
        colorType = colorType_;
        Select(2);
    }

    public void SetColorTableName(String colorTableName_)
    {
        colorTableName = colorTableName_;
        Select(3);
    }

    public void SetInvertColorTable(boolean invertColorTable_)
    {
        invertColorTable = invertColorTable_;
        Select(4);
    }

    public void SetLegendFlag(boolean legendFlag_)
    {
        legendFlag = legendFlag_;
        Select(5);
    }

    public void SetLineStyle(int lineStyle_)
    {
        lineStyle = lineStyle_;
        Select(6);
    }

    public void SetLineWidth(int lineWidth_)
    {
        lineWidth = lineWidth_;
        Select(7);
    }

    public void SetSingleColor(ColorAttribute singleColor_)
    {
        singleColor = singleColor_;
        Select(8);
    }

    public void SetMultiColor(ColorAttributeList multiColor_)
    {
        multiColor = multiColor_;
        Select(9);
    }

    public void SetContourNLevels(int contourNLevels_)
    {
        contourNLevels = contourNLevels_;
        Select(10);
    }

    public void SetContourValue(Vector contourValue_)
    {
        contourValue = contourValue_;
        Select(11);
    }

    public void SetContourPercent(Vector contourPercent_)
    {
        contourPercent = contourPercent_;
        Select(12);
    }

    public void SetContourMethod(int contourMethod_)
    {
        contourMethod = contourMethod_;
        Select(13);
    }

    public void SetMinFlag(boolean minFlag_)
    {
        minFlag = minFlag_;
        Select(14);
    }

    public void SetMaxFlag(boolean maxFlag_)
    {
        maxFlag = maxFlag_;
        Select(15);
    }

    public void SetMin(double min_)
    {
        min = min_;
        Select(16);
    }

    public void SetMax(double max_)
    {
        max = max_;
        Select(17);
    }

    public void SetScaling(int scaling_)
    {
        scaling = scaling_;
        Select(18);
    }

    public void SetWireframe(boolean wireframe_)
    {
        wireframe = wireframe_;
        Select(19);
    }

    // Property getting methods
    public ColorControlPointList GetDefaultPalette() { return defaultPalette; }
    public Vector                GetChangedColors() { return changedColors; }
    public int                   GetColorType() { return colorType; }
    public String                GetColorTableName() { return colorTableName; }
    public boolean               GetInvertColorTable() { return invertColorTable; }
    public boolean               GetLegendFlag() { return legendFlag; }
    public int                   GetLineStyle() { return lineStyle; }
    public int                   GetLineWidth() { return lineWidth; }
    public ColorAttribute        GetSingleColor() { return singleColor; }
    public ColorAttributeList    GetMultiColor() { return multiColor; }
    public int                   GetContourNLevels() { return contourNLevels; }
    public Vector                GetContourValue() { return contourValue; }
    public Vector                GetContourPercent() { return contourPercent; }
    public int                   GetContourMethod() { return contourMethod; }
    public boolean               GetMinFlag() { return minFlag; }
    public boolean               GetMaxFlag() { return maxFlag; }
    public double                GetMin() { return min; }
    public double                GetMax() { return max; }
    public int                   GetScaling() { return scaling; }
    public boolean               GetWireframe() { return wireframe; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            defaultPalette.Write(buf);
        if(WriteSelect(1, buf))
            buf.WriteByteVector(changedColors);
        if(WriteSelect(2, buf))
            buf.WriteInt(colorType);
        if(WriteSelect(3, buf))
            buf.WriteString(colorTableName);
        if(WriteSelect(4, buf))
            buf.WriteBool(invertColorTable);
        if(WriteSelect(5, buf))
            buf.WriteBool(legendFlag);
        if(WriteSelect(6, buf))
            buf.WriteInt(lineStyle);
        if(WriteSelect(7, buf))
            buf.WriteInt(lineWidth);
        if(WriteSelect(8, buf))
            singleColor.Write(buf);
        if(WriteSelect(9, buf))
            multiColor.Write(buf);
        if(WriteSelect(10, buf))
            buf.WriteInt(contourNLevels);
        if(WriteSelect(11, buf))
            buf.WriteDoubleVector(contourValue);
        if(WriteSelect(12, buf))
            buf.WriteDoubleVector(contourPercent);
        if(WriteSelect(13, buf))
            buf.WriteInt(contourMethod);
        if(WriteSelect(14, buf))
            buf.WriteBool(minFlag);
        if(WriteSelect(15, buf))
            buf.WriteBool(maxFlag);
        if(WriteSelect(16, buf))
            buf.WriteDouble(min);
        if(WriteSelect(17, buf))
            buf.WriteDouble(max);
        if(WriteSelect(18, buf))
            buf.WriteInt(scaling);
        if(WriteSelect(19, buf))
            buf.WriteBool(wireframe);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            defaultPalette.Read(buf);
            Select(0);
            break;
        case 1:
            SetChangedColors(buf.ReadByteVector());
            break;
        case 2:
            SetColorType(buf.ReadInt());
            break;
        case 3:
            SetColorTableName(buf.ReadString());
            break;
        case 4:
            SetInvertColorTable(buf.ReadBool());
            break;
        case 5:
            SetLegendFlag(buf.ReadBool());
            break;
        case 6:
            SetLineStyle(buf.ReadInt());
            break;
        case 7:
            SetLineWidth(buf.ReadInt());
            break;
        case 8:
            singleColor.Read(buf);
            Select(8);
            break;
        case 9:
            multiColor.Read(buf);
            Select(9);
            break;
        case 10:
            SetContourNLevels(buf.ReadInt());
            break;
        case 11:
            SetContourValue(buf.ReadDoubleVector());
            break;
        case 12:
            SetContourPercent(buf.ReadDoubleVector());
            break;
        case 13:
            SetContourMethod(buf.ReadInt());
            break;
        case 14:
            SetMinFlag(buf.ReadBool());
            break;
        case 15:
            SetMaxFlag(buf.ReadBool());
            break;
        case 16:
            SetMin(buf.ReadDouble());
            break;
        case 17:
            SetMax(buf.ReadDouble());
            break;
        case 18:
            SetScaling(buf.ReadInt());
            break;
        case 19:
            SetWireframe(buf.ReadBool());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "defaultPalette = {\n" + defaultPalette.toString(indent + "    ") + indent + "}\n";
        str = str + ucharVectorToString("changedColors", changedColors, indent) + "\n";
        str = str + indent + "colorType = ";
        if(colorType == COLORINGMETHOD_COLORBYSINGLECOLOR)
            str = str + "COLORINGMETHOD_COLORBYSINGLECOLOR";
        if(colorType == COLORINGMETHOD_COLORBYMULTIPLECOLORS)
            str = str + "COLORINGMETHOD_COLORBYMULTIPLECOLORS";
        if(colorType == COLORINGMETHOD_COLORBYCOLORTABLE)
            str = str + "COLORINGMETHOD_COLORBYCOLORTABLE";
        str = str + "\n";
        str = str + stringToString("colorTableName", colorTableName, indent) + "\n";
        str = str + boolToString("invertColorTable", invertColorTable, indent) + "\n";
        str = str + boolToString("legendFlag", legendFlag, indent) + "\n";
        str = str + intToString("lineStyle", lineStyle, indent) + "\n";
        str = str + intToString("lineWidth", lineWidth, indent) + "\n";
        str = str + indent + "singleColor = {" + singleColor.Red() + ", " + singleColor.Green() + ", " + singleColor.Blue() + ", " + singleColor.Alpha() + "}\n";
        str = str + indent + "multiColor = {\n" + multiColor.toString(indent + "    ") + indent + "}\n";
        str = str + intToString("contourNLevels", contourNLevels, indent) + "\n";
        str = str + doubleVectorToString("contourValue", contourValue, indent) + "\n";
        str = str + doubleVectorToString("contourPercent", contourPercent, indent) + "\n";
        str = str + indent + "contourMethod = ";
        if(contourMethod == SELECT_BY_LEVEL)
            str = str + "SELECT_BY_LEVEL";
        if(contourMethod == SELECT_BY_VALUE)
            str = str + "SELECT_BY_VALUE";
        if(contourMethod == SELECT_BY_PERCENT)
            str = str + "SELECT_BY_PERCENT";
        str = str + "\n";
        str = str + boolToString("minFlag", minFlag, indent) + "\n";
        str = str + boolToString("maxFlag", maxFlag, indent) + "\n";
        str = str + doubleToString("min", min, indent) + "\n";
        str = str + doubleToString("max", max, indent) + "\n";
        str = str + indent + "scaling = ";
        if(scaling == SCALING_LINEAR)
            str = str + "SCALING_LINEAR";
        if(scaling == SCALING_LOG)
            str = str + "SCALING_LOG";
        str = str + "\n";
        str = str + boolToString("wireframe", wireframe, indent) + "\n";
        return str;
    }


    // Attributes
    private ColorControlPointList defaultPalette;
    private Vector                changedColors; // vector of Byte objects
    private int                   colorType;
    private String                colorTableName;
    private boolean               invertColorTable;
    private boolean               legendFlag;
    private int                   lineStyle;
    private int                   lineWidth;
    private ColorAttribute        singleColor;
    private ColorAttributeList    multiColor;
    private int                   contourNLevels;
    private Vector                contourValue; // vector of Double objects
    private Vector                contourPercent; // vector of Double objects
    private int                   contourMethod;
    private boolean               minFlag;
    private boolean               maxFlag;
    private double                min;
    private double                max;
    private int                   scaling;
    private boolean               wireframe;
}

