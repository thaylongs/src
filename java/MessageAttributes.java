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

import java.lang.Byte;
import java.util.Vector;

// ****************************************************************************
// Class: MessageAttributes
//
// Purpose:
//    This class contains attributes for sending messages.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class MessageAttributes extends AttributeSubject
{
    // Enum values
    public final static int SEVERITY_ERROR = 0;
    public final static int SEVERITY_WARNING = 1;
    public final static int SEVERITY_MESSAGE = 2;
    public final static int SEVERITY_ERRORCLEAR = 3;
    public final static int SEVERITY_INFORMATION = 4;


    public MessageAttributes()
    {
        super(4);

        text = new String("");
        unicode = new Vector();
        hasUnicode = false;
        severity = SEVERITY_MESSAGE;
    }

    public MessageAttributes(MessageAttributes obj)
    {
        super(4);

        int i;

        text = new String(obj.text);
        unicode = new Vector(obj.unicode.size());
        for(i = 0; i < obj.unicode.size(); ++i)
        {
            Byte bv = (Byte)obj.unicode.elementAt(i);
            unicode.addElement(new Byte(bv.byteValue()));
        }

        hasUnicode = obj.hasUnicode;
        severity = obj.severity;

        SelectAll();
    }

    public boolean equals(MessageAttributes obj)
    {
        int i;

        // Compare the elements in the unicode vector.
        boolean unicode_equal = (obj.unicode.size() == unicode.size());
        for(i = 0; (i < unicode.size()) && unicode_equal; ++i)
        {
            // Make references to Byte from Object.
            Byte unicode1 = (Byte)unicode.elementAt(i);
            Byte unicode2 = (Byte)obj.unicode.elementAt(i);
            unicode_equal = unicode1.equals(unicode2);
        }
        // Create the return value
        return ((text.equals(obj.text)) &&
                unicode_equal &&
                (hasUnicode == obj.hasUnicode) &&
                (severity == obj.severity));
    }

    // Property setting methods
    public void SetText(String text_)
    {
        text = text_;
        Select(0);
    }

    public void SetUnicode(Vector unicode_)
    {
        unicode = unicode_;
        Select(1);
    }

    public void SetHasUnicode(boolean hasUnicode_)
    {
        hasUnicode = hasUnicode_;
        Select(2);
    }

    public void SetSeverity(int severity_)
    {
        severity = severity_;
        Select(3);
    }

    // Property getting methods
    public String  GetText() { return text; }
    public Vector  GetUnicode() { return unicode; }
    public boolean GetHasUnicode() { return hasUnicode; }
    public int     GetSeverity() { return severity; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(text);
        if(WriteSelect(1, buf))
            buf.WriteByteVector(unicode);
        if(WriteSelect(2, buf))
            buf.WriteBool(hasUnicode);
        if(WriteSelect(3, buf))
            buf.WriteInt(severity);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetText(buf.ReadString());
                break;
            case 1:
                SetUnicode(buf.ReadByteVector());
                break;
            case 2:
                SetHasUnicode(buf.ReadBool());
                break;
            case 3:
                SetSeverity(buf.ReadInt());
                break;
            }
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + stringToString("text", text, indent) + "\n";
        str = str + ucharVectorToString("unicode", unicode, indent) + "\n";
        str = str + boolToString("hasUnicode", hasUnicode, indent) + "\n";
        str = str + indent + "severity = ";
        if(severity == SEVERITY_ERROR)
            str = str + "SEVERITY_ERROR";
        if(severity == SEVERITY_WARNING)
            str = str + "SEVERITY_WARNING";
        if(severity == SEVERITY_MESSAGE)
            str = str + "SEVERITY_MESSAGE";
        if(severity == SEVERITY_ERRORCLEAR)
            str = str + "SEVERITY_ERRORCLEAR";
        if(severity == SEVERITY_INFORMATION)
            str = str + "SEVERITY_INFORMATION";
        str = str + "\n";
        return str;
    }


    // Attributes
    private String  text;
    private Vector  unicode; // vector of Byte objects
    private boolean hasUnicode;
    private int     severity;
}

