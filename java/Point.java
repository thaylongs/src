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

package llnl.visit;


// ****************************************************************************
// Class: Point
//
// Purpose:
//    This class contains attributes for a point.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class Point extends AttributeSubject
{
    private static int Point_numAdditionalAtts = 1;

    // Enum values
    public final static int VALUETYPE_VT_TUPLE = 0;
    public final static int VALUETYPE_VT_MIN = 1;
    public final static int VALUETYPE_VT_MAX = 2;
    public final static int VALUETYPE_VT_DOMAINZONE = 3;
    public final static int VALUETYPE_VT_ZONE = 4;
    public final static int VALUETYPE_VT_DOMAINNODE = 5;
    public final static int VALUETYPE_VT_NODE = 6;
    public final static int VALUETYPE_VT_UNKNOWN = 7;


    public Point()
    {
        super(Point_numAdditionalAtts);

        value = new String("");
    }

    public Point(int nMoreFields)
    {
        super(Point_numAdditionalAtts + nMoreFields);

        value = new String("");
    }

    public Point(Point obj)
    {
        super(Point_numAdditionalAtts);

        value = new String(obj.value);

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return Point_numAdditionalAtts;
    }

    public boolean equals(Point obj)
    {
        // Create the return value
        return ((value.equals(obj.value)));
    }

    // Property setting methods
    public void SetValue(String value_)
    {
        value = value_;
        Select(0);
    }

    // Property getting methods
    public String GetValue() { return value; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(value);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        SetValue(buf.ReadString());
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + stringToString("value", value, indent) + "\n";
        return str;
    }


    // Attributes
    private String value;
}

