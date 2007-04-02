// ****************************************************************************
//
// Copyright (c) 2000 - 2007, The Regents of the University of California
// Produced at the Lawrence Livermore National Laboratory
// All rights reserved.
//
// This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
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
//    documentation and/or materials provided with the distribution.
//  - Neither the name of the UC/LLNL nor  the names of its contributors may be
//    used to  endorse or  promote products derived from  this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
// CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
// ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ****************************************************************************

package llnl.visit;

import java.lang.Double;
import java.util.Vector;

// ****************************************************************************
// Class: ProcessAttributes
//
// Purpose:
//    attributes to describe a running process
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Thu May 12 13:45:17 PST 2005
//
// Modifications:
//   
// ****************************************************************************

public class ProcessAttributes extends AttributeSubject
{
    public ProcessAttributes()
    {
        super(4);

        pids = new Vector();
        ppids = new Vector();
        hosts = new Vector();
        isParallel = false;
    }

    public ProcessAttributes(ProcessAttributes obj)
    {
        super(4);

        int i;

        pids = new Vector(obj.pids.size());
        for(i = 0; i < obj.pids.size(); ++i)
        {
            Double dv = (Double)obj.pids.elementAt(i);
            pids.addElement(new Double(dv.doubleValue()));
        }

        ppids = new Vector(obj.ppids.size());
        for(i = 0; i < obj.ppids.size(); ++i)
        {
            Double dv = (Double)obj.ppids.elementAt(i);
            ppids.addElement(new Double(dv.doubleValue()));
        }

        hosts = new Vector(obj.hosts.size());
        for(i = 0; i < obj.hosts.size(); ++i)
            hosts.addElement(new String((String)obj.hosts.elementAt(i)));

        isParallel = obj.isParallel;

        SelectAll();
    }

    public boolean equals(ProcessAttributes obj)
    {
        int i;

        // Create the return value
        return ((pids == obj.pids) &&
                (ppids == obj.ppids) &&
                (hosts == obj.hosts) &&
                (isParallel == obj.isParallel));
    }

    // Property setting methods
    public void SetPids(Vector pids_)
    {
        pids = pids_;
        Select(0);
    }

    public void SetPpids(Vector ppids_)
    {
        ppids = ppids_;
        Select(1);
    }

    public void SetHosts(Vector hosts_)
    {
        hosts = hosts_;
        Select(2);
    }

    public void SetIsParallel(boolean isParallel_)
    {
        isParallel = isParallel_;
        Select(3);
    }

    // Property getting methods
    public Vector  GetPids() { return pids; }
    public Vector  GetPpids() { return ppids; }
    public Vector  GetHosts() { return hosts; }
    public boolean GetIsParallel() { return isParallel; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteDoubleVector(pids);
        if(WriteSelect(1, buf))
            buf.WriteDoubleVector(ppids);
        if(WriteSelect(2, buf))
            buf.WriteStringVector(hosts);
        if(WriteSelect(3, buf))
            buf.WriteBool(isParallel);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetPids(buf.ReadDoubleVector());
                break;
            case 1:
                SetPpids(buf.ReadDoubleVector());
                break;
            case 2:
                SetHosts(buf.ReadStringVector());
                break;
            case 3:
                SetIsParallel(buf.ReadBool());
                break;
            }
        }
    }


    // Attributes
    private Vector  pids; // vector of Double objects
    private Vector  ppids; // vector of Double objects
    private Vector  hosts; // vector of String objects
    private boolean isParallel;
}

