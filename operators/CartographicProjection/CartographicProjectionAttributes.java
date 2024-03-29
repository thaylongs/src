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
// Class: CartographicProjectionAttributes
//
// Purpose:
//    
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class CartographicProjectionAttributes extends AttributeSubject implements Plugin
{
    private static int CartographicProjectionAttributes_numAdditionalAtts = 2;

    // Enum values
    public final static int PROJECTIONID_AITOFF = 0;
    public final static int PROJECTIONID_ECK4 = 1;
    public final static int PROJECTIONID_EQDC = 2;
    public final static int PROJECTIONID_HAMMER = 3;
    public final static int PROJECTIONID_LAEA = 4;
    public final static int PROJECTIONID_LCC = 5;
    public final static int PROJECTIONID_MERC = 6;
    public final static int PROJECTIONID_MILL = 7;
    public final static int PROJECTIONID_MOLL = 8;
    public final static int PROJECTIONID_ORTHO = 9;
    public final static int PROJECTIONID_WINK2 = 10;


    public CartographicProjectionAttributes()
    {
        super(CartographicProjectionAttributes_numAdditionalAtts);

        projectionID = PROJECTIONID_AITOFF;
        centralMeridian = 0;
    }

    public CartographicProjectionAttributes(int nMoreFields)
    {
        super(CartographicProjectionAttributes_numAdditionalAtts + nMoreFields);

        projectionID = PROJECTIONID_AITOFF;
        centralMeridian = 0;
    }

    public CartographicProjectionAttributes(CartographicProjectionAttributes obj)
    {
        super(CartographicProjectionAttributes_numAdditionalAtts);

        projectionID = obj.projectionID;
        centralMeridian = obj.centralMeridian;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return CartographicProjectionAttributes_numAdditionalAtts;
    }

    public boolean equals(CartographicProjectionAttributes obj)
    {
        // Create the return value
        return ((projectionID == obj.projectionID) &&
                (centralMeridian == obj.centralMeridian));
    }

    public String GetName() { return "CartographicProjection"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetProjectionID(int projectionID_)
    {
        projectionID = projectionID_;
        Select(0);
    }

    public void SetCentralMeridian(double centralMeridian_)
    {
        centralMeridian = centralMeridian_;
        Select(1);
    }

    // Property getting methods
    public int    GetProjectionID() { return projectionID; }
    public double GetCentralMeridian() { return centralMeridian; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteInt(projectionID);
        if(WriteSelect(1, buf))
            buf.WriteDouble(centralMeridian);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetProjectionID(buf.ReadInt());
            break;
        case 1:
            SetCentralMeridian(buf.ReadDouble());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "projectionID = ";
        if(projectionID == PROJECTIONID_AITOFF)
            str = str + "PROJECTIONID_AITOFF";
        if(projectionID == PROJECTIONID_ECK4)
            str = str + "PROJECTIONID_ECK4";
        if(projectionID == PROJECTIONID_EQDC)
            str = str + "PROJECTIONID_EQDC";
        if(projectionID == PROJECTIONID_HAMMER)
            str = str + "PROJECTIONID_HAMMER";
        if(projectionID == PROJECTIONID_LAEA)
            str = str + "PROJECTIONID_LAEA";
        if(projectionID == PROJECTIONID_LCC)
            str = str + "PROJECTIONID_LCC";
        if(projectionID == PROJECTIONID_MERC)
            str = str + "PROJECTIONID_MERC";
        if(projectionID == PROJECTIONID_MILL)
            str = str + "PROJECTIONID_MILL";
        if(projectionID == PROJECTIONID_MOLL)
            str = str + "PROJECTIONID_MOLL";
        if(projectionID == PROJECTIONID_ORTHO)
            str = str + "PROJECTIONID_ORTHO";
        if(projectionID == PROJECTIONID_WINK2)
            str = str + "PROJECTIONID_WINK2";
        str = str + "\n";
        str = str + doubleToString("centralMeridian", centralMeridian, indent) + "\n";
        return str;
    }


    // Attributes
    private int    projectionID;
    private double centralMeridian;
}

