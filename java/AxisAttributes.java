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

package llnl.visit;


// ****************************************************************************
// Class: AxisAttributes
//
// Purpose:
//    Contains the properties for one axis.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class AxisAttributes extends AttributeSubject
{
    private static int AxisAttributes_numAdditionalAtts = 4;

    public AxisAttributes()
    {
        super(AxisAttributes_numAdditionalAtts);

        title = new AxisTitles();
        label = new AxisLabels();
        tickMarks = new AxisTickMarks();
        grid = false;
    }

    public AxisAttributes(int nMoreFields)
    {
        super(AxisAttributes_numAdditionalAtts + nMoreFields);

        title = new AxisTitles();
        label = new AxisLabels();
        tickMarks = new AxisTickMarks();
        grid = false;
    }

    public AxisAttributes(AxisAttributes obj)
    {
        super(AxisAttributes_numAdditionalAtts);

        title = new AxisTitles(obj.title);
        label = new AxisLabels(obj.label);
        tickMarks = new AxisTickMarks(obj.tickMarks);
        grid = obj.grid;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return AxisAttributes_numAdditionalAtts;
    }

    public boolean equals(AxisAttributes obj)
    {
        // Create the return value
        return ((title.equals(obj.title)) &&
                (label.equals(obj.label)) &&
                (tickMarks.equals(obj.tickMarks)) &&
                (grid == obj.grid));
    }

    // Property setting methods
    public void SetTitle(AxisTitles title_)
    {
        title = title_;
        Select(0);
    }

    public void SetLabel(AxisLabels label_)
    {
        label = label_;
        Select(1);
    }

    public void SetTickMarks(AxisTickMarks tickMarks_)
    {
        tickMarks = tickMarks_;
        Select(2);
    }

    public void SetGrid(boolean grid_)
    {
        grid = grid_;
        Select(3);
    }

    // Property getting methods
    public AxisTitles    GetTitle() { return title; }
    public AxisLabels    GetLabel() { return label; }
    public AxisTickMarks GetTickMarks() { return tickMarks; }
    public boolean       GetGrid() { return grid; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            title.Write(buf);
        if(WriteSelect(1, buf))
            label.Write(buf);
        if(WriteSelect(2, buf))
            tickMarks.Write(buf);
        if(WriteSelect(3, buf))
            buf.WriteBool(grid);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            title.Read(buf);
            Select(0);
            break;
        case 1:
            label.Read(buf);
            Select(1);
            break;
        case 2:
            tickMarks.Read(buf);
            Select(2);
            break;
        case 3:
            SetGrid(buf.ReadBool());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "title = {\n" + title.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "label = {\n" + label.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "tickMarks = {\n" + tickMarks.toString(indent + "    ") + indent + "}\n";
        str = str + boolToString("grid", grid, indent) + "\n";
        return str;
    }


    // Attributes
    private AxisTitles    title;
    private AxisLabels    label;
    private AxisTickMarks tickMarks;
    private boolean       grid;
}

