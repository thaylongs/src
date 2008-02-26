// ***************************************************************************
//
// Copyright (c) 2000 - 2008, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory
// LLNL-CODE-400142
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

import java.util.Vector;

// ****************************************************************************
// Class: avtSimulationInformation
//
// Purpose:
//    Contains information about simulation connections
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Mon Feb 25 15:10:59 PST 2008
//
// Modifications:
//   
// ****************************************************************************

public class avtSimulationInformation extends AttributeSubject
{
    // Enum values
    public final static int RUNMODE_UNKNOWN = 0;
    public final static int RUNMODE_RUNNING = 1;
    public final static int RUNMODE_STOPPED = 2;


    public avtSimulationInformation()
    {
        super(8);

        host = new String("");
        port = 0;
        securityKey = new String("");
        otherNames = new Vector();
        otherValues = new Vector();
        genericCommands = new Vector();
        mode = RUNMODE_UNKNOWN;
        customCommands = new Vector();
    }

    public avtSimulationInformation(avtSimulationInformation obj)
    {
        super(8);

        int i;

        host = new String(obj.host);
        port = obj.port;
        securityKey = new String(obj.securityKey);
        otherNames = new Vector(obj.otherNames.size());
        for(i = 0; i < obj.otherNames.size(); ++i)
            otherNames.addElement(new String((String)obj.otherNames.elementAt(i)));

        otherValues = new Vector(obj.otherValues.size());
        for(i = 0; i < obj.otherValues.size(); ++i)
            otherValues.addElement(new String((String)obj.otherValues.elementAt(i)));

        // *** Copy the genericCommands field ***
        genericCommands = new Vector(obj.genericCommands.size());
        for(i = 0; i < obj.genericCommands.size(); ++i)
        {
            avtSimulationCommandSpecification newObj = (avtSimulationCommandSpecification)genericCommands.elementAt(i);
            genericCommands.addElement(new avtSimulationCommandSpecification(newObj));
        }

        mode = obj.mode;
        // *** Copy the customCommands field ***
        customCommands = new Vector(obj.customCommands.size());
        for(i = 0; i < obj.customCommands.size(); ++i)
        {
            avtSimulationCommandSpecification newObj = (avtSimulationCommandSpecification)customCommands.elementAt(i);
            customCommands.addElement(new avtSimulationCommandSpecification(newObj));
        }


        SelectAll();
    }

    public boolean equals(avtSimulationInformation obj)
    {
        int i;

        boolean genericCommands_equal = (obj.genericCommands.size() == genericCommands.size());
        for(i = 0; (i < genericCommands.size()) && genericCommands_equal; ++i)
        {
            // Make references to avtSimulationCommandSpecification from Object.
            avtSimulationCommandSpecification genericCommands1 = (avtSimulationCommandSpecification)genericCommands.elementAt(i);
            avtSimulationCommandSpecification genericCommands2 = (avtSimulationCommandSpecification)obj.genericCommands.elementAt(i);
            genericCommands_equal = genericCommands1.equals(genericCommands2);
        }

        boolean customCommands_equal = (obj.customCommands.size() == customCommands.size());
        for(i = 0; (i < customCommands.size()) && customCommands_equal; ++i)
        {
            // Make references to avtSimulationCommandSpecification from Object.
            avtSimulationCommandSpecification customCommands1 = (avtSimulationCommandSpecification)customCommands.elementAt(i);
            avtSimulationCommandSpecification customCommands2 = (avtSimulationCommandSpecification)obj.customCommands.elementAt(i);
            customCommands_equal = customCommands1.equals(customCommands2);
        }

        // Create the return value
        return ((host == obj.host) &&
                (port == obj.port) &&
                (securityKey == obj.securityKey) &&
                (otherNames == obj.otherNames) &&
                (otherValues == obj.otherValues) &&
                genericCommands_equal &&
                (mode == obj.mode) &&
                customCommands_equal);
    }

    // Property setting methods
    public void SetHost(String host_)
    {
        host = host_;
        Select(0);
    }

    public void SetPort(int port_)
    {
        port = port_;
        Select(1);
    }

    public void SetSecurityKey(String securityKey_)
    {
        securityKey = securityKey_;
        Select(2);
    }

    public void SetOtherNames(Vector otherNames_)
    {
        otherNames = otherNames_;
        Select(3);
    }

    public void SetOtherValues(Vector otherValues_)
    {
        otherValues = otherValues_;
        Select(4);
    }

    public void SetMode(int mode_)
    {
        mode = mode_;
        Select(6);
    }

    // Property getting methods
    public String GetHost() { return host; }
    public int    GetPort() { return port; }
    public String GetSecurityKey() { return securityKey; }
    public Vector GetOtherNames() { return otherNames; }
    public Vector GetOtherValues() { return otherValues; }
    public Vector GetGenericCommands() { return genericCommands; }
    public int    GetMode() { return mode; }
    public Vector GetCustomCommands() { return customCommands; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(host);
        if(WriteSelect(1, buf))
            buf.WriteInt(port);
        if(WriteSelect(2, buf))
            buf.WriteString(securityKey);
        if(WriteSelect(3, buf))
            buf.WriteStringVector(otherNames);
        if(WriteSelect(4, buf))
            buf.WriteStringVector(otherValues);
        if(WriteSelect(5, buf))
        {
            buf.WriteInt(genericCommands.size());
            for(int i = 0; i < genericCommands.size(); ++i)
            {
                avtSimulationCommandSpecification tmp = (avtSimulationCommandSpecification)genericCommands.elementAt(i);
                tmp.Write(buf);
            }
        }
        if(WriteSelect(6, buf))
            buf.WriteInt(mode);
        if(WriteSelect(7, buf))
        {
            buf.WriteInt(customCommands.size());
            for(int i = 0; i < customCommands.size(); ++i)
            {
                avtSimulationCommandSpecification tmp = (avtSimulationCommandSpecification)customCommands.elementAt(i);
                tmp.Write(buf);
            }
        }
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetHost(buf.ReadString());
                break;
            case 1:
                SetPort(buf.ReadInt());
                break;
            case 2:
                SetSecurityKey(buf.ReadString());
                break;
            case 3:
                SetOtherNames(buf.ReadStringVector());
                break;
            case 4:
                SetOtherValues(buf.ReadStringVector());
                break;
            case 5:
                {
                    int len = buf.ReadInt();
                    genericCommands.clear();
                    for(int j = 0; j < len; ++j)
                    {
                        avtSimulationCommandSpecification tmp = new avtSimulationCommandSpecification();
                        tmp.Read(buf);
                        genericCommands.addElement(tmp);
                    }
                }
                Select(5);
                break;
            case 6:
                SetMode(buf.ReadInt());
                break;
            case 7:
                {
                    int len = buf.ReadInt();
                    customCommands.clear();
                    for(int j = 0; j < len; ++j)
                    {
                        avtSimulationCommandSpecification tmp = new avtSimulationCommandSpecification();
                        tmp.Read(buf);
                        customCommands.addElement(tmp);
                    }
                }
                Select(7);
                break;
            }
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + stringToString("host", host, indent) + "\n";
        str = str + intToString("port", port, indent) + "\n";
        str = str + stringToString("securityKey", securityKey, indent) + "\n";
        str = str + stringVectorToString("otherNames", otherNames, indent) + "\n";
        str = str + stringVectorToString("otherValues", otherValues, indent) + "\n";
        str = str + indent + "genericCommands = {\n";
        for(int i = 0; i < genericCommands.size(); ++i)
        {
            AttributeSubject s = (AttributeSubject)genericCommands.elementAt(i);
            str = str + s.toString(indent + "    ");
            if(i < genericCommands.size()-1)
                str = str + ", ";
            str = str + "\n";
        }
        str = str + "}\n";
        str = str + indent + "mode = ";
        if(mode == RUNMODE_UNKNOWN)
            str = str + "RUNMODE_UNKNOWN";
        if(mode == RUNMODE_RUNNING)
            str = str + "RUNMODE_RUNNING";
        if(mode == RUNMODE_STOPPED)
            str = str + "RUNMODE_STOPPED";
        str = str + "\n";
        str = str + indent + "customCommands = {\n";
        for(int i = 0; i < customCommands.size(); ++i)
        {
            AttributeSubject s = (AttributeSubject)customCommands.elementAt(i);
            str = str + s.toString(indent + "    ");
            if(i < customCommands.size()-1)
                str = str + ", ";
            str = str + "\n";
        }
        str = str + "}\n";
        return str;
    }

    // Attributegroup convenience methods
    public void AddGenericCommands(avtSimulationCommandSpecification obj)
    {
        genericCommands.addElement(new avtSimulationCommandSpecification(obj));
        Select(5);
    }

    public void ClearGenericCommands()
    {
        genericCommands.clear();
        Select(5);
    }

    public void RemoveGenericCommands(int index)
    {
        if(index >= 0 && index < genericCommands.size())
        {
            genericCommands.remove(index);
            Select(5);
        }
    }

    public int GetNumGenericCommands()
    {
        return genericCommands.size();
    }

    public avtSimulationCommandSpecification GetGenericCommands(int i)
    {
        avtSimulationCommandSpecification tmp = (avtSimulationCommandSpecification)genericCommands.elementAt(i);
        return tmp;
    }

    public void AddCustomCommands(avtSimulationCommandSpecification obj)
    {
        customCommands.addElement(new avtSimulationCommandSpecification(obj));
        Select(7);
    }

    public void ClearCustomCommands()
    {
        customCommands.clear();
        Select(7);
    }

    public void RemoveCustomCommands(int index)
    {
        if(index >= 0 && index < customCommands.size())
        {
            customCommands.remove(index);
            Select(7);
        }
    }

    public int GetNumCustomCommands()
    {
        return customCommands.size();
    }

    public avtSimulationCommandSpecification GetCustomCommands(int i)
    {
        avtSimulationCommandSpecification tmp = (avtSimulationCommandSpecification)customCommands.elementAt(i);
        return tmp;
    }


    // Attributes
    private String host;
    private int    port;
    private String securityKey;
    private Vector otherNames; // vector of String objects
    private Vector otherValues; // vector of String objects
    private Vector genericCommands; // vector of avtSimulationCommandSpecification objects
    private int    mode;
    private Vector customCommands; // vector of avtSimulationCommandSpecification objects
}

