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
// Class: TriangulateRegularPointsAttributes
//
// Purpose:
//    Attributes for the triangulate regular points operator
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class TriangulateRegularPointsAttributes extends AttributeSubject implements Plugin
{
    private static int TriangulateRegularPointsAttributes_numAdditionalAtts = 4;

    public TriangulateRegularPointsAttributes()
    {
        super(TriangulateRegularPointsAttributes_numAdditionalAtts);

        useXGridSpacing = false;
        xGridSpacing = 1;
        useYGridSpacing = false;
        yGridSpacing = 1;
    }

    public TriangulateRegularPointsAttributes(int nMoreFields)
    {
        super(TriangulateRegularPointsAttributes_numAdditionalAtts + nMoreFields);

        useXGridSpacing = false;
        xGridSpacing = 1;
        useYGridSpacing = false;
        yGridSpacing = 1;
    }

    public TriangulateRegularPointsAttributes(TriangulateRegularPointsAttributes obj)
    {
        super(TriangulateRegularPointsAttributes_numAdditionalAtts);

        useXGridSpacing = obj.useXGridSpacing;
        xGridSpacing = obj.xGridSpacing;
        useYGridSpacing = obj.useYGridSpacing;
        yGridSpacing = obj.yGridSpacing;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return TriangulateRegularPointsAttributes_numAdditionalAtts;
    }

    public boolean equals(TriangulateRegularPointsAttributes obj)
    {
        // Create the return value
        return ((useXGridSpacing == obj.useXGridSpacing) &&
                (xGridSpacing == obj.xGridSpacing) &&
                (useYGridSpacing == obj.useYGridSpacing) &&
                (yGridSpacing == obj.yGridSpacing));
    }

    public String GetName() { return "TriangulateRegularPoints"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetUseXGridSpacing(boolean useXGridSpacing_)
    {
        useXGridSpacing = useXGridSpacing_;
        Select(0);
    }

    public void SetXGridSpacing(double xGridSpacing_)
    {
        xGridSpacing = xGridSpacing_;
        Select(1);
    }

    public void SetUseYGridSpacing(boolean useYGridSpacing_)
    {
        useYGridSpacing = useYGridSpacing_;
        Select(2);
    }

    public void SetYGridSpacing(double yGridSpacing_)
    {
        yGridSpacing = yGridSpacing_;
        Select(3);
    }

    // Property getting methods
    public boolean GetUseXGridSpacing() { return useXGridSpacing; }
    public double  GetXGridSpacing() { return xGridSpacing; }
    public boolean GetUseYGridSpacing() { return useYGridSpacing; }
    public double  GetYGridSpacing() { return yGridSpacing; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteBool(useXGridSpacing);
        if(WriteSelect(1, buf))
            buf.WriteDouble(xGridSpacing);
        if(WriteSelect(2, buf))
            buf.WriteBool(useYGridSpacing);
        if(WriteSelect(3, buf))
            buf.WriteDouble(yGridSpacing);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetUseXGridSpacing(buf.ReadBool());
            break;
        case 1:
            SetXGridSpacing(buf.ReadDouble());
            break;
        case 2:
            SetUseYGridSpacing(buf.ReadBool());
            break;
        case 3:
            SetYGridSpacing(buf.ReadDouble());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + boolToString("useXGridSpacing", useXGridSpacing, indent) + "\n";
        str = str + doubleToString("xGridSpacing", xGridSpacing, indent) + "\n";
        str = str + boolToString("useYGridSpacing", useYGridSpacing, indent) + "\n";
        str = str + doubleToString("yGridSpacing", yGridSpacing, indent) + "\n";
        return str;
    }


    // Attributes
    private boolean useXGridSpacing;
    private double  xGridSpacing;
    private boolean useYGridSpacing;
    private double  yGridSpacing;
}

