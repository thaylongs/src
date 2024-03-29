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
// Class: ResampleAttributes
//
// Purpose:
//    Atts for Resample operator
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class ResampleAttributes extends AttributeSubject implements Plugin
{
    private static int ResampleAttributes_numAdditionalAtts = 16;

    // Enum values
    public final static int TIERESOLVER_RANDOM = 0;
    public final static int TIERESOLVER_LARGEST = 1;
    public final static int TIERESOLVER_SMALLEST = 2;


    public ResampleAttributes()
    {
        super(ResampleAttributes_numAdditionalAtts);

        useExtents = true;
        startX = 0;
        endX = 1;
        samplesX = 10;
        startY = 0;
        endY = 1;
        samplesY = 10;
        is3D = true;
        startZ = 0;
        endZ = 1;
        samplesZ = 10;
        tieResolver = TIERESOLVER_RANDOM;
        tieResolverVariable = new String("default");
        defaultValue = 0;
        distributedResample = true;
        cellCenteredOutput = false;
    }

    public ResampleAttributes(int nMoreFields)
    {
        super(ResampleAttributes_numAdditionalAtts + nMoreFields);

        useExtents = true;
        startX = 0;
        endX = 1;
        samplesX = 10;
        startY = 0;
        endY = 1;
        samplesY = 10;
        is3D = true;
        startZ = 0;
        endZ = 1;
        samplesZ = 10;
        tieResolver = TIERESOLVER_RANDOM;
        tieResolverVariable = new String("default");
        defaultValue = 0;
        distributedResample = true;
        cellCenteredOutput = false;
    }

    public ResampleAttributes(ResampleAttributes obj)
    {
        super(ResampleAttributes_numAdditionalAtts);

        useExtents = obj.useExtents;
        startX = obj.startX;
        endX = obj.endX;
        samplesX = obj.samplesX;
        startY = obj.startY;
        endY = obj.endY;
        samplesY = obj.samplesY;
        is3D = obj.is3D;
        startZ = obj.startZ;
        endZ = obj.endZ;
        samplesZ = obj.samplesZ;
        tieResolver = obj.tieResolver;
        tieResolverVariable = new String(obj.tieResolverVariable);
        defaultValue = obj.defaultValue;
        distributedResample = obj.distributedResample;
        cellCenteredOutput = obj.cellCenteredOutput;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return ResampleAttributes_numAdditionalAtts;
    }

    public boolean equals(ResampleAttributes obj)
    {
        // Create the return value
        return ((useExtents == obj.useExtents) &&
                (startX == obj.startX) &&
                (endX == obj.endX) &&
                (samplesX == obj.samplesX) &&
                (startY == obj.startY) &&
                (endY == obj.endY) &&
                (samplesY == obj.samplesY) &&
                (is3D == obj.is3D) &&
                (startZ == obj.startZ) &&
                (endZ == obj.endZ) &&
                (samplesZ == obj.samplesZ) &&
                (tieResolver == obj.tieResolver) &&
                (tieResolverVariable.equals(obj.tieResolverVariable)) &&
                (defaultValue == obj.defaultValue) &&
                (distributedResample == obj.distributedResample) &&
                (cellCenteredOutput == obj.cellCenteredOutput));
    }

    public String GetName() { return "Resample"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetUseExtents(boolean useExtents_)
    {
        useExtents = useExtents_;
        Select(0);
    }

    public void SetStartX(double startX_)
    {
        startX = startX_;
        Select(1);
    }

    public void SetEndX(double endX_)
    {
        endX = endX_;
        Select(2);
    }

    public void SetSamplesX(int samplesX_)
    {
        samplesX = samplesX_;
        Select(3);
    }

    public void SetStartY(double startY_)
    {
        startY = startY_;
        Select(4);
    }

    public void SetEndY(double endY_)
    {
        endY = endY_;
        Select(5);
    }

    public void SetSamplesY(int samplesY_)
    {
        samplesY = samplesY_;
        Select(6);
    }

    public void SetIs3D(boolean is3D_)
    {
        is3D = is3D_;
        Select(7);
    }

    public void SetStartZ(double startZ_)
    {
        startZ = startZ_;
        Select(8);
    }

    public void SetEndZ(double endZ_)
    {
        endZ = endZ_;
        Select(9);
    }

    public void SetSamplesZ(int samplesZ_)
    {
        samplesZ = samplesZ_;
        Select(10);
    }

    public void SetTieResolver(int tieResolver_)
    {
        tieResolver = tieResolver_;
        Select(11);
    }

    public void SetTieResolverVariable(String tieResolverVariable_)
    {
        tieResolverVariable = tieResolverVariable_;
        Select(12);
    }

    public void SetDefaultValue(double defaultValue_)
    {
        defaultValue = defaultValue_;
        Select(13);
    }

    public void SetDistributedResample(boolean distributedResample_)
    {
        distributedResample = distributedResample_;
        Select(14);
    }

    public void SetCellCenteredOutput(boolean cellCenteredOutput_)
    {
        cellCenteredOutput = cellCenteredOutput_;
        Select(15);
    }

    // Property getting methods
    public boolean GetUseExtents() { return useExtents; }
    public double  GetStartX() { return startX; }
    public double  GetEndX() { return endX; }
    public int     GetSamplesX() { return samplesX; }
    public double  GetStartY() { return startY; }
    public double  GetEndY() { return endY; }
    public int     GetSamplesY() { return samplesY; }
    public boolean GetIs3D() { return is3D; }
    public double  GetStartZ() { return startZ; }
    public double  GetEndZ() { return endZ; }
    public int     GetSamplesZ() { return samplesZ; }
    public int     GetTieResolver() { return tieResolver; }
    public String  GetTieResolverVariable() { return tieResolverVariable; }
    public double  GetDefaultValue() { return defaultValue; }
    public boolean GetDistributedResample() { return distributedResample; }
    public boolean GetCellCenteredOutput() { return cellCenteredOutput; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteBool(useExtents);
        if(WriteSelect(1, buf))
            buf.WriteDouble(startX);
        if(WriteSelect(2, buf))
            buf.WriteDouble(endX);
        if(WriteSelect(3, buf))
            buf.WriteInt(samplesX);
        if(WriteSelect(4, buf))
            buf.WriteDouble(startY);
        if(WriteSelect(5, buf))
            buf.WriteDouble(endY);
        if(WriteSelect(6, buf))
            buf.WriteInt(samplesY);
        if(WriteSelect(7, buf))
            buf.WriteBool(is3D);
        if(WriteSelect(8, buf))
            buf.WriteDouble(startZ);
        if(WriteSelect(9, buf))
            buf.WriteDouble(endZ);
        if(WriteSelect(10, buf))
            buf.WriteInt(samplesZ);
        if(WriteSelect(11, buf))
            buf.WriteInt(tieResolver);
        if(WriteSelect(12, buf))
            buf.WriteString(tieResolverVariable);
        if(WriteSelect(13, buf))
            buf.WriteDouble(defaultValue);
        if(WriteSelect(14, buf))
            buf.WriteBool(distributedResample);
        if(WriteSelect(15, buf))
            buf.WriteBool(cellCenteredOutput);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetUseExtents(buf.ReadBool());
            break;
        case 1:
            SetStartX(buf.ReadDouble());
            break;
        case 2:
            SetEndX(buf.ReadDouble());
            break;
        case 3:
            SetSamplesX(buf.ReadInt());
            break;
        case 4:
            SetStartY(buf.ReadDouble());
            break;
        case 5:
            SetEndY(buf.ReadDouble());
            break;
        case 6:
            SetSamplesY(buf.ReadInt());
            break;
        case 7:
            SetIs3D(buf.ReadBool());
            break;
        case 8:
            SetStartZ(buf.ReadDouble());
            break;
        case 9:
            SetEndZ(buf.ReadDouble());
            break;
        case 10:
            SetSamplesZ(buf.ReadInt());
            break;
        case 11:
            SetTieResolver(buf.ReadInt());
            break;
        case 12:
            SetTieResolverVariable(buf.ReadString());
            break;
        case 13:
            SetDefaultValue(buf.ReadDouble());
            break;
        case 14:
            SetDistributedResample(buf.ReadBool());
            break;
        case 15:
            SetCellCenteredOutput(buf.ReadBool());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + boolToString("useExtents", useExtents, indent) + "\n";
        str = str + doubleToString("startX", startX, indent) + "\n";
        str = str + doubleToString("endX", endX, indent) + "\n";
        str = str + intToString("samplesX", samplesX, indent) + "\n";
        str = str + doubleToString("startY", startY, indent) + "\n";
        str = str + doubleToString("endY", endY, indent) + "\n";
        str = str + intToString("samplesY", samplesY, indent) + "\n";
        str = str + boolToString("is3D", is3D, indent) + "\n";
        str = str + doubleToString("startZ", startZ, indent) + "\n";
        str = str + doubleToString("endZ", endZ, indent) + "\n";
        str = str + intToString("samplesZ", samplesZ, indent) + "\n";
        str = str + indent + "tieResolver = ";
        if(tieResolver == TIERESOLVER_RANDOM)
            str = str + "TIERESOLVER_RANDOM";
        if(tieResolver == TIERESOLVER_LARGEST)
            str = str + "TIERESOLVER_LARGEST";
        if(tieResolver == TIERESOLVER_SMALLEST)
            str = str + "TIERESOLVER_SMALLEST";
        str = str + "\n";
        str = str + stringToString("tieResolverVariable", tieResolverVariable, indent) + "\n";
        str = str + doubleToString("defaultValue", defaultValue, indent) + "\n";
        str = str + boolToString("distributedResample", distributedResample, indent) + "\n";
        str = str + boolToString("cellCenteredOutput", cellCenteredOutput, indent) + "\n";
        return str;
    }


    // Attributes
    private boolean useExtents;
    private double  startX;
    private double  endX;
    private int     samplesX;
    private double  startY;
    private double  endY;
    private int     samplesY;
    private boolean is3D;
    private double  startZ;
    private double  endZ;
    private int     samplesZ;
    private int     tieResolver;
    private String  tieResolverVariable;
    private double  defaultValue;
    private boolean distributedResample;
    private boolean cellCenteredOutput;
}

