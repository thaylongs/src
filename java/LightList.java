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
// Class: LightList
//
// Purpose:
//    This class contains a list of LightAttributes.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class LightList extends AttributeSubject
{
    private static int LightList_numAdditionalAtts = 8;

    public LightList()
    {
        super(LightList_numAdditionalAtts);

        light0 = new LightAttributes();
        light1 = new LightAttributes();
        light2 = new LightAttributes();
        light3 = new LightAttributes();
        light4 = new LightAttributes();
        light5 = new LightAttributes();
        light6 = new LightAttributes();
        light7 = new LightAttributes();
        SetDefaultEnabledStates();
    }

    public LightList(int nMoreFields)
    {
        super(LightList_numAdditionalAtts + nMoreFields);

        light0 = new LightAttributes();
        light1 = new LightAttributes();
        light2 = new LightAttributes();
        light3 = new LightAttributes();
        light4 = new LightAttributes();
        light5 = new LightAttributes();
        light6 = new LightAttributes();
        light7 = new LightAttributes();
        SetDefaultEnabledStates();
    }

    public LightList(LightList obj)
    {
        super(LightList_numAdditionalAtts);

        light0 = new LightAttributes(obj.light0);
        light1 = new LightAttributes(obj.light1);
        light2 = new LightAttributes(obj.light2);
        light3 = new LightAttributes(obj.light3);
        light4 = new LightAttributes(obj.light4);
        light5 = new LightAttributes(obj.light5);
        light6 = new LightAttributes(obj.light6);
        light7 = new LightAttributes(obj.light7);

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return LightList_numAdditionalAtts;
    }

    public boolean equals(LightList obj)
    {
        // Create the return value
        return ((light0.equals(obj.light0)) &&
                (light1.equals(obj.light1)) &&
                (light2.equals(obj.light2)) &&
                (light3.equals(obj.light3)) &&
                (light4.equals(obj.light4)) &&
                (light5.equals(obj.light5)) &&
                (light6.equals(obj.light6)) &&
                (light7.equals(obj.light7)));
    }

    // Property setting methods
    public void SetLight0(LightAttributes light0_)
    {
        light0 = light0_;
        Select(0);
    }

    public void SetLight1(LightAttributes light1_)
    {
        light1 = light1_;
        Select(1);
    }

    public void SetLight2(LightAttributes light2_)
    {
        light2 = light2_;
        Select(2);
    }

    public void SetLight3(LightAttributes light3_)
    {
        light3 = light3_;
        Select(3);
    }

    public void SetLight4(LightAttributes light4_)
    {
        light4 = light4_;
        Select(4);
    }

    public void SetLight5(LightAttributes light5_)
    {
        light5 = light5_;
        Select(5);
    }

    public void SetLight6(LightAttributes light6_)
    {
        light6 = light6_;
        Select(6);
    }

    public void SetLight7(LightAttributes light7_)
    {
        light7 = light7_;
        Select(7);
    }

    // Property getting methods
    public LightAttributes GetLight0() { return light0; }
    public LightAttributes GetLight1() { return light1; }
    public LightAttributes GetLight2() { return light2; }
    public LightAttributes GetLight3() { return light3; }
    public LightAttributes GetLight4() { return light4; }
    public LightAttributes GetLight5() { return light5; }
    public LightAttributes GetLight6() { return light6; }
    public LightAttributes GetLight7() { return light7; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            light0.Write(buf);
        if(WriteSelect(1, buf))
            light1.Write(buf);
        if(WriteSelect(2, buf))
            light2.Write(buf);
        if(WriteSelect(3, buf))
            light3.Write(buf);
        if(WriteSelect(4, buf))
            light4.Write(buf);
        if(WriteSelect(5, buf))
            light5.Write(buf);
        if(WriteSelect(6, buf))
            light6.Write(buf);
        if(WriteSelect(7, buf))
            light7.Write(buf);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            light0.Read(buf);
            Select(0);
            break;
        case 1:
            light1.Read(buf);
            Select(1);
            break;
        case 2:
            light2.Read(buf);
            Select(2);
            break;
        case 3:
            light3.Read(buf);
            Select(3);
            break;
        case 4:
            light4.Read(buf);
            Select(4);
            break;
        case 5:
            light5.Read(buf);
            Select(5);
            break;
        case 6:
            light6.Read(buf);
            Select(6);
            break;
        case 7:
            light7.Read(buf);
            Select(7);
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "light0 = {\n" + light0.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "light1 = {\n" + light1.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "light2 = {\n" + light2.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "light3 = {\n" + light3.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "light4 = {\n" + light4.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "light5 = {\n" + light5.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "light6 = {\n" + light6.toString(indent + "    ") + indent + "}\n";
        str = str + indent + "light7 = {\n" + light7.toString(indent + "    ") + indent + "}\n";
        return str;
    }


    public void SetDefaultEnabledStates()
    {
        light0.SetEnabledFlag(true);
        light1.SetEnabledFlag(false);
        light2.SetEnabledFlag(false);
        light3.SetEnabledFlag(false);
        light4.SetEnabledFlag(false);
        light5.SetEnabledFlag(false);
        light6.SetEnabledFlag(false);
        light7.SetEnabledFlag(false);
    }

    public void SetAllEnabled(boolean val)
    {
        light0.SetEnabledFlag(val);
        light1.SetEnabledFlag(val);
        light2.SetEnabledFlag(val);
        light3.SetEnabledFlag(val);
        light4.SetEnabledFlag(val);
        light5.SetEnabledFlag(val);
        light6.SetEnabledFlag(val);
        light7.SetEnabledFlag(val);
        SelectAll();
    }

    // Attributes
    private LightAttributes light0;
    private LightAttributes light1;
    private LightAttributes light2;
    private LightAttributes light3;
    private LightAttributes light4;
    private LightAttributes light5;
    private LightAttributes light6;
    private LightAttributes light7;
}

