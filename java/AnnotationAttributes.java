// ***************************************************************************
//
// Copyright (c) 2000 - 2016, Lawrence Livermore National Security, LLC
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

package llnl.visit;


// ****************************************************************************
// Class: AnnotationAttributes
//
// Purpose:
//    This class contains the attributes controlling annotations.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class AnnotationAttributes extends AttributeSubject
{
    private static int AnnotationAttributes_numAdditionalAtts = 21;

    // Enum values
    public final static int GRADIENTSTYLE_TOPTOBOTTOM = 0;
    public final static int GRADIENTSTYLE_BOTTOMTOTOP = 1;
    public final static int GRADIENTSTYLE_LEFTTORIGHT = 2;
    public final static int GRADIENTSTYLE_RIGHTTOLEFT = 3;
    public final static int GRADIENTSTYLE_RADIAL = 4;

    public final static int BACKGROUNDMODE_SOLID = 0;
    public final static int BACKGROUNDMODE_GRADIENT = 1;
    public final static int BACKGROUNDMODE_IMAGE = 2;
    public final static int BACKGROUNDMODE_IMAGESPHERE = 3;

    public final static int PATHEXPANSIONMODE_FILE = 0;
    public final static int PATHEXPANSIONMODE_DIRECTORY = 1;
    public final static int PATHEXPANSIONMODE_FULL = 2;
    public final static int PATHEXPANSIONMODE_SMART = 3;
    public final static int PATHEXPANSIONMODE_SMARTDIRECTORY = 4;


    public AnnotationAttributes()
    {
        super(AnnotationAttributes_numAdditionalAtts);

        axes2D = new Axes2D();
        axes3D = new Axes3D();
        userInfoFlag = true;
        userInfoFont = new FontAttributes();
        databaseInfoFlag = true;
        timeInfoFlag = true;
        databaseInfoFont = new FontAttributes();
        databaseInfoExpansionMode = PATHEXPANSIONMODE_FILE;
        databaseInfoTimeScale = 1;
        databaseInfoTimeOffset = 0;
        legendInfoFlag = true;
        backgroundColor = new ColorAttribute(255, 255, 255);
        foregroundColor = new ColorAttribute(0, 0, 0);
        gradientBackgroundStyle = GRADIENTSTYLE_RADIAL;
        gradientColor1 = new ColorAttribute(0, 0, 255);
        gradientColor2 = new ColorAttribute(0, 0, 0);
        backgroundMode = BACKGROUNDMODE_SOLID;
        backgroundImage = new String("");
        imageRepeatX = 1;
        imageRepeatY = 1;
        axesArray = new AxesArray();
    }

    public AnnotationAttributes(int nMoreFields)
    {
        super(AnnotationAttributes_numAdditionalAtts + nMoreFields);

        axes2D = new Axes2D();
        axes3D = new Axes3D();
        userInfoFlag = true;
        userInfoFont = new FontAttributes();
        databaseInfoFlag = true;
        timeInfoFlag = true;
        databaseInfoFont = new FontAttributes();
        databaseInfoExpansionMode = PATHEXPANSIONMODE_FILE;
        databaseInfoTimeScale = 1;
        databaseInfoTimeOffset = 0;
        legendInfoFlag = true;
        backgroundColor = new ColorAttribute(255, 255, 255);
        foregroundColor = new ColorAttribute(0, 0, 0);
        gradientBackgroundStyle = GRADIENTSTYLE_RADIAL;
        gradientColor1 = new ColorAttribute(0, 0, 255);
        gradientColor2 = new ColorAttribute(0, 0, 0);
        backgroundMode = BACKGROUNDMODE_SOLID;
        backgroundImage = new String("");
        imageRepeatX = 1;
        imageRepeatY = 1;
        axesArray = new AxesArray();
    }

    public AnnotationAttributes(AnnotationAttributes obj)
    {
        super(AnnotationAttributes_numAdditionalAtts);

        axes2D = new Axes2D(obj.axes2D);
        axes3D = new Axes3D(obj.axes3D);
        userInfoFlag = obj.userInfoFlag;
        userInfoFont = new FontAttributes(obj.userInfoFont);
        databaseInfoFlag = obj.databaseInfoFlag;
        timeInfoFlag = obj.timeInfoFlag;
        databaseInfoFont = new FontAttributes(obj.databaseInfoFont);
        databaseInfoExpansionMode = obj.databaseInfoExpansionMode;
        databaseInfoTimeScale = obj.databaseInfoTimeScale;
        databaseInfoTimeOffset = obj.databaseInfoTimeOffset;
        legendInfoFlag = obj.legendInfoFlag;
        backgroundColor = new ColorAttribute(obj.backgroundColor);
        foregroundColor = new ColorAttribute(obj.foregroundColor);
        gradientBackgroundStyle = obj.gradientBackgroundStyle;
        gradientColor1 = new ColorAttribute(obj.gradientColor1);
        gradientColor2 = new ColorAttribute(obj.gradientColor2);
        backgroundMode = obj.backgroundMode;
        backgroundImage = new String(obj.backgroundImage);
        imageRepeatX = obj.imageRepeatX;
        imageRepeatY = obj.imageRepeatY;
        axesArray = new AxesArray(obj.axesArray);

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return AnnotationAttributes_numAdditionalAtts;
    }

    public boolean equals(AnnotationAttributes obj)
    {
        // Create the return value
        return ((axes2D.equals(obj.axes2D)) &&
                (axes3D.equals(obj.axes3D)) &&
                (userInfoFlag == obj.userInfoFlag) &&
                (userInfoFont.equals(obj.userInfoFont)) &&
                (databaseInfoFlag == obj.databaseInfoFlag) &&
                (timeInfoFlag == obj.timeInfoFlag) &&
                (databaseInfoFont.equals(obj.databaseInfoFont)) &&
                (databaseInfoExpansionMode == obj.databaseInfoExpansionMode) &&
                (databaseInfoTimeScale == obj.databaseInfoTimeScale) &&
                (databaseInfoTimeOffset == obj.databaseInfoTimeOffset) &&
                (legendInfoFlag == obj.legendInfoFlag) &&
                (backgroundColor == obj.backgroundColor) &&
                (foregroundColor == obj.foregroundColor) &&
                (gradientBackgroundStyle == obj.gradientBackgroundStyle) &&
                (gradientColor1 == obj.gradientColor1) &&
                (gradientColor2 == obj.gradientColor2) &&
                (backgroundMode == obj.backgroundMode) &&
                (backgroundImage.equals(obj.backgroundImage)) &&
                (imageRepeatX == obj.imageRepeatX) &&
                (imageRepeatY == obj.imageRepeatY) &&
                (axesArray.equals(obj.axesArray)));
    }

    // Property setting methods
    public void SetAxes2D(Axes2D axes2D_)
    {
        axes2D = axes2D_;
        Select(0);
    }

    public void SetAxes3D(Axes3D axes3D_)
    {
        axes3D = axes3D_;
        Select(1);
    }

    public void SetUserInfoFlag(boolean userInfoFlag_)
    {
        userInfoFlag = userInfoFlag_;
        Select(2);
    }

    public void SetUserInfoFont(FontAttributes userInfoFont_)
    {
        userInfoFont = userInfoFont_;
        Select(3);
    }

    public void SetDatabaseInfoFlag(boolean databaseInfoFlag_)
    {
        databaseInfoFlag = databaseInfoFlag_;
        Select(4);
    }

    public void SetTimeInfoFlag(boolean timeInfoFlag_)
    {
        timeInfoFlag = timeInfoFlag_;
        Select(5);
    }

    public void SetDatabaseInfoFont(FontAttributes databaseInfoFont_)
    {
        databaseInfoFont = databaseInfoFont_;
        Select(6);
    }

    public void SetDatabaseInfoExpansionMode(int databaseInfoExpansionMode_)
    {
        databaseInfoExpansionMode = databaseInfoExpansionMode_;
        Select(7);
    }

    public void SetDatabaseInfoTimeScale(double databaseInfoTimeScale_)
    {
        databaseInfoTimeScale = databaseInfoTimeScale_;
        Select(8);
    }

    public void SetDatabaseInfoTimeOffset(double databaseInfoTimeOffset_)
    {
        databaseInfoTimeOffset = databaseInfoTimeOffset_;
        Select(9);
    }

    public void SetLegendInfoFlag(boolean legendInfoFlag_)
    {
        legendInfoFlag = legendInfoFlag_;
        Select(10);
    }

    public void SetBackgroundColor(ColorAttribute backgroundColor_)
    {
        backgroundColor = backgroundColor_;
        Select(11);
    }

    public void SetForegroundColor(ColorAttribute foregroundColor_)
    {
        foregroundColor = foregroundColor_;
        Select(12);
    }

    public void SetGradientBackgroundStyle(int gradientBackgroundStyle_)
    {
        gradientBackgroundStyle = gradientBackgroundStyle_;
        Select(13);
    }

    public void SetGradientColor1(ColorAttribute gradientColor1_)
    {
        gradientColor1 = gradientColor1_;
        Select(14);
    }

    public void SetGradientColor2(ColorAttribute gradientColor2_)
    {
        gradientColor2 = gradientColor2_;
        Select(15);
    }

    public void SetBackgroundMode(int backgroundMode_)
    {
        backgroundMode = backgroundMode_;
        Select(16);
    }

    public void SetBackgroundImage(String backgroundImage_)
    {
        backgroundImage = backgroundImage_;
        Select(17);
    }

    public void SetImageRepeatX(int imageRepeatX_)
    {
        imageRepeatX = imageRepeatX_;
        Select(18);
    }

    public void SetImageRepeatY(int imageRepeatY_)
    {
        imageRepeatY = imageRepeatY_;
        Select(19);
    }

    public void SetAxesArray(AxesArray axesArray_)
    {
        axesArray = axesArray_;
        Select(20);
    }

    // Property getting methods
    public Axes2D         GetAxes2D() { return axes2D; }
    public Axes3D         GetAxes3D() { return axes3D; }
    public boolean        GetUserInfoFlag() { return userInfoFlag; }
    public FontAttributes GetUserInfoFont() { return userInfoFont; }
    public boolean        GetDatabaseInfoFlag() { return databaseInfoFlag; }
    public boolean        GetTimeInfoFlag() { return timeInfoFlag; }
    public FontAttributes GetDatabaseInfoFont() { return databaseInfoFont; }
    public int            GetDatabaseInfoExpansionMode() { return databaseInfoExpansionMode; }
    public double         GetDatabaseInfoTimeScale() { return databaseInfoTimeScale; }
    public double         GetDatabaseInfoTimeOffset() { return databaseInfoTimeOffset; }
    public boolean        GetLegendInfoFlag() { return legendInfoFlag; }
    public ColorAttribute GetBackgroundColor() { return backgroundColor; }
    public ColorAttribute GetForegroundColor() { return foregroundColor; }
    public int            GetGradientBackgroundStyle() { return gradientBackgroundStyle; }
    public ColorAttribute GetGradientColor1() { return gradientColor1; }
    public ColorAttribute GetGradientColor2() { return gradientColor2; }
    public int            GetBackgroundMode() { return backgroundMode; }
    public String         GetBackgroundImage() { return backgroundImage; }
    public int            GetImageRepeatX() { return imageRepeatX; }
    public int            GetImageRepeatY() { return imageRepeatY; }
    public AxesArray      GetAxesArray() { return axesArray; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            axes2D.Write(buf);
        if(WriteSelect(1, buf))
            axes3D.Write(buf);
        if(WriteSelect(2, buf))
            buf.WriteBool(userInfoFlag);
        if(WriteSelect(3, buf))
            userInfoFont.Write(buf);
        if(WriteSelect(4, buf))
            buf.WriteBool(databaseInfoFlag);
        if(WriteSelect(5, buf))
            buf.WriteBool(timeInfoFlag);
        if(WriteSelect(6, buf))
            databaseInfoFont.Write(buf);
        if(WriteSelect(7, buf))
            buf.WriteInt(databaseInfoExpansionMode);
        if(WriteSelect(8, buf))
            buf.WriteDouble(databaseInfoTimeScale);
        if(WriteSelect(9, buf))
            buf.WriteDouble(databaseInfoTimeOffset);
        if(WriteSelect(10, buf))
            buf.WriteBool(legendInfoFlag);
        if(WriteSelect(11, buf))
            backgroundColor.Write(buf);
        if(WriteSelect(12, buf))
            foregroundColor.Write(buf);
        if(WriteSelect(13, buf))
            buf.WriteInt(gradientBackgroundStyle);
        if(WriteSelect(14, buf))
            gradientColor1.Write(buf);
        if(WriteSelect(15, buf))
            gradientColor2.Write(buf);
        if(WriteSelect(16, buf))
            buf.WriteInt(backgroundMode);
        if(WriteSelect(17, buf))
            buf.WriteString(backgroundImage);
        if(WriteSelect(18, buf))
            buf.WriteInt(imageRepeatX);
        if(WriteSelect(19, buf))
            buf.WriteInt(imageRepeatY);
        if(WriteSelect(20, buf))
            axesArray.Write(buf);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            axes2D.Read(buf);
            Select(0);
            break;
        case 1:
            axes3D.Read(buf);
            Select(1);
            break;
        case 2:
            SetUserInfoFlag(buf.ReadBool());
            break;
        case 3:
            userInfoFont.Read(buf);
            Select(3);
            break;
        case 4:
            SetDatabaseInfoFlag(buf.ReadBool());
            break;
        case 5:
            SetTimeInfoFlag(buf.ReadBool());
            break;
        case 6:
            databaseInfoFont.Read(buf);
            Select(6);
            break;
        case 7:
            SetDatabaseInfoExpansionMode(buf.ReadInt());
            break;
        case 8:
            SetDatabaseInfoTimeScale(buf.ReadDouble());
            break;
        case 9:
            SetDatabaseInfoTimeOffset(buf.ReadDouble());
            break;
        case 10:
            SetLegendInfoFlag(buf.ReadBool());
            break;
        case 11:
            backgroundColor.Read(buf);
            Select(11);
            break;
        case 12:
            foregroundColor.Read(buf);
            Select(12);
            break;
        case 13:
            SetGradientBackgroundStyle(buf.ReadInt());
            break;
        case 14:
            gradientColor1.Read(buf);
            Select(14);
            break;
        case 15:
            gradientColor2.Read(buf);
            Select(15);
            break;
        case 16:
            SetBackgroundMode(buf.ReadInt());
            break;
        case 17:
            SetBackgroundImage(buf.ReadString());
            break;
        case 18:
            SetImageRepeatX(buf.ReadInt());
            break;
        case 19:
            SetImageRepeatY(buf.ReadInt());
            break;
        case 20:
            axesArray.Read(buf);
            Select(20);
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "axes2D = {\n" + axes2D.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "axes3D = {\n" + axes3D.toString(indent + "    ") + indent + "}\n";
        str = str + boolToString("userInfoFlag", userInfoFlag, indent) + "\n";
        str = str + indent + "userInfoFont = {\n" + userInfoFont.toString(indent + "    ") + indent + "}\n";
        str = str + boolToString("databaseInfoFlag", databaseInfoFlag, indent) + "\n";
        str = str + boolToString("timeInfoFlag", timeInfoFlag, indent) + "\n";
        str = str + indent + "databaseInfoFont = {\n" + databaseInfoFont.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "databaseInfoExpansionMode = ";
        if(databaseInfoExpansionMode == PATHEXPANSIONMODE_FILE)
            str = str + "PATHEXPANSIONMODE_FILE";
        if(databaseInfoExpansionMode == PATHEXPANSIONMODE_DIRECTORY)
            str = str + "PATHEXPANSIONMODE_DIRECTORY";
        if(databaseInfoExpansionMode == PATHEXPANSIONMODE_FULL)
            str = str + "PATHEXPANSIONMODE_FULL";
        if(databaseInfoExpansionMode == PATHEXPANSIONMODE_SMART)
            str = str + "PATHEXPANSIONMODE_SMART";
        if(databaseInfoExpansionMode == PATHEXPANSIONMODE_SMARTDIRECTORY)
            str = str + "PATHEXPANSIONMODE_SMARTDIRECTORY";
        str = str + "\n";
        str = str + doubleToString("databaseInfoTimeScale", databaseInfoTimeScale, indent) + "\n";
        str = str + doubleToString("databaseInfoTimeOffset", databaseInfoTimeOffset, indent) + "\n";
        str = str + boolToString("legendInfoFlag", legendInfoFlag, indent) + "\n";
        str = str + indent + "backgroundColor = {" + backgroundColor.Red() + ", " + backgroundColor.Green() + ", " + backgroundColor.Blue() + ", " + backgroundColor.Alpha() + "}\n";
        str = str + indent + "foregroundColor = {" + foregroundColor.Red() + ", " + foregroundColor.Green() + ", " + foregroundColor.Blue() + ", " + foregroundColor.Alpha() + "}\n";
        str = str + indent + "gradientBackgroundStyle = ";
        if(gradientBackgroundStyle == GRADIENTSTYLE_TOPTOBOTTOM)
            str = str + "GRADIENTSTYLE_TOPTOBOTTOM";
        if(gradientBackgroundStyle == GRADIENTSTYLE_BOTTOMTOTOP)
            str = str + "GRADIENTSTYLE_BOTTOMTOTOP";
        if(gradientBackgroundStyle == GRADIENTSTYLE_LEFTTORIGHT)
            str = str + "GRADIENTSTYLE_LEFTTORIGHT";
        if(gradientBackgroundStyle == GRADIENTSTYLE_RIGHTTOLEFT)
            str = str + "GRADIENTSTYLE_RIGHTTOLEFT";
        if(gradientBackgroundStyle == GRADIENTSTYLE_RADIAL)
            str = str + "GRADIENTSTYLE_RADIAL";
        str = str + "\n";
        str = str + indent + "gradientColor1 = {" + gradientColor1.Red() + ", " + gradientColor1.Green() + ", " + gradientColor1.Blue() + ", " + gradientColor1.Alpha() + "}\n";
        str = str + indent + "gradientColor2 = {" + gradientColor2.Red() + ", " + gradientColor2.Green() + ", " + gradientColor2.Blue() + ", " + gradientColor2.Alpha() + "}\n";
        str = str + indent + "backgroundMode = ";
        if(backgroundMode == BACKGROUNDMODE_SOLID)
            str = str + "BACKGROUNDMODE_SOLID";
        if(backgroundMode == BACKGROUNDMODE_GRADIENT)
            str = str + "BACKGROUNDMODE_GRADIENT";
        if(backgroundMode == BACKGROUNDMODE_IMAGE)
            str = str + "BACKGROUNDMODE_IMAGE";
        if(backgroundMode == BACKGROUNDMODE_IMAGESPHERE)
            str = str + "BACKGROUNDMODE_IMAGESPHERE";
        str = str + "\n";
        str = str + stringToString("backgroundImage", backgroundImage, indent) + "\n";
        str = str + intToString("imageRepeatX", imageRepeatX, indent) + "\n";
        str = str + intToString("imageRepeatY", imageRepeatY, indent) + "\n";
        str = str + indent + "axesArray = {\n" + axesArray.toString(indent + "    ") + indent + "}\n";
        return str;
    }


    // Attributes
    private Axes2D         axes2D;
    private Axes3D         axes3D;
    private boolean        userInfoFlag;
    private FontAttributes userInfoFont;
    private boolean        databaseInfoFlag;
    private boolean        timeInfoFlag;
    private FontAttributes databaseInfoFont;
    private int            databaseInfoExpansionMode;
    private double         databaseInfoTimeScale;
    private double         databaseInfoTimeOffset;
    private boolean        legendInfoFlag;
    private ColorAttribute backgroundColor;
    private ColorAttribute foregroundColor;
    private int            gradientBackgroundStyle;
    private ColorAttribute gradientColor1;
    private ColorAttribute gradientColor2;
    private int            backgroundMode;
    private String         backgroundImage;
    private int            imageRepeatX;
    private int            imageRepeatY;
    private AxesArray      axesArray;
}

