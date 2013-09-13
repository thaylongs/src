// ***************************************************************************
//
// Copyright (c) 2000 - 2013, Lawrence Livermore National Security, LLC
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

import java.lang.Double;
import java.util.Vector;

// ****************************************************************************
// Class: ContourOpAttributes
//
// Purpose:
//    This class contains the operator attributes for the contour operator.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class ContourOpAttributes extends AttributeSubject
{
    private static int ContourOpAttributes_numAdditionalAtts = 10;

    // Enum values
    public final static int CONTOURMETHOD_LEVEL = 0;
    public final static int CONTOURMETHOD_VALUE = 1;
    public final static int CONTOURMETHOD_PERCENT = 2;

    public final static int CONTOURSCALING_LINEAR = 0;
    public final static int CONTOURSCALING_LOG = 1;


    public ContourOpAttributes()
    {
        super(ContourOpAttributes_numAdditionalAtts);

        contourNLevels = 10;
        contourValue = new Vector();
        contourPercent = new Vector();
            minFlag = false;
        maxFlag = false;
        min = 0;
        max = 1;
            variable = new String("default");
    }

    public ContourOpAttributes(int nMoreFields)
    {
        super(ContourOpAttributes_numAdditionalAtts + nMoreFields);

        contourNLevels = 10;
        contourValue = new Vector();
        contourPercent = new Vector();
            minFlag = false;
        maxFlag = false;
        min = 0;
        max = 1;
            variable = new String("default");
    }

    public ContourOpAttributes(ContourOpAttributes obj)
    {
        super(ContourOpAttributes_numAdditionalAtts);

        int i;

        contourNLevels = obj.contourNLevels;
        contourValue = new Vector(obj.contourValue.size());
        for(i = 0; i < obj.contourValue.size(); ++i)
        {
            Double dv = (Double)obj.contourValue.elementAt(i);
            contourValue.addElement(new Double(dv.doubleValue()));
        }

        contourPercent = new Vector(obj.contourPercent.size());
        for(i = 0; i < obj.contourPercent.size(); ++i)
        {
            Double dv = (Double)obj.contourPercent.elementAt(i);
            contourPercent.addElement(new Double(dv.doubleValue()));
        }

        contourMethod = obj.contourMethod;
        minFlag = obj.minFlag;
        maxFlag = obj.maxFlag;
        min = obj.min;
        max = obj.max;
        scaling = obj.scaling;
        variable = new String(obj.variable);

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return ContourOpAttributes_numAdditionalAtts;
    }

    public boolean equals(ContourOpAttributes obj)
    {
        int i;

        // Compare the elements in the contourValue vector.
        boolean contourValue_equal = (obj.contourValue.size() == contourValue.size());
        for(i = 0; (i < contourValue.size()) && contourValue_equal; ++i)
        {
            // Make references to Double from Object.
            Double contourValue1 = (Double)contourValue.elementAt(i);
            Double contourValue2 = (Double)obj.contourValue.elementAt(i);
            contourValue_equal = contourValue1.equals(contourValue2);
        }
        // Compare the elements in the contourPercent vector.
        boolean contourPercent_equal = (obj.contourPercent.size() == contourPercent.size());
        for(i = 0; (i < contourPercent.size()) && contourPercent_equal; ++i)
        {
            // Make references to Double from Object.
            Double contourPercent1 = (Double)contourPercent.elementAt(i);
            Double contourPercent2 = (Double)obj.contourPercent.elementAt(i);
            contourPercent_equal = contourPercent1.equals(contourPercent2);
        }
        // Create the return value
        return ((contourNLevels == obj.contourNLevels) &&
                contourValue_equal &&
                contourPercent_equal &&
                (contourMethod == obj.contourMethod) &&
                (minFlag == obj.minFlag) &&
                (maxFlag == obj.maxFlag) &&
                (min == obj.min) &&
                (max == obj.max) &&
                (scaling == obj.scaling) &&
                (variable.equals(obj.variable)));
    }

    // Property setting methods
    public void SetContourNLevels(int contourNLevels_)
    {
        contourNLevels = contourNLevels_;
        Select(0);
    }

    public void SetContourValue(Vector contourValue_)
    {
        contourValue = contourValue_;
        Select(1);
    }

    public void SetContourPercent(Vector contourPercent_)
    {
        contourPercent = contourPercent_;
        Select(2);
    }

    public void SetContourMethod(int contourMethod_)
    {
        contourMethod = contourMethod_;
        Select(3);
    }

    public void SetMinFlag(boolean minFlag_)
    {
        minFlag = minFlag_;
        Select(4);
    }

    public void SetMaxFlag(boolean maxFlag_)
    {
        maxFlag = maxFlag_;
        Select(5);
    }

    public void SetMin(double min_)
    {
        min = min_;
        Select(6);
    }

    public void SetMax(double max_)
    {
        max = max_;
        Select(7);
    }

    public void SetScaling(int scaling_)
    {
        scaling = scaling_;
        Select(8);
    }

    public void SetVariable(String variable_)
    {
        variable = variable_;
        Select(9);
    }

    // Property getting methods
    public int     GetContourNLevels() { return contourNLevels; }
    public Vector  GetContourValue() { return contourValue; }
    public Vector  GetContourPercent() { return contourPercent; }
    public int     GetContourMethod() { return contourMethod; }
    public boolean GetMinFlag() { return minFlag; }
    public boolean GetMaxFlag() { return maxFlag; }
    public double  GetMin() { return min; }
    public double  GetMax() { return max; }
    public int     GetScaling() { return scaling; }
    public String  GetVariable() { return variable; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteInt(contourNLevels);
        if(WriteSelect(1, buf))
            buf.WriteDoubleVector(contourValue);
        if(WriteSelect(2, buf))
            buf.WriteDoubleVector(contourPercent);
        if(WriteSelect(3, buf))
            buf.WriteInt(contourMethod);
        if(WriteSelect(4, buf))
            buf.WriteBool(minFlag);
        if(WriteSelect(5, buf))
            buf.WriteBool(maxFlag);
        if(WriteSelect(6, buf))
            buf.WriteDouble(min);
        if(WriteSelect(7, buf))
            buf.WriteDouble(max);
        if(WriteSelect(8, buf))
            buf.WriteInt(scaling);
        if(WriteSelect(9, buf))
            buf.WriteString(variable);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetContourNLevels(buf.ReadInt());
            break;
        case 1:
            SetContourValue(buf.ReadDoubleVector());
            break;
        case 2:
            SetContourPercent(buf.ReadDoubleVector());
            break;
        case 3:
            SetContourMethod(buf.ReadInt());
            break;
        case 4:
            SetMinFlag(buf.ReadBool());
            break;
        case 5:
            SetMaxFlag(buf.ReadBool());
            break;
        case 6:
            SetMin(buf.ReadDouble());
            break;
        case 7:
            SetMax(buf.ReadDouble());
            break;
        case 8:
            SetScaling(buf.ReadInt());
            break;
        case 9:
            SetVariable(buf.ReadString());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + intToString("contourNLevels", contourNLevels, indent) + "\n";
        str = str + doubleVectorToString("contourValue", contourValue, indent) + "\n";
        str = str + doubleVectorToString("contourPercent", contourPercent, indent) + "\n";
        str = str + indent + "contourMethod = ";
        if(contourMethod == CONTOURMETHOD_LEVEL)
            str = str + "CONTOURMETHOD_LEVEL";
        if(contourMethod == CONTOURMETHOD_VALUE)
            str = str + "CONTOURMETHOD_VALUE";
        if(contourMethod == CONTOURMETHOD_PERCENT)
            str = str + "CONTOURMETHOD_PERCENT";
        str = str + "\n";
        str = str + boolToString("minFlag", minFlag, indent) + "\n";
        str = str + boolToString("maxFlag", maxFlag, indent) + "\n";
        str = str + doubleToString("min", min, indent) + "\n";
        str = str + doubleToString("max", max, indent) + "\n";
        str = str + indent + "scaling = ";
        if(scaling == CONTOURSCALING_LINEAR)
            str = str + "CONTOURSCALING_LINEAR";
        if(scaling == CONTOURSCALING_LOG)
            str = str + "CONTOURSCALING_LOG";
        str = str + "\n";
        str = str + stringToString("variable", variable, indent) + "\n";
        return str;
    }


    // Attributes
    private int     contourNLevels;
    private Vector  contourValue; // vector of Double objects
    private Vector  contourPercent; // vector of Double objects
    private int     contourMethod;
    private boolean minFlag;
    private boolean maxFlag;
    private double  min;
    private double  max;
    private int     scaling;
    private String  variable;
}

