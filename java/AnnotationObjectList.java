// ***************************************************************************
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
// ***************************************************************************

package llnl.visit;

import java.util.Vector;

// ****************************************************************************
// Class: AnnotationObjectList
//
// Purpose:
//    Contains a list of AnnotationObjectAttributes
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Tue Mar 20 09:28:42 PDT 2007
//
// Modifications:
//   
// ****************************************************************************

public class AnnotationObjectList extends AttributeSubject
{
    public AnnotationObjectList()
    {
        super(1);

        annotation = new Vector();
    }

    public AnnotationObjectList(AnnotationObjectList obj)
    {
        super(1);

        int i;

        // *** Copy the annotation field ***
        annotation = new Vector(obj.annotation.size());
        for(i = 0; i < obj.annotation.size(); ++i)
        {
            AnnotationObject newObj = (AnnotationObject)annotation.elementAt(i);
            annotation.addElement(new AnnotationObject(newObj));
        }


        SelectAll();
    }

    public boolean equals(AnnotationObjectList obj)
    {
        int i;

        boolean annotation_equal = (obj.annotation.size() == annotation.size());
        for(i = 0; (i < annotation.size()) && annotation_equal; ++i)
        {
            // Make references to AnnotationObject from Object.
            AnnotationObject annotation1 = (AnnotationObject)annotation.elementAt(i);
            AnnotationObject annotation2 = (AnnotationObject)obj.annotation.elementAt(i);
            annotation_equal = annotation1.equals(annotation2);
        }

        // Create the return value
        return (annotation_equal);
    }

    // Property setting methods
    // Property getting methods
    public Vector GetAnnotation() { return annotation; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
        {
            buf.WriteInt(annotation.size());
            for(int i = 0; i < annotation.size(); ++i)
            {
                AnnotationObject tmp = (AnnotationObject)annotation.elementAt(i);
                tmp.Write(buf);
            }
        }
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        buf.ReadByte();
        {
            int len = buf.ReadInt();
            annotation.clear();
            for(int j = 0; j < len; ++j)
            {
                AnnotationObject tmp = new AnnotationObject();
                tmp.Read(buf);
                annotation.addElement(tmp);
            }
        }
        Select(0);
    }

    // Attributegroup convenience methods
    public void AddAnnotation(AnnotationObject obj)
    {
        annotation.addElement(new AnnotationObject(obj));
        Select(0);
    }

    public void ClearAnnotations()
    {
        annotation.clear();
        Select(0);
    }

    public void RemoveAnnotation(int index)
    {
        if(index >= 0 && index < annotation.size())
        {
            annotation.remove(index);
            Select(0);
        }
    }

    public int GetNumAnnotations()
    {
        return annotation.size();
    }

    public AnnotationObject GetAnnotation(int i)
    {
        AnnotationObject tmp = (AnnotationObject)annotation.elementAt(i);
        return tmp;
    }


    // Attributes
    private Vector annotation; // vector of AnnotationObject objects
}

