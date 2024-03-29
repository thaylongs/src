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

import java.lang.Integer;
import java.util.Vector;
import java.lang.Double;

// ****************************************************************************
// Class: ClientMethod
//
// Purpose:
//    This class contains the attributes needed to make one client execute a method on another client.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class ClientMethod extends AttributeSubject
{
    private static int ClientMethod_numAdditionalAtts = 4;

    public ClientMethod()
    {
        super(ClientMethod_numAdditionalAtts);

        methodName = new String("");
        intArgs = new Vector();
        doubleArgs = new Vector();
        stringArgs = new Vector();
    }

    public ClientMethod(int nMoreFields)
    {
        super(ClientMethod_numAdditionalAtts + nMoreFields);

        methodName = new String("");
        intArgs = new Vector();
        doubleArgs = new Vector();
        stringArgs = new Vector();
    }

    public ClientMethod(ClientMethod obj)
    {
        super(ClientMethod_numAdditionalAtts);

        int i;

        methodName = new String(obj.methodName);
        intArgs = new Vector();
        for(i = 0; i < obj.intArgs.size(); ++i)
        {
            Integer iv = (Integer)obj.intArgs.elementAt(i);
            intArgs.addElement(new Integer(iv.intValue()));
        }
        doubleArgs = new Vector(obj.doubleArgs.size());
        for(i = 0; i < obj.doubleArgs.size(); ++i)
        {
            Double dv = (Double)obj.doubleArgs.elementAt(i);
            doubleArgs.addElement(new Double(dv.doubleValue()));
        }

        stringArgs = new Vector(obj.stringArgs.size());
        for(i = 0; i < obj.stringArgs.size(); ++i)
            stringArgs.addElement(new String((String)obj.stringArgs.elementAt(i)));


        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return ClientMethod_numAdditionalAtts;
    }

    public boolean equals(ClientMethod obj)
    {
        int i;

        // Compare the elements in the intArgs vector.
        boolean intArgs_equal = (obj.intArgs.size() == intArgs.size());
        for(i = 0; (i < intArgs.size()) && intArgs_equal; ++i)
        {
            // Make references to Integer from Object.
            Integer intArgs1 = (Integer)intArgs.elementAt(i);
            Integer intArgs2 = (Integer)obj.intArgs.elementAt(i);
            intArgs_equal = intArgs1.equals(intArgs2);
        }
        // Compare the elements in the doubleArgs vector.
        boolean doubleArgs_equal = (obj.doubleArgs.size() == doubleArgs.size());
        for(i = 0; (i < doubleArgs.size()) && doubleArgs_equal; ++i)
        {
            // Make references to Double from Object.
            Double doubleArgs1 = (Double)doubleArgs.elementAt(i);
            Double doubleArgs2 = (Double)obj.doubleArgs.elementAt(i);
            doubleArgs_equal = doubleArgs1.equals(doubleArgs2);
        }
        // Compare the elements in the stringArgs vector.
        boolean stringArgs_equal = (obj.stringArgs.size() == stringArgs.size());
        for(i = 0; (i < stringArgs.size()) && stringArgs_equal; ++i)
        {
            // Make references to String from Object.
            String stringArgs1 = (String)stringArgs.elementAt(i);
            String stringArgs2 = (String)obj.stringArgs.elementAt(i);
            stringArgs_equal = stringArgs1.equals(stringArgs2);
        }
        // Create the return value
        return ((methodName.equals(obj.methodName)) &&
                intArgs_equal &&
                doubleArgs_equal &&
                stringArgs_equal);
    }

    // Property setting methods
    public void SetMethodName(String methodName_)
    {
        methodName = methodName_;
        Select(0);
    }

    public void SetIntArgs(Vector intArgs_)
    {
        intArgs = intArgs_;
        Select(1);
    }

    public void SetDoubleArgs(Vector doubleArgs_)
    {
        doubleArgs = doubleArgs_;
        Select(2);
    }

    public void SetStringArgs(Vector stringArgs_)
    {
        stringArgs = stringArgs_;
        Select(3);
    }

    // Property getting methods
    public String GetMethodName() { return methodName; }
    public Vector GetIntArgs() { return intArgs; }
    public Vector GetDoubleArgs() { return doubleArgs; }
    public Vector GetStringArgs() { return stringArgs; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(methodName);
        if(WriteSelect(1, buf))
            buf.WriteIntVector(intArgs);
        if(WriteSelect(2, buf))
            buf.WriteDoubleVector(doubleArgs);
        if(WriteSelect(3, buf))
            buf.WriteStringVector(stringArgs);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetMethodName(buf.ReadString());
            break;
        case 1:
            SetIntArgs(buf.ReadIntVector());
            break;
        case 2:
            SetDoubleArgs(buf.ReadDoubleVector());
            break;
        case 3:
            SetStringArgs(buf.ReadStringVector());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + stringToString("methodName", methodName, indent) + "\n";
        str = str + intVectorToString("intArgs", intArgs, indent) + "\n";
        str = str + doubleVectorToString("doubleArgs", doubleArgs, indent) + "\n";
        str = str + stringVectorToString("stringArgs", stringArgs, indent) + "\n";
        return str;
    }


    // Attributes
    private String methodName;
    private Vector intArgs; // vector of Integer objects
    private Vector doubleArgs; // vector of Double objects
    private Vector stringArgs; // vector of String objects
}

