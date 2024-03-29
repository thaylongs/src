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

import java.util.Vector;
import java.lang.Integer;
import java.lang.Double;

// ****************************************************************************
// Class: DatabaseCorrelation
//
// Purpose:
//    This class encapsulates a database correlation, which is a mapping of one or more databases to a set of indices that go from 0 to N.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class DatabaseCorrelation extends AttributeSubject
{
    private static int DatabaseCorrelation_numAdditionalAtts = 10;

    // Enum values
    public final static int CORRELATIONMETHOD_INDEXFORINDEXCORRELATION = 0;
    public final static int CORRELATIONMETHOD_STRETCHEDINDEXCORRELATION = 1;
    public final static int CORRELATIONMETHOD_TIMECORRELATION = 2;
    public final static int CORRELATIONMETHOD_CYCLECORRELATION = 3;
    public final static int CORRELATIONMETHOD_USERDEFINEDCORRELATION = 4;


    public DatabaseCorrelation()
    {
        super(DatabaseCorrelation_numAdditionalAtts);

        name = new String("");
        numStates = 1;
        method = CORRELATIONMETHOD_INDEXFORINDEXCORRELATION;
        databaseNames = new Vector();
        databaseNStates = new Vector();
        databaseTimes = new Vector();
        databaseCycles = new Vector();
        indices = new Vector();
        condensedTimes = new Vector();
        condensedCycles = new Vector();
    }

    public DatabaseCorrelation(int nMoreFields)
    {
        super(DatabaseCorrelation_numAdditionalAtts + nMoreFields);

        name = new String("");
        numStates = 1;
        method = CORRELATIONMETHOD_INDEXFORINDEXCORRELATION;
        databaseNames = new Vector();
        databaseNStates = new Vector();
        databaseTimes = new Vector();
        databaseCycles = new Vector();
        indices = new Vector();
        condensedTimes = new Vector();
        condensedCycles = new Vector();
    }

    public DatabaseCorrelation(DatabaseCorrelation obj)
    {
        super(DatabaseCorrelation_numAdditionalAtts);

        int i;

        name = new String(obj.name);
        numStates = obj.numStates;
        method = obj.method;
        databaseNames = new Vector(obj.databaseNames.size());
        for(i = 0; i < obj.databaseNames.size(); ++i)
            databaseNames.addElement(new String((String)obj.databaseNames.elementAt(i)));

        databaseNStates = new Vector();
        for(i = 0; i < obj.databaseNStates.size(); ++i)
        {
            Integer iv = (Integer)obj.databaseNStates.elementAt(i);
            databaseNStates.addElement(new Integer(iv.intValue()));
        }
        databaseTimes = new Vector(obj.databaseTimes.size());
        for(i = 0; i < obj.databaseTimes.size(); ++i)
        {
            Double dv = (Double)obj.databaseTimes.elementAt(i);
            databaseTimes.addElement(new Double(dv.doubleValue()));
        }

        databaseCycles = new Vector();
        for(i = 0; i < obj.databaseCycles.size(); ++i)
        {
            Integer iv = (Integer)obj.databaseCycles.elementAt(i);
            databaseCycles.addElement(new Integer(iv.intValue()));
        }
        indices = new Vector();
        for(i = 0; i < obj.indices.size(); ++i)
        {
            Integer iv = (Integer)obj.indices.elementAt(i);
            indices.addElement(new Integer(iv.intValue()));
        }
        condensedTimes = new Vector(obj.condensedTimes.size());
        for(i = 0; i < obj.condensedTimes.size(); ++i)
        {
            Double dv = (Double)obj.condensedTimes.elementAt(i);
            condensedTimes.addElement(new Double(dv.doubleValue()));
        }

        condensedCycles = new Vector();
        for(i = 0; i < obj.condensedCycles.size(); ++i)
        {
            Integer iv = (Integer)obj.condensedCycles.elementAt(i);
            condensedCycles.addElement(new Integer(iv.intValue()));
        }

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return DatabaseCorrelation_numAdditionalAtts;
    }

    public boolean equals(DatabaseCorrelation obj)
    {
        int i;

        // Compare the elements in the databaseNames vector.
        boolean databaseNames_equal = (obj.databaseNames.size() == databaseNames.size());
        for(i = 0; (i < databaseNames.size()) && databaseNames_equal; ++i)
        {
            // Make references to String from Object.
            String databaseNames1 = (String)databaseNames.elementAt(i);
            String databaseNames2 = (String)obj.databaseNames.elementAt(i);
            databaseNames_equal = databaseNames1.equals(databaseNames2);
        }
        // Compare the elements in the databaseNStates vector.
        boolean databaseNStates_equal = (obj.databaseNStates.size() == databaseNStates.size());
        for(i = 0; (i < databaseNStates.size()) && databaseNStates_equal; ++i)
        {
            // Make references to Integer from Object.
            Integer databaseNStates1 = (Integer)databaseNStates.elementAt(i);
            Integer databaseNStates2 = (Integer)obj.databaseNStates.elementAt(i);
            databaseNStates_equal = databaseNStates1.equals(databaseNStates2);
        }
        // Compare the elements in the databaseTimes vector.
        boolean databaseTimes_equal = (obj.databaseTimes.size() == databaseTimes.size());
        for(i = 0; (i < databaseTimes.size()) && databaseTimes_equal; ++i)
        {
            // Make references to Double from Object.
            Double databaseTimes1 = (Double)databaseTimes.elementAt(i);
            Double databaseTimes2 = (Double)obj.databaseTimes.elementAt(i);
            databaseTimes_equal = databaseTimes1.equals(databaseTimes2);
        }
        // Compare the elements in the databaseCycles vector.
        boolean databaseCycles_equal = (obj.databaseCycles.size() == databaseCycles.size());
        for(i = 0; (i < databaseCycles.size()) && databaseCycles_equal; ++i)
        {
            // Make references to Integer from Object.
            Integer databaseCycles1 = (Integer)databaseCycles.elementAt(i);
            Integer databaseCycles2 = (Integer)obj.databaseCycles.elementAt(i);
            databaseCycles_equal = databaseCycles1.equals(databaseCycles2);
        }
        // Compare the elements in the indices vector.
        boolean indices_equal = (obj.indices.size() == indices.size());
        for(i = 0; (i < indices.size()) && indices_equal; ++i)
        {
            // Make references to Integer from Object.
            Integer indices1 = (Integer)indices.elementAt(i);
            Integer indices2 = (Integer)obj.indices.elementAt(i);
            indices_equal = indices1.equals(indices2);
        }
        // Compare the elements in the condensedTimes vector.
        boolean condensedTimes_equal = (obj.condensedTimes.size() == condensedTimes.size());
        for(i = 0; (i < condensedTimes.size()) && condensedTimes_equal; ++i)
        {
            // Make references to Double from Object.
            Double condensedTimes1 = (Double)condensedTimes.elementAt(i);
            Double condensedTimes2 = (Double)obj.condensedTimes.elementAt(i);
            condensedTimes_equal = condensedTimes1.equals(condensedTimes2);
        }
        // Compare the elements in the condensedCycles vector.
        boolean condensedCycles_equal = (obj.condensedCycles.size() == condensedCycles.size());
        for(i = 0; (i < condensedCycles.size()) && condensedCycles_equal; ++i)
        {
            // Make references to Integer from Object.
            Integer condensedCycles1 = (Integer)condensedCycles.elementAt(i);
            Integer condensedCycles2 = (Integer)obj.condensedCycles.elementAt(i);
            condensedCycles_equal = condensedCycles1.equals(condensedCycles2);
        }
        // Create the return value
        return ((name.equals(obj.name)) &&
                (numStates == obj.numStates) &&
                (method == obj.method) &&
                databaseNames_equal &&
                databaseNStates_equal &&
                databaseTimes_equal &&
                databaseCycles_equal &&
                indices_equal &&
                condensedTimes_equal &&
                condensedCycles_equal);
    }

    // Property setting methods
    public void SetName(String name_)
    {
        name = name_;
        Select(0);
    }

    public void SetNumStates(int numStates_)
    {
        numStates = numStates_;
        Select(1);
    }

    public void SetMethod(int method_)
    {
        method = method_;
        Select(2);
    }

    public void SetDatabaseNames(Vector databaseNames_)
    {
        databaseNames = databaseNames_;
        Select(3);
    }

    public void SetDatabaseNStates(Vector databaseNStates_)
    {
        databaseNStates = databaseNStates_;
        Select(4);
    }

    public void SetDatabaseTimes(Vector databaseTimes_)
    {
        databaseTimes = databaseTimes_;
        Select(5);
    }

    public void SetDatabaseCycles(Vector databaseCycles_)
    {
        databaseCycles = databaseCycles_;
        Select(6);
    }

    public void SetIndices(Vector indices_)
    {
        indices = indices_;
        Select(7);
    }

    public void SetCondensedTimes(Vector condensedTimes_)
    {
        condensedTimes = condensedTimes_;
        Select(8);
    }

    public void SetCondensedCycles(Vector condensedCycles_)
    {
        condensedCycles = condensedCycles_;
        Select(9);
    }

    // Property getting methods
    public String GetName() { return name; }
    public int    GetNumStates() { return numStates; }
    public int    GetMethod() { return method; }
    public Vector GetDatabaseNames() { return databaseNames; }
    public Vector GetDatabaseNStates() { return databaseNStates; }
    public Vector GetDatabaseTimes() { return databaseTimes; }
    public Vector GetDatabaseCycles() { return databaseCycles; }
    public Vector GetIndices() { return indices; }
    public Vector GetCondensedTimes() { return condensedTimes; }
    public Vector GetCondensedCycles() { return condensedCycles; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(name);
        if(WriteSelect(1, buf))
            buf.WriteInt(numStates);
        if(WriteSelect(2, buf))
            buf.WriteInt(method);
        if(WriteSelect(3, buf))
            buf.WriteStringVector(databaseNames);
        if(WriteSelect(4, buf))
            buf.WriteIntVector(databaseNStates);
        if(WriteSelect(5, buf))
            buf.WriteDoubleVector(databaseTimes);
        if(WriteSelect(6, buf))
            buf.WriteIntVector(databaseCycles);
        if(WriteSelect(7, buf))
            buf.WriteIntVector(indices);
        if(WriteSelect(8, buf))
            buf.WriteDoubleVector(condensedTimes);
        if(WriteSelect(9, buf))
            buf.WriteIntVector(condensedCycles);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetName(buf.ReadString());
            break;
        case 1:
            SetNumStates(buf.ReadInt());
            break;
        case 2:
            SetMethod(buf.ReadInt());
            break;
        case 3:
            SetDatabaseNames(buf.ReadStringVector());
            break;
        case 4:
            SetDatabaseNStates(buf.ReadIntVector());
            break;
        case 5:
            SetDatabaseTimes(buf.ReadDoubleVector());
            break;
        case 6:
            SetDatabaseCycles(buf.ReadIntVector());
            break;
        case 7:
            SetIndices(buf.ReadIntVector());
            break;
        case 8:
            SetCondensedTimes(buf.ReadDoubleVector());
            break;
        case 9:
            SetCondensedCycles(buf.ReadIntVector());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + stringToString("name", name, indent) + "\n";
        str = str + intToString("numStates", numStates, indent) + "\n";
        str = str + indent + "method = ";
        if(method == CORRELATIONMETHOD_INDEXFORINDEXCORRELATION)
            str = str + "CORRELATIONMETHOD_INDEXFORINDEXCORRELATION";
        if(method == CORRELATIONMETHOD_STRETCHEDINDEXCORRELATION)
            str = str + "CORRELATIONMETHOD_STRETCHEDINDEXCORRELATION";
        if(method == CORRELATIONMETHOD_TIMECORRELATION)
            str = str + "CORRELATIONMETHOD_TIMECORRELATION";
        if(method == CORRELATIONMETHOD_CYCLECORRELATION)
            str = str + "CORRELATIONMETHOD_CYCLECORRELATION";
        if(method == CORRELATIONMETHOD_USERDEFINEDCORRELATION)
            str = str + "CORRELATIONMETHOD_USERDEFINEDCORRELATION";
        str = str + "\n";
        str = str + stringVectorToString("databaseNames", databaseNames, indent) + "\n";
        str = str + intVectorToString("databaseNStates", databaseNStates, indent) + "\n";
        str = str + doubleVectorToString("databaseTimes", databaseTimes, indent) + "\n";
        str = str + intVectorToString("databaseCycles", databaseCycles, indent) + "\n";
        str = str + intVectorToString("indices", indices, indent) + "\n";
        str = str + doubleVectorToString("condensedTimes", condensedTimes, indent) + "\n";
        str = str + intVectorToString("condensedCycles", condensedCycles, indent) + "\n";
        return str;
    }


    // Attributes
    private String name;
    private int    numStates;
    private int    method;
    private Vector databaseNames; // vector of String objects
    private Vector databaseNStates; // vector of Integer objects
    private Vector databaseTimes; // vector of Double objects
    private Vector databaseCycles; // vector of Integer objects
    private Vector indices; // vector of Integer objects
    private Vector condensedTimes; // vector of Double objects
    private Vector condensedCycles; // vector of Integer objects
}

