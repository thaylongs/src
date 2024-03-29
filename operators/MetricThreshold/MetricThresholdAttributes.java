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

package llnl.visit.operators;

import llnl.visit.AttributeSubject;
import llnl.visit.CommunicationBuffer;
import llnl.visit.Plugin;

// ****************************************************************************
// Class: MetricThresholdAttributes
//
// Purpose:
//    This class contains attributes for the MetricThreshold operator.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class MetricThresholdAttributes extends AttributeSubject implements Plugin
{
    private static int MetricThresholdAttributes_numAdditionalAtts = 19;

    // Enum values
    public final static int PRESET_NONE = 0;
    public final static int PRESET_ASPECT_RATIO = 1;
    public final static int PRESET_ASPECT_GAMMA = 2;
    public final static int PRESET_SKEW = 3;
    public final static int PRESET_TAPER = 4;
    public final static int PRESET_VOLUME = 5;
    public final static int PRESET_STRETCH = 6;
    public final static int PRESET_DIAGONAL = 7;
    public final static int PRESET_DIMENSION = 8;
    public final static int PRESET_ODDY = 9;
    public final static int PRESET_CONDITION = 10;
    public final static int PRESET_JACOBIAN = 11;
    public final static int PRESET_SCALED_JACOBIAN = 12;
    public final static int PRESET_SHEAR = 13;
    public final static int PRESET_SHAPE = 14;
    public final static int PRESET_RELATIVE_SIZE = 15;
    public final static int PRESET_SHAPE_AND_SIZE = 16;
    public final static int PRESET_AREA = 17;
    public final static int PRESET_WARPAGE = 18;
    public final static int PRESET_SMALLEST_ANGLE = 19;
    public final static int PRESET_LARGEST_ANGLE = 20;


    public MetricThresholdAttributes()
    {
        super(MetricThresholdAttributes_numAdditionalAtts);

        preset = PRESET_NONE;
        Hexahedron = false;
        hex_lower = 0;
        hex_upper = 0;
        Tetrahedron = false;
        tet_lower = 0;
        tet_upper = 0;
        Wedge = false;
        wed_lower = 0;
        wed_upper = 0;
        Pyramid = false;
        pyr_lower = 0;
        pyr_upper = 0;
        Triangle = false;
        tri_lower = 0;
        tri_upper = 0;
        Quad = false;
        quad_lower = 0;
        quad_upper = 0;
    }

    public MetricThresholdAttributes(int nMoreFields)
    {
        super(MetricThresholdAttributes_numAdditionalAtts + nMoreFields);

        preset = PRESET_NONE;
        Hexahedron = false;
        hex_lower = 0;
        hex_upper = 0;
        Tetrahedron = false;
        tet_lower = 0;
        tet_upper = 0;
        Wedge = false;
        wed_lower = 0;
        wed_upper = 0;
        Pyramid = false;
        pyr_lower = 0;
        pyr_upper = 0;
        Triangle = false;
        tri_lower = 0;
        tri_upper = 0;
        Quad = false;
        quad_lower = 0;
        quad_upper = 0;
    }

    public MetricThresholdAttributes(MetricThresholdAttributes obj)
    {
        super(MetricThresholdAttributes_numAdditionalAtts);

        preset = obj.preset;
        Hexahedron = obj.Hexahedron;
        hex_lower = obj.hex_lower;
        hex_upper = obj.hex_upper;
        Tetrahedron = obj.Tetrahedron;
        tet_lower = obj.tet_lower;
        tet_upper = obj.tet_upper;
        Wedge = obj.Wedge;
        wed_lower = obj.wed_lower;
        wed_upper = obj.wed_upper;
        Pyramid = obj.Pyramid;
        pyr_lower = obj.pyr_lower;
        pyr_upper = obj.pyr_upper;
        Triangle = obj.Triangle;
        tri_lower = obj.tri_lower;
        tri_upper = obj.tri_upper;
        Quad = obj.Quad;
        quad_lower = obj.quad_lower;
        quad_upper = obj.quad_upper;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return MetricThresholdAttributes_numAdditionalAtts;
    }

    public boolean equals(MetricThresholdAttributes obj)
    {
        // Create the return value
        return ((preset == obj.preset) &&
                (Hexahedron == obj.Hexahedron) &&
                (hex_lower == obj.hex_lower) &&
                (hex_upper == obj.hex_upper) &&
                (Tetrahedron == obj.Tetrahedron) &&
                (tet_lower == obj.tet_lower) &&
                (tet_upper == obj.tet_upper) &&
                (Wedge == obj.Wedge) &&
                (wed_lower == obj.wed_lower) &&
                (wed_upper == obj.wed_upper) &&
                (Pyramid == obj.Pyramid) &&
                (pyr_lower == obj.pyr_lower) &&
                (pyr_upper == obj.pyr_upper) &&
                (Triangle == obj.Triangle) &&
                (tri_lower == obj.tri_lower) &&
                (tri_upper == obj.tri_upper) &&
                (Quad == obj.Quad) &&
                (quad_lower == obj.quad_lower) &&
                (quad_upper == obj.quad_upper));
    }

    public String GetName() { return "MetricThreshold"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetPreset(int preset_)
    {
        preset = preset_;
        Select(0);
    }

    public void SetHexahedron(boolean Hexahedron_)
    {
        Hexahedron = Hexahedron_;
        Select(1);
    }

    public void SetHex_lower(double hex_lower_)
    {
        hex_lower = hex_lower_;
        Select(2);
    }

    public void SetHex_upper(double hex_upper_)
    {
        hex_upper = hex_upper_;
        Select(3);
    }

    public void SetTetrahedron(boolean Tetrahedron_)
    {
        Tetrahedron = Tetrahedron_;
        Select(4);
    }

    public void SetTet_lower(double tet_lower_)
    {
        tet_lower = tet_lower_;
        Select(5);
    }

    public void SetTet_upper(double tet_upper_)
    {
        tet_upper = tet_upper_;
        Select(6);
    }

    public void SetWedge(boolean Wedge_)
    {
        Wedge = Wedge_;
        Select(7);
    }

    public void SetWed_lower(double wed_lower_)
    {
        wed_lower = wed_lower_;
        Select(8);
    }

    public void SetWed_upper(double wed_upper_)
    {
        wed_upper = wed_upper_;
        Select(9);
    }

    public void SetPyramid(boolean Pyramid_)
    {
        Pyramid = Pyramid_;
        Select(10);
    }

    public void SetPyr_lower(double pyr_lower_)
    {
        pyr_lower = pyr_lower_;
        Select(11);
    }

    public void SetPyr_upper(double pyr_upper_)
    {
        pyr_upper = pyr_upper_;
        Select(12);
    }

    public void SetTriangle(boolean Triangle_)
    {
        Triangle = Triangle_;
        Select(13);
    }

    public void SetTri_lower(double tri_lower_)
    {
        tri_lower = tri_lower_;
        Select(14);
    }

    public void SetTri_upper(double tri_upper_)
    {
        tri_upper = tri_upper_;
        Select(15);
    }

    public void SetQuad(boolean Quad_)
    {
        Quad = Quad_;
        Select(16);
    }

    public void SetQuad_lower(double quad_lower_)
    {
        quad_lower = quad_lower_;
        Select(17);
    }

    public void SetQuad_upper(double quad_upper_)
    {
        quad_upper = quad_upper_;
        Select(18);
    }

    // Property getting methods
    public int     GetPreset() { return preset; }
    public boolean GetHexahedron() { return Hexahedron; }
    public double  GetHex_lower() { return hex_lower; }
    public double  GetHex_upper() { return hex_upper; }
    public boolean GetTetrahedron() { return Tetrahedron; }
    public double  GetTet_lower() { return tet_lower; }
    public double  GetTet_upper() { return tet_upper; }
    public boolean GetWedge() { return Wedge; }
    public double  GetWed_lower() { return wed_lower; }
    public double  GetWed_upper() { return wed_upper; }
    public boolean GetPyramid() { return Pyramid; }
    public double  GetPyr_lower() { return pyr_lower; }
    public double  GetPyr_upper() { return pyr_upper; }
    public boolean GetTriangle() { return Triangle; }
    public double  GetTri_lower() { return tri_lower; }
    public double  GetTri_upper() { return tri_upper; }
    public boolean GetQuad() { return Quad; }
    public double  GetQuad_lower() { return quad_lower; }
    public double  GetQuad_upper() { return quad_upper; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteInt(preset);
        if(WriteSelect(1, buf))
            buf.WriteBool(Hexahedron);
        if(WriteSelect(2, buf))
            buf.WriteDouble(hex_lower);
        if(WriteSelect(3, buf))
            buf.WriteDouble(hex_upper);
        if(WriteSelect(4, buf))
            buf.WriteBool(Tetrahedron);
        if(WriteSelect(5, buf))
            buf.WriteDouble(tet_lower);
        if(WriteSelect(6, buf))
            buf.WriteDouble(tet_upper);
        if(WriteSelect(7, buf))
            buf.WriteBool(Wedge);
        if(WriteSelect(8, buf))
            buf.WriteDouble(wed_lower);
        if(WriteSelect(9, buf))
            buf.WriteDouble(wed_upper);
        if(WriteSelect(10, buf))
            buf.WriteBool(Pyramid);
        if(WriteSelect(11, buf))
            buf.WriteDouble(pyr_lower);
        if(WriteSelect(12, buf))
            buf.WriteDouble(pyr_upper);
        if(WriteSelect(13, buf))
            buf.WriteBool(Triangle);
        if(WriteSelect(14, buf))
            buf.WriteDouble(tri_lower);
        if(WriteSelect(15, buf))
            buf.WriteDouble(tri_upper);
        if(WriteSelect(16, buf))
            buf.WriteBool(Quad);
        if(WriteSelect(17, buf))
            buf.WriteDouble(quad_lower);
        if(WriteSelect(18, buf))
            buf.WriteDouble(quad_upper);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetPreset(buf.ReadInt());
            break;
        case 1:
            SetHexahedron(buf.ReadBool());
            break;
        case 2:
            SetHex_lower(buf.ReadDouble());
            break;
        case 3:
            SetHex_upper(buf.ReadDouble());
            break;
        case 4:
            SetTetrahedron(buf.ReadBool());
            break;
        case 5:
            SetTet_lower(buf.ReadDouble());
            break;
        case 6:
            SetTet_upper(buf.ReadDouble());
            break;
        case 7:
            SetWedge(buf.ReadBool());
            break;
        case 8:
            SetWed_lower(buf.ReadDouble());
            break;
        case 9:
            SetWed_upper(buf.ReadDouble());
            break;
        case 10:
            SetPyramid(buf.ReadBool());
            break;
        case 11:
            SetPyr_lower(buf.ReadDouble());
            break;
        case 12:
            SetPyr_upper(buf.ReadDouble());
            break;
        case 13:
            SetTriangle(buf.ReadBool());
            break;
        case 14:
            SetTri_lower(buf.ReadDouble());
            break;
        case 15:
            SetTri_upper(buf.ReadDouble());
            break;
        case 16:
            SetQuad(buf.ReadBool());
            break;
        case 17:
            SetQuad_lower(buf.ReadDouble());
            break;
        case 18:
            SetQuad_upper(buf.ReadDouble());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "preset = ";
        if(preset == PRESET_NONE)
            str = str + "PRESET_NONE";
        if(preset == PRESET_ASPECT_RATIO)
            str = str + "PRESET_ASPECT_RATIO";
        if(preset == PRESET_ASPECT_GAMMA)
            str = str + "PRESET_ASPECT_GAMMA";
        if(preset == PRESET_SKEW)
            str = str + "PRESET_SKEW";
        if(preset == PRESET_TAPER)
            str = str + "PRESET_TAPER";
        if(preset == PRESET_VOLUME)
            str = str + "PRESET_VOLUME";
        if(preset == PRESET_STRETCH)
            str = str + "PRESET_STRETCH";
        if(preset == PRESET_DIAGONAL)
            str = str + "PRESET_DIAGONAL";
        if(preset == PRESET_DIMENSION)
            str = str + "PRESET_DIMENSION";
        if(preset == PRESET_ODDY)
            str = str + "PRESET_ODDY";
        if(preset == PRESET_CONDITION)
            str = str + "PRESET_CONDITION";
        if(preset == PRESET_JACOBIAN)
            str = str + "PRESET_JACOBIAN";
        if(preset == PRESET_SCALED_JACOBIAN)
            str = str + "PRESET_SCALED_JACOBIAN";
        if(preset == PRESET_SHEAR)
            str = str + "PRESET_SHEAR";
        if(preset == PRESET_SHAPE)
            str = str + "PRESET_SHAPE";
        if(preset == PRESET_RELATIVE_SIZE)
            str = str + "PRESET_RELATIVE_SIZE";
        if(preset == PRESET_SHAPE_AND_SIZE)
            str = str + "PRESET_SHAPE_AND_SIZE";
        if(preset == PRESET_AREA)
            str = str + "PRESET_AREA";
        if(preset == PRESET_WARPAGE)
            str = str + "PRESET_WARPAGE";
        if(preset == PRESET_SMALLEST_ANGLE)
            str = str + "PRESET_SMALLEST_ANGLE";
        if(preset == PRESET_LARGEST_ANGLE)
            str = str + "PRESET_LARGEST_ANGLE";
        str = str + "\n";
        str = str + boolToString("Hexahedron", Hexahedron, indent) + "\n";
        str = str + doubleToString("hex_lower", hex_lower, indent) + "\n";
        str = str + doubleToString("hex_upper", hex_upper, indent) + "\n";
        str = str + boolToString("Tetrahedron", Tetrahedron, indent) + "\n";
        str = str + doubleToString("tet_lower", tet_lower, indent) + "\n";
        str = str + doubleToString("tet_upper", tet_upper, indent) + "\n";
        str = str + boolToString("Wedge", Wedge, indent) + "\n";
        str = str + doubleToString("wed_lower", wed_lower, indent) + "\n";
        str = str + doubleToString("wed_upper", wed_upper, indent) + "\n";
        str = str + boolToString("Pyramid", Pyramid, indent) + "\n";
        str = str + doubleToString("pyr_lower", pyr_lower, indent) + "\n";
        str = str + doubleToString("pyr_upper", pyr_upper, indent) + "\n";
        str = str + boolToString("Triangle", Triangle, indent) + "\n";
        str = str + doubleToString("tri_lower", tri_lower, indent) + "\n";
        str = str + doubleToString("tri_upper", tri_upper, indent) + "\n";
        str = str + boolToString("Quad", Quad, indent) + "\n";
        str = str + doubleToString("quad_lower", quad_lower, indent) + "\n";
        str = str + doubleToString("quad_upper", quad_upper, indent) + "\n";
        return str;
    }


    // Attributes
    private int     preset;
    private boolean Hexahedron;
    private double  hex_lower;
    private double  hex_upper;
    private boolean Tetrahedron;
    private double  tet_lower;
    private double  tet_upper;
    private boolean Wedge;
    private double  wed_lower;
    private double  wed_upper;
    private boolean Pyramid;
    private double  pyr_lower;
    private double  pyr_upper;
    private boolean Triangle;
    private double  tri_lower;
    private double  tri_upper;
    private boolean Quad;
    private double  quad_lower;
    private double  quad_upper;
}

