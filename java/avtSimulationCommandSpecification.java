// ***************************************************************************
//
// Copyright (c) 2000 - 2009, Lawrence Livermore National Security, LLC
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
// Class: avtSimulationCommandSpecification
//
// Purpose:
//    Contains the specification for one command
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class avtSimulationCommandSpecification extends AttributeSubject
{
    // Enum values
    public final static int RUNMODE_UNKNOWN = 0;
    public final static int RUNMODE_RUNNING = 1;
    public final static int RUNMODE_STOPPED = 2;

    public final static int COMMANDARGUMENTTYPE_CMDARGNONE = 0;
    public final static int COMMANDARGUMENTTYPE_CMDARGINT = 1;
    public final static int COMMANDARGUMENTTYPE_CMDARGFLOAT = 2;
    public final static int COMMANDARGUMENTTYPE_CMDARGSTRING = 3;


    public avtSimulationCommandSpecification()
    {
        super(10);

        name = new String("");
            className = new String("");
        enabled = false;
        parent = new String("");
        isOn = false;
        signal = new String("");
        text = new String("");
        uiType = new String("");
        value = new String("");
    }

    public avtSimulationCommandSpecification(avtSimulationCommandSpecification obj)
    {
        super(10);

        name = new String(obj.name);
        argumentType = obj.argumentType;
        className = new String(obj.className);
        enabled = obj.enabled;
        parent = new String(obj.parent);
        isOn = obj.isOn;
        signal = new String(obj.signal);
        text = new String(obj.text);
        uiType = new String(obj.uiType);
        value = new String(obj.value);

        SelectAll();
    }

    public boolean equals(avtSimulationCommandSpecification obj)
    {
        // Create the return value
        return ((name.equals(obj.name)) &&
                (argumentType == obj.argumentType) &&
                (className.equals(obj.className)) &&
                (enabled == obj.enabled) &&
                (parent.equals(obj.parent)) &&
                (isOn == obj.isOn) &&
                (signal.equals(obj.signal)) &&
                (text.equals(obj.text)) &&
                (uiType.equals(obj.uiType)) &&
                (value.equals(obj.value)));
    }

    // Property setting methods
    public void SetName(String name_)
    {
        name = name_;
        Select(0);
    }

    public void SetArgumentType(int argumentType_)
    {
        argumentType = argumentType_;
        Select(1);
    }

    public void SetClassName(String className_)
    {
        className = className_;
        Select(2);
    }

    public void SetEnabled(boolean enabled_)
    {
        enabled = enabled_;
        Select(3);
    }

    public void SetParent(String parent_)
    {
        parent = parent_;
        Select(4);
    }

    public void SetIsOn(boolean isOn_)
    {
        isOn = isOn_;
        Select(5);
    }

    public void SetSignal(String signal_)
    {
        signal = signal_;
        Select(6);
    }

    public void SetText(String text_)
    {
        text = text_;
        Select(7);
    }

    public void SetUiType(String uiType_)
    {
        uiType = uiType_;
        Select(8);
    }

    public void SetValue(String value_)
    {
        value = value_;
        Select(9);
    }

    // Property getting methods
    public String  GetName() { return name; }
    public int     GetArgumentType() { return argumentType; }
    public String  GetClassName() { return className; }
    public boolean GetEnabled() { return enabled; }
    public String  GetParent() { return parent; }
    public boolean GetIsOn() { return isOn; }
    public String  GetSignal() { return signal; }
    public String  GetText() { return text; }
    public String  GetUiType() { return uiType; }
    public String  GetValue() { return value; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(name);
        if(WriteSelect(1, buf))
            buf.WriteInt(argumentType);
        if(WriteSelect(2, buf))
            buf.WriteString(className);
        if(WriteSelect(3, buf))
            buf.WriteBool(enabled);
        if(WriteSelect(4, buf))
            buf.WriteString(parent);
        if(WriteSelect(5, buf))
            buf.WriteBool(isOn);
        if(WriteSelect(6, buf))
            buf.WriteString(signal);
        if(WriteSelect(7, buf))
            buf.WriteString(text);
        if(WriteSelect(8, buf))
            buf.WriteString(uiType);
        if(WriteSelect(9, buf))
            buf.WriteString(value);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetName(buf.ReadString());
                break;
            case 1:
                SetArgumentType(buf.ReadInt());
                break;
            case 2:
                SetClassName(buf.ReadString());
                break;
            case 3:
                SetEnabled(buf.ReadBool());
                break;
            case 4:
                SetParent(buf.ReadString());
                break;
            case 5:
                SetIsOn(buf.ReadBool());
                break;
            case 6:
                SetSignal(buf.ReadString());
                break;
            case 7:
                SetText(buf.ReadString());
                break;
            case 8:
                SetUiType(buf.ReadString());
                break;
            case 9:
                SetValue(buf.ReadString());
                break;
            }
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + stringToString("name", name, indent) + "\n";
        str = str + indent + "argumentType = ";
        if(argumentType == COMMANDARGUMENTTYPE_CMDARGNONE)
            str = str + "COMMANDARGUMENTTYPE_CMDARGNONE";
        if(argumentType == COMMANDARGUMENTTYPE_CMDARGINT)
            str = str + "COMMANDARGUMENTTYPE_CMDARGINT";
        if(argumentType == COMMANDARGUMENTTYPE_CMDARGFLOAT)
            str = str + "COMMANDARGUMENTTYPE_CMDARGFLOAT";
        if(argumentType == COMMANDARGUMENTTYPE_CMDARGSTRING)
            str = str + "COMMANDARGUMENTTYPE_CMDARGSTRING";
        str = str + "\n";
        str = str + stringToString("className", className, indent) + "\n";
        str = str + boolToString("enabled", enabled, indent) + "\n";
        str = str + stringToString("parent", parent, indent) + "\n";
        str = str + boolToString("isOn", isOn, indent) + "\n";
        str = str + stringToString("signal", signal, indent) + "\n";
        str = str + stringToString("text", text, indent) + "\n";
        str = str + stringToString("uiType", uiType, indent) + "\n";
        str = str + stringToString("value", value, indent) + "\n";
        return str;
    }


    // Attributes
    private String  name;
    private int     argumentType;
    private String  className;
    private boolean enabled;
    private String  parent;
    private boolean isOn;
    private String  signal;
    private String  text;
    private String  uiType;
    private String  value;
}

