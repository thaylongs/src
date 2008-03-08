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
// Class: ClientInformationList
//
// Purpose:
//    Contains the information for all connected clients.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class ClientInformationList extends AttributeSubject
{
    public ClientInformationList()
    {
        super(1);

        clients = new Vector();
    }

    public ClientInformationList(ClientInformationList obj)
    {
        super(1);

        int i;

        // *** Copy the clients field ***
        clients = new Vector(obj.clients.size());
        for(i = 0; i < obj.clients.size(); ++i)
        {
            ClientInformation newObj = (ClientInformation)clients.elementAt(i);
            clients.addElement(new ClientInformation(newObj));
        }


        SelectAll();
    }

    public boolean equals(ClientInformationList obj)
    {
        int i;

        // Compare the elements in the clients vector.
        boolean clients_equal = (obj.clients.size() == clients.size());
        for(i = 0; (i < clients.size()) && clients_equal; ++i)
        {
            // Make references to ClientInformation from Object.
            ClientInformation clients1 = (ClientInformation)clients.elementAt(i);
            ClientInformation clients2 = (ClientInformation)obj.clients.elementAt(i);
            clients_equal = clients1.equals(clients2);
        }
        // Create the return value
        return (clients_equal);
    }

    // Property setting methods
    // Property getting methods
    public Vector GetClients() { return clients; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
        {
            buf.WriteInt(clients.size());
            for(int i = 0; i < clients.size(); ++i)
            {
                ClientInformation tmp = (ClientInformation)clients.elementAt(i);
                tmp.Write(buf);
            }
        }
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        buf.ReadByte();
        {
            int len = buf.ReadInt();
            clients.clear();
            for(int j = 0; j < len; ++j)
            {
                ClientInformation tmp = new ClientInformation();
                tmp.Read(buf);
                clients.addElement(tmp);
            }
        }
        Select(0);
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "clients = {\n";
        for(int i = 0; i < clients.size(); ++i)
        {
            AttributeSubject s = (AttributeSubject)clients.elementAt(i);
            str = str + s.toString(indent + "    ");
            if(i < clients.size()-1)
                str = str + ", ";
            str = str + "\n";
        }
        str = str + "}\n";
        return str;
    }

    // Attributegroup convenience methods
    public void AddClients(ClientInformation obj)
    {
        clients.addElement(new ClientInformation(obj));
        Select(0);
    }

    public void ClearClients()
    {
        clients.clear();
        Select(0);
    }

    public void RemoveClients(int index)
    {
        if(index >= 0 && index < clients.size())
        {
            clients.remove(index);
            Select(0);
        }
    }

    public int GetNumClients()
    {
        return clients.size();
    }

    public ClientInformation GetClients(int i)
    {
        ClientInformation tmp = (ClientInformation)clients.elementAt(i);
        return tmp;
    }


    // Attributes
    private Vector clients; // vector of ClientInformation objects
}

