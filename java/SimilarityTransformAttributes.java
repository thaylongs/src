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
// Class: SimilarityTransformAttributes
//
// Purpose:
//    This class contains attributes for the similarity transform.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class SimilarityTransformAttributes extends AttributeSubject
{
    private static int SimilarityTransformAttributes_numAdditionalAtts = 15;

    // Enum values
    public final static int ANGLETYPE_DEG = 0;
    public final static int ANGLETYPE_RAD = 1;


    public SimilarityTransformAttributes()
    {
        super(SimilarityTransformAttributes_numAdditionalAtts);

        doRotate = false;
        rotateOrigin = new double[3];
        rotateOrigin[0] = 0;
        rotateOrigin[1] = 0;
        rotateOrigin[2] = 0;
        rotateAxis = new double[3];
        rotateAxis[0] = 0;
        rotateAxis[1] = 0;
        rotateAxis[2] = 1;
        rotateAmount = 0;
        rotateType = ANGLETYPE_DEG;
        doScale = false;
        scaleOrigin = new double[3];
        scaleOrigin[0] = 0;
        scaleOrigin[1] = 0;
        scaleOrigin[2] = 0;
        scaleX = 1;
        scaleY = 1;
        scaleZ = 1;
        doTranslate = false;
        translateX = 0;
        translateY = 0;
        translateZ = 0;
        transformVectors = true;
    }

    public SimilarityTransformAttributes(int nMoreFields)
    {
        super(SimilarityTransformAttributes_numAdditionalAtts + nMoreFields);

        doRotate = false;
        rotateOrigin = new double[3];
        rotateOrigin[0] = 0;
        rotateOrigin[1] = 0;
        rotateOrigin[2] = 0;
        rotateAxis = new double[3];
        rotateAxis[0] = 0;
        rotateAxis[1] = 0;
        rotateAxis[2] = 1;
        rotateAmount = 0;
        rotateType = ANGLETYPE_DEG;
        doScale = false;
        scaleOrigin = new double[3];
        scaleOrigin[0] = 0;
        scaleOrigin[1] = 0;
        scaleOrigin[2] = 0;
        scaleX = 1;
        scaleY = 1;
        scaleZ = 1;
        doTranslate = false;
        translateX = 0;
        translateY = 0;
        translateZ = 0;
        transformVectors = true;
    }

    public SimilarityTransformAttributes(SimilarityTransformAttributes obj)
    {
        super(SimilarityTransformAttributes_numAdditionalAtts);

        int i;

        doRotate = obj.doRotate;
        rotateOrigin = new double[3];
        rotateOrigin[0] = obj.rotateOrigin[0];
        rotateOrigin[1] = obj.rotateOrigin[1];
        rotateOrigin[2] = obj.rotateOrigin[2];

        rotateAxis = new double[3];
        rotateAxis[0] = obj.rotateAxis[0];
        rotateAxis[1] = obj.rotateAxis[1];
        rotateAxis[2] = obj.rotateAxis[2];

        rotateAmount = obj.rotateAmount;
        rotateType = obj.rotateType;
        doScale = obj.doScale;
        scaleOrigin = new double[3];
        scaleOrigin[0] = obj.scaleOrigin[0];
        scaleOrigin[1] = obj.scaleOrigin[1];
        scaleOrigin[2] = obj.scaleOrigin[2];

        scaleX = obj.scaleX;
        scaleY = obj.scaleY;
        scaleZ = obj.scaleZ;
        doTranslate = obj.doTranslate;
        translateX = obj.translateX;
        translateY = obj.translateY;
        translateZ = obj.translateZ;
        transformVectors = obj.transformVectors;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return SimilarityTransformAttributes_numAdditionalAtts;
    }

    public boolean equals(SimilarityTransformAttributes obj)
    {
        int i;

        // Compare the rotateOrigin arrays.
        boolean rotateOrigin_equal = true;
        for(i = 0; i < 3 && rotateOrigin_equal; ++i)
            rotateOrigin_equal = (rotateOrigin[i] == obj.rotateOrigin[i]);

        // Compare the rotateAxis arrays.
        boolean rotateAxis_equal = true;
        for(i = 0; i < 3 && rotateAxis_equal; ++i)
            rotateAxis_equal = (rotateAxis[i] == obj.rotateAxis[i]);

        // Compare the scaleOrigin arrays.
        boolean scaleOrigin_equal = true;
        for(i = 0; i < 3 && scaleOrigin_equal; ++i)
            scaleOrigin_equal = (scaleOrigin[i] == obj.scaleOrigin[i]);

        // Create the return value
        return ((doRotate == obj.doRotate) &&
                rotateOrigin_equal &&
                rotateAxis_equal &&
                (rotateAmount == obj.rotateAmount) &&
                (rotateType == obj.rotateType) &&
                (doScale == obj.doScale) &&
                scaleOrigin_equal &&
                (scaleX == obj.scaleX) &&
                (scaleY == obj.scaleY) &&
                (scaleZ == obj.scaleZ) &&
                (doTranslate == obj.doTranslate) &&
                (translateX == obj.translateX) &&
                (translateY == obj.translateY) &&
                (translateZ == obj.translateZ) &&
                (transformVectors == obj.transformVectors));
    }

    // Property setting methods
    public void SetDoRotate(boolean doRotate_)
    {
        doRotate = doRotate_;
        Select(0);
    }

    public void SetRotateOrigin(double[] rotateOrigin_)
    {
        rotateOrigin[0] = rotateOrigin_[0];
        rotateOrigin[1] = rotateOrigin_[1];
        rotateOrigin[2] = rotateOrigin_[2];
        Select(1);
    }

    public void SetRotateOrigin(double e0, double e1, double e2)
    {
        rotateOrigin[0] = e0;
        rotateOrigin[1] = e1;
        rotateOrigin[2] = e2;
        Select(1);
    }

    public void SetRotateAxis(double[] rotateAxis_)
    {
        rotateAxis[0] = rotateAxis_[0];
        rotateAxis[1] = rotateAxis_[1];
        rotateAxis[2] = rotateAxis_[2];
        Select(2);
    }

    public void SetRotateAxis(double e0, double e1, double e2)
    {
        rotateAxis[0] = e0;
        rotateAxis[1] = e1;
        rotateAxis[2] = e2;
        Select(2);
    }

    public void SetRotateAmount(double rotateAmount_)
    {
        rotateAmount = rotateAmount_;
        Select(3);
    }

    public void SetRotateType(int rotateType_)
    {
        rotateType = rotateType_;
        Select(4);
    }

    public void SetDoScale(boolean doScale_)
    {
        doScale = doScale_;
        Select(5);
    }

    public void SetScaleOrigin(double[] scaleOrigin_)
    {
        scaleOrigin[0] = scaleOrigin_[0];
        scaleOrigin[1] = scaleOrigin_[1];
        scaleOrigin[2] = scaleOrigin_[2];
        Select(6);
    }

    public void SetScaleOrigin(double e0, double e1, double e2)
    {
        scaleOrigin[0] = e0;
        scaleOrigin[1] = e1;
        scaleOrigin[2] = e2;
        Select(6);
    }

    public void SetScaleX(double scaleX_)
    {
        scaleX = scaleX_;
        Select(7);
    }

    public void SetScaleY(double scaleY_)
    {
        scaleY = scaleY_;
        Select(8);
    }

    public void SetScaleZ(double scaleZ_)
    {
        scaleZ = scaleZ_;
        Select(9);
    }

    public void SetDoTranslate(boolean doTranslate_)
    {
        doTranslate = doTranslate_;
        Select(10);
    }

    public void SetTranslateX(double translateX_)
    {
        translateX = translateX_;
        Select(11);
    }

    public void SetTranslateY(double translateY_)
    {
        translateY = translateY_;
        Select(12);
    }

    public void SetTranslateZ(double translateZ_)
    {
        translateZ = translateZ_;
        Select(13);
    }

    public void SetTransformVectors(boolean transformVectors_)
    {
        transformVectors = transformVectors_;
        Select(14);
    }

    // Property getting methods
    public boolean  GetDoRotate() { return doRotate; }
    public double[] GetRotateOrigin() { return rotateOrigin; }
    public double[] GetRotateAxis() { return rotateAxis; }
    public double   GetRotateAmount() { return rotateAmount; }
    public int      GetRotateType() { return rotateType; }
    public boolean  GetDoScale() { return doScale; }
    public double[] GetScaleOrigin() { return scaleOrigin; }
    public double   GetScaleX() { return scaleX; }
    public double   GetScaleY() { return scaleY; }
    public double   GetScaleZ() { return scaleZ; }
    public boolean  GetDoTranslate() { return doTranslate; }
    public double   GetTranslateX() { return translateX; }
    public double   GetTranslateY() { return translateY; }
    public double   GetTranslateZ() { return translateZ; }
    public boolean  GetTransformVectors() { return transformVectors; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteBool(doRotate);
        if(WriteSelect(1, buf))
            buf.WriteDoubleArray(rotateOrigin);
        if(WriteSelect(2, buf))
            buf.WriteDoubleArray(rotateAxis);
        if(WriteSelect(3, buf))
            buf.WriteDouble(rotateAmount);
        if(WriteSelect(4, buf))
            buf.WriteInt(rotateType);
        if(WriteSelect(5, buf))
            buf.WriteBool(doScale);
        if(WriteSelect(6, buf))
            buf.WriteDoubleArray(scaleOrigin);
        if(WriteSelect(7, buf))
            buf.WriteDouble(scaleX);
        if(WriteSelect(8, buf))
            buf.WriteDouble(scaleY);
        if(WriteSelect(9, buf))
            buf.WriteDouble(scaleZ);
        if(WriteSelect(10, buf))
            buf.WriteBool(doTranslate);
        if(WriteSelect(11, buf))
            buf.WriteDouble(translateX);
        if(WriteSelect(12, buf))
            buf.WriteDouble(translateY);
        if(WriteSelect(13, buf))
            buf.WriteDouble(translateZ);
        if(WriteSelect(14, buf))
            buf.WriteBool(transformVectors);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetDoRotate(buf.ReadBool());
            break;
        case 1:
            SetRotateOrigin(buf.ReadDoubleArray());
            break;
        case 2:
            SetRotateAxis(buf.ReadDoubleArray());
            break;
        case 3:
            SetRotateAmount(buf.ReadDouble());
            break;
        case 4:
            SetRotateType(buf.ReadInt());
            break;
        case 5:
            SetDoScale(buf.ReadBool());
            break;
        case 6:
            SetScaleOrigin(buf.ReadDoubleArray());
            break;
        case 7:
            SetScaleX(buf.ReadDouble());
            break;
        case 8:
            SetScaleY(buf.ReadDouble());
            break;
        case 9:
            SetScaleZ(buf.ReadDouble());
            break;
        case 10:
            SetDoTranslate(buf.ReadBool());
            break;
        case 11:
            SetTranslateX(buf.ReadDouble());
            break;
        case 12:
            SetTranslateY(buf.ReadDouble());
            break;
        case 13:
            SetTranslateZ(buf.ReadDouble());
            break;
        case 14:
            SetTransformVectors(buf.ReadBool());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + boolToString("doRotate", doRotate, indent) + "\n";
        str = str + doubleArrayToString("rotateOrigin", rotateOrigin, indent) + "\n";
        str = str + doubleArrayToString("rotateAxis", rotateAxis, indent) + "\n";
        str = str + doubleToString("rotateAmount", rotateAmount, indent) + "\n";
        str = str + indent + "rotateType = ";
        if(rotateType == ANGLETYPE_DEG)
            str = str + "ANGLETYPE_DEG";
        if(rotateType == ANGLETYPE_RAD)
            str = str + "ANGLETYPE_RAD";
        str = str + "\n";
        str = str + boolToString("doScale", doScale, indent) + "\n";
        str = str + doubleArrayToString("scaleOrigin", scaleOrigin, indent) + "\n";
        str = str + doubleToString("scaleX", scaleX, indent) + "\n";
        str = str + doubleToString("scaleY", scaleY, indent) + "\n";
        str = str + doubleToString("scaleZ", scaleZ, indent) + "\n";
        str = str + boolToString("doTranslate", doTranslate, indent) + "\n";
        str = str + doubleToString("translateX", translateX, indent) + "\n";
        str = str + doubleToString("translateY", translateY, indent) + "\n";
        str = str + doubleToString("translateZ", translateZ, indent) + "\n";
        str = str + boolToString("transformVectors", transformVectors, indent) + "\n";
        return str;
    }


    // Attributes
    private boolean  doRotate;
    private double[] rotateOrigin;
    private double[] rotateAxis;
    private double   rotateAmount;
    private int      rotateType;
    private boolean  doScale;
    private double[] scaleOrigin;
    private double   scaleX;
    private double   scaleY;
    private double   scaleZ;
    private boolean  doTranslate;
    private double   translateX;
    private double   translateY;
    private double   translateZ;
    private boolean  transformVectors;
}

