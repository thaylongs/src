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
// Class: DelaunayAttributes
//
// Purpose:
//    Attributes for the Delaunay Operator
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class DelaunayAttributes extends AttributeSubject implements Plugin
{
    private static int DelaunayAttributes_numAdditionalAtts = 1;

    // Enum values
    public final static int DIMENSION_AUTOMATIC = 0;
    public final static int DIMENSION_TRIANGULATION = 1;
    public final static int DIMENSION_TETRAHEDRALIZATION = 2;


    public DelaunayAttributes()
    {
        super(DelaunayAttributes_numAdditionalAtts);

        dimension = DIMENSION_AUTOMATIC;
    }

    public DelaunayAttributes(int nMoreFields)
    {
        super(DelaunayAttributes_numAdditionalAtts + nMoreFields);

        dimension = DIMENSION_AUTOMATIC;
    }

    public DelaunayAttributes(DelaunayAttributes obj)
    {
        super(DelaunayAttributes_numAdditionalAtts);

        dimension = obj.dimension;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return DelaunayAttributes_numAdditionalAtts;
    }

    public boolean equals(DelaunayAttributes obj)
    {
        // Create the return value
        return ((dimension == obj.dimension));
    }

    public String GetName() { return "Delaunay"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetDimension(int dimension_)
    {
        dimension = dimension_;
        Select(0);
    }

    // Property getting methods
    public int GetDimension() { return dimension; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteInt(dimension);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        SetDimension(buf.ReadInt());
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "dimension = ";
        if(dimension == DIMENSION_AUTOMATIC)
            str = str + "DIMENSION_AUTOMATIC";
        if(dimension == DIMENSION_TRIANGULATION)
            str = str + "DIMENSION_TRIANGULATION";
        if(dimension == DIMENSION_TETRAHEDRALIZATION)
            str = str + "DIMENSION_TETRAHEDRALIZATION";
        str = str + "\n";
        return str;
    }


    // Attributes
    private int dimension;
}

