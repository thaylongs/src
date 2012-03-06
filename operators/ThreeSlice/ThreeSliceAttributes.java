// ***************************************************************************
//
// Copyright (c) 2000 - 2012, Lawrence Livermore National Security, LLC
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
// Class: ThreeSliceAttributes
//
// Purpose:
//    This class contains attributes for the threeslice operator.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class ThreeSliceAttributes extends AttributeSubject implements Plugin
{
    private static int ThreeSliceAttributes_numAdditionalAtts = 4;

    public ThreeSliceAttributes()
    {
        super(ThreeSliceAttributes_numAdditionalAtts);

        x = 0f;
        y = 0f;
        z = 0f;
        interactive = true;
    }

    public ThreeSliceAttributes(int nMoreFields)
    {
        super(ThreeSliceAttributes_numAdditionalAtts + nMoreFields);

        x = 0f;
        y = 0f;
        z = 0f;
        interactive = true;
    }

    public ThreeSliceAttributes(ThreeSliceAttributes obj)
    {
        super(ThreeSliceAttributes_numAdditionalAtts);

        x = obj.x;
        y = obj.y;
        z = obj.z;
        interactive = obj.interactive;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return ThreeSliceAttributes_numAdditionalAtts;
    }

    public boolean equals(ThreeSliceAttributes obj)
    {
        // Create the return value
        return ((x == obj.x) &&
                (y == obj.y) &&
                (z == obj.z) &&
                (interactive == obj.interactive));
    }

    public String GetName() { return "ThreeSlice"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetX(float x_)
    {
        x = x_;
        Select(0);
    }

    public void SetY(float y_)
    {
        y = y_;
        Select(1);
    }

    public void SetZ(float z_)
    {
        z = z_;
        Select(2);
    }

    public void SetInteractive(boolean interactive_)
    {
        interactive = interactive_;
        Select(3);
    }

    // Property getting methods
    public float   GetX() { return x; }
    public float   GetY() { return y; }
    public float   GetZ() { return z; }
    public boolean GetInteractive() { return interactive; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteFloat(x);
        if(WriteSelect(1, buf))
            buf.WriteFloat(y);
        if(WriteSelect(2, buf))
            buf.WriteFloat(z);
        if(WriteSelect(3, buf))
            buf.WriteBool(interactive);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetX(buf.ReadFloat());
            break;
        case 1:
            SetY(buf.ReadFloat());
            break;
        case 2:
            SetZ(buf.ReadFloat());
            break;
        case 3:
            SetInteractive(buf.ReadBool());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + floatToString("x", x, indent) + "\n";
        str = str + floatToString("y", y, indent) + "\n";
        str = str + floatToString("z", z, indent) + "\n";
        str = str + boolToString("interactive", interactive, indent) + "\n";
        return str;
    }


    // Attributes
    private float   x;
    private float   y;
    private float   z;
    private boolean interactive;
}

