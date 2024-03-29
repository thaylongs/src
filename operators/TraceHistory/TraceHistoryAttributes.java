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
import java.util.Vector;

// ****************************************************************************
// Class: TraceHistoryAttributes
//
// Purpose:
//    Attributes for the TraceHistory operator
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class TraceHistoryAttributes extends AttributeSubject implements Plugin
{
    private static int TraceHistoryAttributes_numAdditionalAtts = 4;

    public TraceHistoryAttributes()
    {
        super(TraceHistoryAttributes_numAdditionalAtts);

        vars = new Vector();
        displacement = new String("");
        numiter = 5;
        output = new String("dump");
    }

    public TraceHistoryAttributes(int nMoreFields)
    {
        super(TraceHistoryAttributes_numAdditionalAtts + nMoreFields);

        vars = new Vector();
        displacement = new String("");
        numiter = 5;
        output = new String("dump");
    }

    public TraceHistoryAttributes(TraceHistoryAttributes obj)
    {
        super(TraceHistoryAttributes_numAdditionalAtts);

        int i;

        vars = new Vector(obj.vars.size());
        for(i = 0; i < obj.vars.size(); ++i)
            vars.addElement(new String((String)obj.vars.elementAt(i)));

        displacement = new String(obj.displacement);
        numiter = obj.numiter;
        output = new String(obj.output);

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return TraceHistoryAttributes_numAdditionalAtts;
    }

    public boolean equals(TraceHistoryAttributes obj)
    {
        int i;

        // Compare the elements in the vars vector.
        boolean vars_equal = (obj.vars.size() == vars.size());
        for(i = 0; (i < vars.size()) && vars_equal; ++i)
        {
            // Make references to String from Object.
            String vars1 = (String)vars.elementAt(i);
            String vars2 = (String)obj.vars.elementAt(i);
            vars_equal = vars1.equals(vars2);
        }
        // Create the return value
        return (vars_equal &&
                (displacement.equals(obj.displacement)) &&
                (numiter == obj.numiter) &&
                (output.equals(obj.output)));
    }

    public String GetName() { return "TraceHistory"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetVars(Vector vars_)
    {
        vars = vars_;
        Select(0);
    }

    public void SetDisplacement(String displacement_)
    {
        displacement = displacement_;
        Select(1);
    }

    public void SetNumiter(int numiter_)
    {
        numiter = numiter_;
        Select(2);
    }

    public void SetOutput(String output_)
    {
        output = output_;
        Select(3);
    }

    // Property getting methods
    public Vector GetVars() { return vars; }
    public String GetDisplacement() { return displacement; }
    public int    GetNumiter() { return numiter; }
    public String GetOutput() { return output; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteStringVector(vars);
        if(WriteSelect(1, buf))
            buf.WriteString(displacement);
        if(WriteSelect(2, buf))
            buf.WriteInt(numiter);
        if(WriteSelect(3, buf))
            buf.WriteString(output);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetVars(buf.ReadStringVector());
            break;
        case 1:
            SetDisplacement(buf.ReadString());
            break;
        case 2:
            SetNumiter(buf.ReadInt());
            break;
        case 3:
            SetOutput(buf.ReadString());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + stringVectorToString("vars", vars, indent) + "\n";
        str = str + stringToString("displacement", displacement, indent) + "\n";
        str = str + intToString("numiter", numiter, indent) + "\n";
        str = str + stringToString("output", output, indent) + "\n";
        return str;
    }


    // Attributes
    private Vector vars; // vector of String objects
    private String displacement;
    private int    numiter;
    private String output;
}

