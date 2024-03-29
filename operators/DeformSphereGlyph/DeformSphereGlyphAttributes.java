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
// Class: DeformSphereGlyphAttributes
//
// Purpose:
//    Attributes for the DeformSphereGlyph
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class DeformSphereGlyphAttributes extends AttributeSubject implements Plugin
{
    private static int DeformSphereGlyphAttributes_numAdditionalAtts = 3;

    public DeformSphereGlyphAttributes()
    {
        super(DeformSphereGlyphAttributes_numAdditionalAtts);

        var = new String("Default");
        scale = 1;
        minSize = 1;
    }

    public DeformSphereGlyphAttributes(int nMoreFields)
    {
        super(DeformSphereGlyphAttributes_numAdditionalAtts + nMoreFields);

        var = new String("Default");
        scale = 1;
        minSize = 1;
    }

    public DeformSphereGlyphAttributes(DeformSphereGlyphAttributes obj)
    {
        super(DeformSphereGlyphAttributes_numAdditionalAtts);

        var = new String(obj.var);
        scale = obj.scale;
        minSize = obj.minSize;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return DeformSphereGlyphAttributes_numAdditionalAtts;
    }

    public boolean equals(DeformSphereGlyphAttributes obj)
    {
        // Create the return value
        return ((var.equals(obj.var)) &&
                (scale == obj.scale) &&
                (minSize == obj.minSize));
    }

    public String GetName() { return "DeformSphereGlyph"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetVar(String var_)
    {
        var = var_;
        Select(0);
    }

    public void SetScale(double scale_)
    {
        scale = scale_;
        Select(1);
    }

    public void SetMinSize(double minSize_)
    {
        minSize = minSize_;
        Select(2);
    }

    // Property getting methods
    public String GetVar() { return var; }
    public double GetScale() { return scale; }
    public double GetMinSize() { return minSize; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(var);
        if(WriteSelect(1, buf))
            buf.WriteDouble(scale);
        if(WriteSelect(2, buf))
            buf.WriteDouble(minSize);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetVar(buf.ReadString());
            break;
        case 1:
            SetScale(buf.ReadDouble());
            break;
        case 2:
            SetMinSize(buf.ReadDouble());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + stringToString("var", var, indent) + "\n";
        str = str + doubleToString("scale", scale, indent) + "\n";
        str = str + doubleToString("minSize", minSize, indent) + "\n";
        return str;
    }


    // Attributes
    private String var;
    private double scale;
    private double minSize;
}

