// ***************************************************************************
//
// Copyright (c) 2000 - 2010, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory
// LLNL-CODE-400124
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
// Class: avtCurveMetaData
//
// Purpose:
//    Contains curve metadata attributes
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class avtCurveMetaData extends avtVarMetaData
{
    private static int avtCurveMetaData_numAdditionalAtts = 8;

    public avtCurveMetaData()
    {
        super(avtCurveMetaData_numAdditionalAtts);

        xUnits = new String("");
        xLabel = new String("X-Axis");
        yUnits = new String("");
        yLabel = new String("Y-Axis");
        hasSpatialExtents = false;
        minSpatialExtents = 0;
        maxSpatialExtents = 0;
        from1DScalarName = new String("");
    }

    public avtCurveMetaData(int nMoreFields)
    {
        super(avtCurveMetaData_numAdditionalAtts + nMoreFields);

        xUnits = new String("");
        xLabel = new String("X-Axis");
        yUnits = new String("");
        yLabel = new String("Y-Axis");
        hasSpatialExtents = false;
        minSpatialExtents = 0;
        maxSpatialExtents = 0;
        from1DScalarName = new String("");
    }

    public avtCurveMetaData(avtCurveMetaData obj)
    {
        super(avtCurveMetaData_numAdditionalAtts);

        xUnits = new String(obj.xUnits);
        xLabel = new String(obj.xLabel);
        yUnits = new String(obj.yUnits);
        yLabel = new String(obj.yLabel);
        hasSpatialExtents = obj.hasSpatialExtents;
        minSpatialExtents = obj.minSpatialExtents;
        maxSpatialExtents = obj.maxSpatialExtents;
        from1DScalarName = new String(obj.from1DScalarName);

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return avtCurveMetaData_numAdditionalAtts;
    }

    public boolean equals(avtCurveMetaData obj)
    {
        // Create the return value
        return (super.equals(obj) && (xUnits.equals(obj.xUnits)) &&
                (xLabel.equals(obj.xLabel)) &&
                (yUnits.equals(obj.yUnits)) &&
                (yLabel.equals(obj.yLabel)) &&
                (hasSpatialExtents == obj.hasSpatialExtents) &&
                (minSpatialExtents == obj.minSpatialExtents) &&
                (maxSpatialExtents == obj.maxSpatialExtents) &&
                (from1DScalarName.equals(obj.from1DScalarName)));
    }

    // Property setting methods
    public void SetXUnits(String xUnits_)
    {
        xUnits = xUnits_;
        Select((new avtCurveMetaData()).Offset() + 0);
    }

    public void SetXLabel(String xLabel_)
    {
        xLabel = xLabel_;
        Select((new avtCurveMetaData()).Offset() + 1);
    }

    public void SetYUnits(String yUnits_)
    {
        yUnits = yUnits_;
        Select((new avtCurveMetaData()).Offset() + 2);
    }

    public void SetYLabel(String yLabel_)
    {
        yLabel = yLabel_;
        Select((new avtCurveMetaData()).Offset() + 3);
    }

    public void SetHasSpatialExtents(boolean hasSpatialExtents_)
    {
        hasSpatialExtents = hasSpatialExtents_;
        Select((new avtCurveMetaData()).Offset() + 4);
    }

    public void SetMinSpatialExtents(double minSpatialExtents_)
    {
        minSpatialExtents = minSpatialExtents_;
        Select((new avtCurveMetaData()).Offset() + 5);
    }

    public void SetMaxSpatialExtents(double maxSpatialExtents_)
    {
        maxSpatialExtents = maxSpatialExtents_;
        Select((new avtCurveMetaData()).Offset() + 6);
    }

    public void SetFrom1DScalarName(String from1DScalarName_)
    {
        from1DScalarName = from1DScalarName_;
        Select((new avtCurveMetaData()).Offset() + 7);
    }

    // Property getting methods
    public String  GetXUnits() { return xUnits; }
    public String  GetXLabel() { return xLabel; }
    public String  GetYUnits() { return yUnits; }
    public String  GetYLabel() { return yLabel; }
    public boolean GetHasSpatialExtents() { return hasSpatialExtents; }
    public double  GetMinSpatialExtents() { return minSpatialExtents; }
    public double  GetMaxSpatialExtents() { return maxSpatialExtents; }
    public String  GetFrom1DScalarName() { return from1DScalarName; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        super.WriteAtts(buf);

        int offset = (new avtCurveMetaData()).Offset();
        if(WriteSelect(offset + 0, buf))
            buf.WriteString(xUnits);
        if(WriteSelect(offset + 1, buf))
            buf.WriteString(xLabel);
        if(WriteSelect(offset + 2, buf))
            buf.WriteString(yUnits);
        if(WriteSelect(offset + 3, buf))
            buf.WriteString(yLabel);
        if(WriteSelect(offset + 4, buf))
            buf.WriteBool(hasSpatialExtents);
        if(WriteSelect(offset + 5, buf))
            buf.WriteDouble(minSpatialExtents);
        if(WriteSelect(offset + 6, buf))
            buf.WriteDouble(maxSpatialExtents);
        if(WriteSelect(offset + 7, buf))
            buf.WriteString(from1DScalarName);
    }

    public void ReadAtts(int id, CommunicationBuffer buf)
    {
        int offset = (new avtCurveMetaData()).Offset();
        int index = id - offset;
        switch(index)
        {
        case 0:
            SetXUnits(buf.ReadString());
            break;
        case 1:
            SetXLabel(buf.ReadString());
            break;
        case 2:
            SetYUnits(buf.ReadString());
            break;
        case 3:
            SetYLabel(buf.ReadString());
            break;
        case 4:
            SetHasSpatialExtents(buf.ReadBool());
            break;
        case 5:
            SetMinSpatialExtents(buf.ReadDouble());
            break;
        case 6:
            SetMaxSpatialExtents(buf.ReadDouble());
            break;
        case 7:
            SetFrom1DScalarName(buf.ReadString());
            break;
        default:
            super.ReadAtts(id, buf);
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + stringToString("xUnits", xUnits, indent) + "\n";
        str = str + stringToString("xLabel", xLabel, indent) + "\n";
        str = str + stringToString("yUnits", yUnits, indent) + "\n";
        str = str + stringToString("yLabel", yLabel, indent) + "\n";
        str = str + boolToString("hasSpatialExtents", hasSpatialExtents, indent) + "\n";
        str = str + doubleToString("minSpatialExtents", minSpatialExtents, indent) + "\n";
        str = str + doubleToString("maxSpatialExtents", maxSpatialExtents, indent) + "\n";
        str = str + stringToString("from1DScalarName", from1DScalarName, indent) + "\n";
        return super.toString(indent) + str;
    }


    // Attributes
    private String  xUnits;
    private String  xLabel;
    private String  yUnits;
    private String  yLabel;
    private boolean hasSpatialExtents;
    private double  minSpatialExtents;
    private double  maxSpatialExtents;
    private String  from1DScalarName;
}

