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


// ****************************************************************************
// Class: PrinterAttributes
//
// Purpose:
//    This class contains the attributes used for controlling printers.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Wed Mar 14 17:55:07 PST 2007
//
// Modifications:
//   
// ****************************************************************************

public class PrinterAttributes extends AttributeSubject
{
    public PrinterAttributes()
    {
        super(10);

        printerName = new String("");
        printProgram = new String("lpr");
        documentName = new String("untitled");
        creator = new String("");
        numCopies = 1;
        portrait = true;
        printColor = true;
        outputToFile = false;
        outputToFileName = new String("untitled");
        pageSize = 2;
    }

    public PrinterAttributes(PrinterAttributes obj)
    {
        super(10);

        printerName = new String(obj.printerName);
        printProgram = new String(obj.printProgram);
        documentName = new String(obj.documentName);
        creator = new String(obj.creator);
        numCopies = obj.numCopies;
        portrait = obj.portrait;
        printColor = obj.printColor;
        outputToFile = obj.outputToFile;
        outputToFileName = new String(obj.outputToFileName);
        pageSize = obj.pageSize;

        SelectAll();
    }

    public boolean equals(PrinterAttributes obj)
    {
        // Create the return value
        return ((printerName == obj.printerName) &&
                (printProgram == obj.printProgram) &&
                (documentName == obj.documentName) &&
                (creator == obj.creator) &&
                (numCopies == obj.numCopies) &&
                (portrait == obj.portrait) &&
                (printColor == obj.printColor) &&
                (outputToFile == obj.outputToFile) &&
                (outputToFileName == obj.outputToFileName) &&
                (pageSize == obj.pageSize));
    }

    // Property setting methods
    public void SetPrinterName(String printerName_)
    {
        printerName = printerName_;
        Select(0);
    }

    public void SetPrintProgram(String printProgram_)
    {
        printProgram = printProgram_;
        Select(1);
    }

    public void SetDocumentName(String documentName_)
    {
        documentName = documentName_;
        Select(2);
    }

    public void SetCreator(String creator_)
    {
        creator = creator_;
        Select(3);
    }

    public void SetNumCopies(int numCopies_)
    {
        numCopies = numCopies_;
        Select(4);
    }

    public void SetPortrait(boolean portrait_)
    {
        portrait = portrait_;
        Select(5);
    }

    public void SetPrintColor(boolean printColor_)
    {
        printColor = printColor_;
        Select(6);
    }

    public void SetOutputToFile(boolean outputToFile_)
    {
        outputToFile = outputToFile_;
        Select(7);
    }

    public void SetOutputToFileName(String outputToFileName_)
    {
        outputToFileName = outputToFileName_;
        Select(8);
    }

    public void SetPageSize(int pageSize_)
    {
        pageSize = pageSize_;
        Select(9);
    }

    // Property getting methods
    public String  GetPrinterName() { return printerName; }
    public String  GetPrintProgram() { return printProgram; }
    public String  GetDocumentName() { return documentName; }
    public String  GetCreator() { return creator; }
    public int     GetNumCopies() { return numCopies; }
    public boolean GetPortrait() { return portrait; }
    public boolean GetPrintColor() { return printColor; }
    public boolean GetOutputToFile() { return outputToFile; }
    public String  GetOutputToFileName() { return outputToFileName; }
    public int     GetPageSize() { return pageSize; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(printerName);
        if(WriteSelect(1, buf))
            buf.WriteString(printProgram);
        if(WriteSelect(2, buf))
            buf.WriteString(documentName);
        if(WriteSelect(3, buf))
            buf.WriteString(creator);
        if(WriteSelect(4, buf))
            buf.WriteInt(numCopies);
        if(WriteSelect(5, buf))
            buf.WriteBool(portrait);
        if(WriteSelect(6, buf))
            buf.WriteBool(printColor);
        if(WriteSelect(7, buf))
            buf.WriteBool(outputToFile);
        if(WriteSelect(8, buf))
            buf.WriteString(outputToFileName);
        if(WriteSelect(9, buf))
            buf.WriteInt(pageSize);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetPrinterName(buf.ReadString());
                break;
            case 1:
                SetPrintProgram(buf.ReadString());
                break;
            case 2:
                SetDocumentName(buf.ReadString());
                break;
            case 3:
                SetCreator(buf.ReadString());
                break;
            case 4:
                SetNumCopies(buf.ReadInt());
                break;
            case 5:
                SetPortrait(buf.ReadBool());
                break;
            case 6:
                SetPrintColor(buf.ReadBool());
                break;
            case 7:
                SetOutputToFile(buf.ReadBool());
                break;
            case 8:
                SetOutputToFileName(buf.ReadString());
                break;
            case 9:
                SetPageSize(buf.ReadInt());
                break;
            }
        }
    }


    // Attributes
    private String  printerName;
    private String  printProgram;
    private String  documentName;
    private String  creator;
    private int     numCopies;
    private boolean portrait;
    private boolean printColor;
    private boolean outputToFile;
    private String  outputToFileName;
    private int     pageSize;
}

