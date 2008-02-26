// ***************************************************************************
//
// Copyright (c) 2000 - 2008, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory
// LLNL-CODE-400142
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

// ****************************************************************************
// Class: PseudocolorAttributes
//
// Purpose:
//    Attributes for the pseudocolor plot
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Mon Feb 25 15:34:40 PST 2008
//
// Modifications:
//   
// ****************************************************************************

public class PseudocolorAttributes extends AttributeSubject implements Plugin
{
    // Enum values
    public final static int CENTERING_NATURAL = 0;
    public final static int CENTERING_NODAL = 1;
    public final static int CENTERING_ZONAL = 2;

    public final static int SCALING_LINEAR = 0;
    public final static int SCALING_LOG = 1;
    public final static int SCALING_SKEW = 2;

    public final static int LIMITSMODE_ORIGINALDATA = 0;
    public final static int LIMITSMODE_CURRENTPLOT = 1;

    public final static int POINTTYPE_BOX = 0;
    public final static int POINTTYPE_AXIS = 1;
    public final static int POINTTYPE_ICOSAHEDRON = 2;
    public final static int POINTTYPE_POINT = 3;
    public final static int POINTTYPE_SPHERE = 4;


    public PseudocolorAttributes()
    {
        super(18);

        legendFlag = true;
        lightingFlag = true;
        minFlag = false;
        maxFlag = false;
        centering = CENTERING_NATURAL;
        scaling = SCALING_LINEAR;
        limitsMode = LIMITSMODE_ORIGINALDATA;
        min = 0;
        max = 1;
        pointSize = 0.05;
        pointType = POINTTYPE_POINT;
        skewFactor = 1;
        opacity = 1;
        colorTableName = new String("hot");
        smoothingLevel = 0;
        pointSizeVarEnabled = false;
        pointSizeVar = new String("default");
        pointSizePixels = 2;
    }

    public PseudocolorAttributes(PseudocolorAttributes obj)
    {
        super(18);

        legendFlag = obj.legendFlag;
        lightingFlag = obj.lightingFlag;
        minFlag = obj.minFlag;
        maxFlag = obj.maxFlag;
        centering = obj.centering;
        scaling = obj.scaling;
        limitsMode = obj.limitsMode;
        min = obj.min;
        max = obj.max;
        pointSize = obj.pointSize;
        pointType = obj.pointType;
        skewFactor = obj.skewFactor;
        opacity = obj.opacity;
        colorTableName = new String(obj.colorTableName);
        smoothingLevel = obj.smoothingLevel;
        pointSizeVarEnabled = obj.pointSizeVarEnabled;
        pointSizeVar = new String(obj.pointSizeVar);
        pointSizePixels = obj.pointSizePixels;

        SelectAll();
    }

    public boolean equals(PseudocolorAttributes obj)
    {
        // Create the return value
        return ((legendFlag == obj.legendFlag) &&
                (lightingFlag == obj.lightingFlag) &&
                (minFlag == obj.minFlag) &&
                (maxFlag == obj.maxFlag) &&
                (centering == obj.centering) &&
                (scaling == obj.scaling) &&
                (limitsMode == obj.limitsMode) &&
                (min == obj.min) &&
                (max == obj.max) &&
                (pointSize == obj.pointSize) &&
                (pointType == obj.pointType) &&
                (skewFactor == obj.skewFactor) &&
                (opacity == obj.opacity) &&
                (colorTableName == obj.colorTableName) &&
                (smoothingLevel == obj.smoothingLevel) &&
                (pointSizeVarEnabled == obj.pointSizeVarEnabled) &&
                (pointSizeVar == obj.pointSizeVar) &&
                (pointSizePixels == obj.pointSizePixels));
    }

    public String GetName() { return "Pseudocolor"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetLegendFlag(boolean legendFlag_)
    {
        legendFlag = legendFlag_;
        Select(0);
    }

    public void SetLightingFlag(boolean lightingFlag_)
    {
        lightingFlag = lightingFlag_;
        Select(1);
    }

    public void SetMinFlag(boolean minFlag_)
    {
        minFlag = minFlag_;
        Select(2);
    }

    public void SetMaxFlag(boolean maxFlag_)
    {
        maxFlag = maxFlag_;
        Select(3);
    }

    public void SetCentering(int centering_)
    {
        centering = centering_;
        Select(4);
    }

    public void SetScaling(int scaling_)
    {
        scaling = scaling_;
        Select(5);
    }

    public void SetLimitsMode(int limitsMode_)
    {
        limitsMode = limitsMode_;
        Select(6);
    }

    public void SetMin(double min_)
    {
        min = min_;
        Select(7);
    }

    public void SetMax(double max_)
    {
        max = max_;
        Select(8);
    }

    public void SetPointSize(double pointSize_)
    {
        pointSize = pointSize_;
        Select(9);
    }

    public void SetPointType(int pointType_)
    {
        pointType = pointType_;
        Select(10);
    }

    public void SetSkewFactor(double skewFactor_)
    {
        skewFactor = skewFactor_;
        Select(11);
    }

    public void SetOpacity(double opacity_)
    {
        opacity = opacity_;
        Select(12);
    }

    public void SetColorTableName(String colorTableName_)
    {
        colorTableName = colorTableName_;
        Select(13);
    }

    public void SetSmoothingLevel(int smoothingLevel_)
    {
        smoothingLevel = smoothingLevel_;
        Select(14);
    }

    public void SetPointSizeVarEnabled(boolean pointSizeVarEnabled_)
    {
        pointSizeVarEnabled = pointSizeVarEnabled_;
        Select(15);
    }

    public void SetPointSizeVar(String pointSizeVar_)
    {
        pointSizeVar = pointSizeVar_;
        Select(16);
    }

    public void SetPointSizePixels(int pointSizePixels_)
    {
        pointSizePixels = pointSizePixels_;
        Select(17);
    }

    // Property getting methods
    public boolean GetLegendFlag() { return legendFlag; }
    public boolean GetLightingFlag() { return lightingFlag; }
    public boolean GetMinFlag() { return minFlag; }
    public boolean GetMaxFlag() { return maxFlag; }
    public int     GetCentering() { return centering; }
    public int     GetScaling() { return scaling; }
    public int     GetLimitsMode() { return limitsMode; }
    public double  GetMin() { return min; }
    public double  GetMax() { return max; }
    public double  GetPointSize() { return pointSize; }
    public int     GetPointType() { return pointType; }
    public double  GetSkewFactor() { return skewFactor; }
    public double  GetOpacity() { return opacity; }
    public String  GetColorTableName() { return colorTableName; }
    public int     GetSmoothingLevel() { return smoothingLevel; }
    public boolean GetPointSizeVarEnabled() { return pointSizeVarEnabled; }
    public String  GetPointSizeVar() { return pointSizeVar; }
    public int     GetPointSizePixels() { return pointSizePixels; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteBool(legendFlag);
        if(WriteSelect(1, buf))
            buf.WriteBool(lightingFlag);
        if(WriteSelect(2, buf))
            buf.WriteBool(minFlag);
        if(WriteSelect(3, buf))
            buf.WriteBool(maxFlag);
        if(WriteSelect(4, buf))
            buf.WriteInt(centering);
        if(WriteSelect(5, buf))
            buf.WriteInt(scaling);
        if(WriteSelect(6, buf))
            buf.WriteInt(limitsMode);
        if(WriteSelect(7, buf))
            buf.WriteDouble(min);
        if(WriteSelect(8, buf))
            buf.WriteDouble(max);
        if(WriteSelect(9, buf))
            buf.WriteDouble(pointSize);
        if(WriteSelect(10, buf))
            buf.WriteInt(pointType);
        if(WriteSelect(11, buf))
            buf.WriteDouble(skewFactor);
        if(WriteSelect(12, buf))
            buf.WriteDouble(opacity);
        if(WriteSelect(13, buf))
            buf.WriteString(colorTableName);
        if(WriteSelect(14, buf))
            buf.WriteInt(smoothingLevel);
        if(WriteSelect(15, buf))
            buf.WriteBool(pointSizeVarEnabled);
        if(WriteSelect(16, buf))
            buf.WriteString(pointSizeVar);
        if(WriteSelect(17, buf))
            buf.WriteInt(pointSizePixels);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetLegendFlag(buf.ReadBool());
                break;
            case 1:
                SetLightingFlag(buf.ReadBool());
                break;
            case 2:
                SetMinFlag(buf.ReadBool());
                break;
            case 3:
                SetMaxFlag(buf.ReadBool());
                break;
            case 4:
                SetCentering(buf.ReadInt());
                break;
            case 5:
                SetScaling(buf.ReadInt());
                break;
            case 6:
                SetLimitsMode(buf.ReadInt());
                break;
            case 7:
                SetMin(buf.ReadDouble());
                break;
            case 8:
                SetMax(buf.ReadDouble());
                break;
            case 9:
                SetPointSize(buf.ReadDouble());
                break;
            case 10:
                SetPointType(buf.ReadInt());
                break;
            case 11:
                SetSkewFactor(buf.ReadDouble());
                break;
            case 12:
                SetOpacity(buf.ReadDouble());
                break;
            case 13:
                SetColorTableName(buf.ReadString());
                break;
            case 14:
                SetSmoothingLevel(buf.ReadInt());
                break;
            case 15:
                SetPointSizeVarEnabled(buf.ReadBool());
                break;
            case 16:
                SetPointSizeVar(buf.ReadString());
                break;
            case 17:
                SetPointSizePixels(buf.ReadInt());
                break;
            }
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + boolToString("legendFlag", legendFlag, indent) + "\n";
        str = str + boolToString("lightingFlag", lightingFlag, indent) + "\n";
        str = str + boolToString("minFlag", minFlag, indent) + "\n";
        str = str + boolToString("maxFlag", maxFlag, indent) + "\n";
        str = str + indent + "centering = ";
        if(centering == CENTERING_NATURAL)
            str = str + "CENTERING_NATURAL";
        if(centering == CENTERING_NODAL)
            str = str + "CENTERING_NODAL";
        if(centering == CENTERING_ZONAL)
            str = str + "CENTERING_ZONAL";
        str = str + "\n";
        str = str + indent + "scaling = ";
        if(scaling == SCALING_LINEAR)
            str = str + "SCALING_LINEAR";
        if(scaling == SCALING_LOG)
            str = str + "SCALING_LOG";
        if(scaling == SCALING_SKEW)
            str = str + "SCALING_SKEW";
        str = str + "\n";
        str = str + indent + "limitsMode = ";
        if(limitsMode == LIMITSMODE_ORIGINALDATA)
            str = str + "LIMITSMODE_ORIGINALDATA";
        if(limitsMode == LIMITSMODE_CURRENTPLOT)
            str = str + "LIMITSMODE_CURRENTPLOT";
        str = str + "\n";
        str = str + doubleToString("min", min, indent) + "\n";
        str = str + doubleToString("max", max, indent) + "\n";
        str = str + doubleToString("pointSize", pointSize, indent) + "\n";
        str = str + indent + "pointType = ";
        if(pointType == POINTTYPE_BOX)
            str = str + "POINTTYPE_BOX";
        if(pointType == POINTTYPE_AXIS)
            str = str + "POINTTYPE_AXIS";
        if(pointType == POINTTYPE_ICOSAHEDRON)
            str = str + "POINTTYPE_ICOSAHEDRON";
        if(pointType == POINTTYPE_POINT)
            str = str + "POINTTYPE_POINT";
        if(pointType == POINTTYPE_SPHERE)
            str = str + "POINTTYPE_SPHERE";
        str = str + "\n";
        str = str + doubleToString("skewFactor", skewFactor, indent) + "\n";
        str = str + doubleToString("opacity", opacity, indent) + "\n";
        str = str + stringToString("colorTableName", colorTableName, indent) + "\n";
        str = str + intToString("smoothingLevel", smoothingLevel, indent) + "\n";
        str = str + boolToString("pointSizeVarEnabled", pointSizeVarEnabled, indent) + "\n";
        str = str + stringToString("pointSizeVar", pointSizeVar, indent) + "\n";
        str = str + intToString("pointSizePixels", pointSizePixels, indent) + "\n";
        return str;
    }


    // Attributes
    private boolean legendFlag;
    private boolean lightingFlag;
    private boolean minFlag;
    private boolean maxFlag;
    private int     centering;
    private int     scaling;
    private int     limitsMode;
    private double  min;
    private double  max;
    private double  pointSize;
    private int     pointType;
    private double  skewFactor;
    private double  opacity;
    private String  colorTableName;
    private int     smoothingLevel;
    private boolean pointSizeVarEnabled;
    private String  pointSizeVar;
    private int     pointSizePixels;
}

