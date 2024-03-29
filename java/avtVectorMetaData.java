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
// Class: avtVectorMetaData
//
// Purpose:
//    Contains vector metadata attributes
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class avtVectorMetaData extends avtVarMetaData
{
    private static int avtVectorMetaData_numAdditionalAtts = 1;

    public avtVectorMetaData()
    {
        super(avtVectorMetaData_numAdditionalAtts);

        varDim = 0;
    }

    public avtVectorMetaData(int nMoreFields)
    {
        super(avtVectorMetaData_numAdditionalAtts + nMoreFields);

        varDim = 0;
    }

    public avtVectorMetaData(avtVectorMetaData obj)
    {
        super(avtVectorMetaData_numAdditionalAtts);

        varDim = obj.varDim;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return avtVectorMetaData_numAdditionalAtts;
    }

    public boolean equals(avtVectorMetaData obj)
    {
        // Create the return value
        return (super.equals(obj) && (varDim == obj.varDim));
    }

    // Property setting methods
    public void SetVarDim(int varDim_)
    {
        varDim = varDim_;
        Select((new avtVectorMetaData()).Offset() + 0);
    }

    // Property getting methods
    public int GetVarDim() { return varDim; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        super.WriteAtts(buf);

        int offset = (new avtVectorMetaData()).Offset();
        if(WriteSelect(offset + 0, buf))
            buf.WriteInt(varDim);
    }

    public void ReadAtts(int id, CommunicationBuffer buf)
    {
        int offset = (new avtVectorMetaData()).Offset();
        if(id == offset)
            SetVarDim(buf.ReadInt());
        else
            super.ReadAtts(id, buf);
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + intToString("varDim", varDim, indent) + "\n";
        return super.toString(indent) + str;
    }


    // Attributes
    private int varDim;
}

