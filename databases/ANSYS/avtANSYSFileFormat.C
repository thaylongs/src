/*****************************************************************************
*
* Copyright (c) 2000 - 2017, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//                            avtANSYSFileFormat.C                           //
// ************************************************************************* //

#include <avtANSYSFileFormat.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <string>

#if defined(_WIN32)
// for _strnicmp
#include <string.h>
#define STRNCASECMP _strnicmp
#else
// for strcasecmp
#include <strings.h>
#define STRNCASECMP strncasecmp
#endif

#include <vtkCellType.h>
#include <vtkFloatArray.h>
#include <vtkUnstructuredGrid.h>

#include <avtDatabaseMetaData.h>

#include <InvalidVariableException.h>
#include <InvalidFilesException.h>

#include <TimingsManager.h>
#include <DebugStream.h>
#include <FileFunctions.h>

using     std::string;

#define ALL_LINES -1

// ****************************************************************************
//  Method: avtANSYSFileFormat constructor
//
//  Programmer: Brad Whitlock
//  Creation:   Tue Jul 5 17:24:35 PST 2005
//
//  Modifications:
//
// ****************************************************************************

avtANSYSFileFormat::avtANSYSFileFormat(const char *filename)
    : avtSTSDFileFormat(filename), title()
{
    meshDS = 0;

#ifdef MDSERVER
    if(!ReadFile(filename, 100))
    {
        EXCEPTION1(InvalidFilesException, filename);
    }
#endif
}

// ****************************************************************************
// Method: avtANSYSFileFormat::~avtANSYSFileFormat
//
// Purpose: 
//   Destructor for avtANSYSFileFormat class.
//
// Programmer: Brad Whitlock
// Creation:   Wed Jul 6 15:59:07 PST 2005
//
// Modifications:
//   
// ****************************************************************************

avtANSYSFileFormat::~avtANSYSFileFormat()
{
    FreeUpResources();
}

// ****************************************************************************
//  Method: avtANSYSFileFormat::FreeUpResources
//
//  Purpose:
//      When VisIt is done focusing on a particular timestep, it asks that
//      timestep to free up any resources (memory, file descriptors) that
//      it has associated with it.  This method is the mechanism for doing
//      that.
//
//  Programmer: Brad Whitlock
//  Creation:   Tue Jul 5 17:24:35 PST 2005
//
// ****************************************************************************

void
avtANSYSFileFormat::FreeUpResources(void)
{
    debug4 << "avtANSYSFileFormat::FreeUpResources" << endl;
    if(meshDS)
    {
        meshDS->Delete();
        meshDS = 0;
    }

    title = "";
}

// ****************************************************************************
// Method: avtANSYSFileFormat::ActivateTimestep
//
// Purpose: 
//   Called when we're activating the current time step.
//
// Programmer: Brad Whitlock
// Creation:   Wed Jul 6 15:59:34 PST 2005
//
// Modifications:
//   
// ****************************************************************************

void
avtANSYSFileFormat::ActivateTimestep()
{
    debug4 << "avtANSYSFileFormat::ActivateTimestep" << endl;
#ifndef MDSERVER
    if(meshDS == 0)
    {
        ReadFile(filename, ALL_LINES);
    }
#endif
}

// ****************************************************************************
// Method: avtANSYSFileFormat::ReadFile
//
// Purpose: 
//   This method reads the ANSYS file and constructs a dataset that gets
//   returned later in the GetMesh method.
//
// Arguments:
//   name   : The name of the file to read.
//   nLines : The max number of lines to read from the file.
//
// Returns:    True if the file looks like a ANSYS bulk data file.
//
// Programmer: Brad Whitlock
// Creation:   Wed Jul 6 16:00:08 PST 2005
//
// Modifications:
//   Brad Whitlock, Wed Jul 27 10:55:58 PDT 2005
//   Fixed for win32.
//
//    Mark C. Miller, Thu Mar 30 16:45:35 PST 2006
//    Made it use VisItStat instead of stat
//
//    Brad Whitlock, Wed May 16 12:02:53 PDT 2012
//    Change how we read the lines so it is more robust.
//
// ****************************************************************************

bool
avtANSYSFileFormat::ReadFile(const char *name, int nLines)
{
    const char *mName = "avtANSYSFileFormat::ReadFile: ";
    const char *timerName = "Reading ANSYS file";
    int total = visitTimer->StartTimer();
    
    debug4 << mName << endl;

    // Open the file.
    ifstream ifile(name);
    if (ifile.fail())
    {
        visitTimer->StopTimer(total, timerName);
        EXCEPTION1(InvalidFilesException, name);
    }

    // Determine the file size and come up with an estimate of the
    // number of vertices and cells so we can size the points and cells.
    int nPoints = 100;
    int nCells = 100;
    if(nLines == ALL_LINES)
    {
        FileFunctions::VisItStat_t statbuf;
        FileFunctions::VisItStat(name, &statbuf);
        FileFunctions::VisItOff_t fileSize = statbuf.st_size;

        // Make a guess about the number of cells and points based on
        // the size of the file.
        nPoints = fileSize / (FileFunctions::VisItOff_t) 190;
        nCells  = fileSize / (FileFunctions::VisItOff_t) 210;
    }
    vtkPoints *pts = vtkPoints::New();
    pts->Allocate(nPoints);

    vtkUnstructuredGrid *ugrid = vtkUnstructuredGrid::New();
    ugrid->SetPoints(pts);
    ugrid->Allocate(nCells);
    pts->Delete();

#define MAX_ANSYS_LINE 200
    char  line[MAX_ANSYS_LINE];
    float pt[3];
    vtkIdType   verts[8];
    bool  recognized = false;
    bool  fatalError = false;
    bool  readingCoordinates = false;
    bool  readingConnectivity = false;
    int   expectedLineLength = 0;

    int   firstFieldWidth = 8;
    int   fieldWidth = 16;
    int   fieldStart = 56;

    for(int lineIndex = 0; !ifile.eof(); ++lineIndex)
    {
        if(nLines != ALL_LINES && lineIndex >= nLines)
            break;

        // Get the line
        ifile.getline(line, MAX_ANSYS_LINE);
#if defined(_WIN32)
        int linelen = strlen(line);
#else
        int linelen = strlen(line)-1; // account for the end of line char.
#endif
        // If the line length is less than expected then pad with NULLs.
        if(expectedLineLength > 0 && linelen < expectedLineLength)
        {
             memset(line + linelen + 1, 0, (MAX_ANSYS_LINE - linelen - 1) * sizeof(char));
#if 0
             debug5 << "Padding line with NULLs" << endl;
             debug5 << line << endl;
#endif
        }

        // Give it a chance to break out of coordinate reading.
        if(readingCoordinates)
        {
            bool valid = true;
            for(int i = 0; i < firstFieldWidth && valid; ++i)
                valid &= (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9'));

            if(!valid)
            {                
                expectedLineLength = 0;
                readingCoordinates = false;
                continue;
            }
        }

        if(readingCoordinates)
        {
            char *valstart = line + fieldStart;
            char *valend = valstart + fieldWidth;
            pt[2] = atof(valstart);

            valstart -= fieldWidth;
            valend -= fieldWidth;
            *valend = '\0';
            pt[1] = atof(valstart);

            valstart -= fieldWidth;
            valend -= fieldWidth;
            *valend = '\0';
            pt[0] = atof(valstart);

#if 0
            debug4 << pt[0] << ", " << pt[1] << ", " << pt[2] << endl;
#endif
            pts->InsertNextPoint(pt);
        }
        else if(readingConnectivity)
        {
            // Get whether this cell is real from column 0
            line[fieldWidth] = '\0';
            bool realCell = atoi(line) > 0;
            if(!realCell)
            {
                expectedLineLength = 0;
                readingConnectivity = false;
                continue;
            }

            // Get the number of vertices in this cell from column 9.
            static const int ncellsColumn = 9;
            line[ncellsColumn * fieldWidth] = '\0';
            int nverts = atoi(line + (ncellsColumn-1) * fieldWidth);

            if(nverts == 8)
            {
                char *valstart = line + fieldStart;
                char *valend   = valstart + fieldWidth;
                for(int i = 0; i < 8; ++i)
                {
                    int ivalue = atoi(valstart);
                    verts[7-i] = (ivalue > 0) ? (ivalue - 1) : ivalue;
                    valstart -= fieldWidth;
                    valend   -= fieldWidth;
                    *valend = '\0';
                }

#if 0
                for(int j = 0; j < 8; ++j)
                    debug4 << ", " << verts[j];
                debug4 << endl;
#endif
                ugrid->InsertNextCell(VTK_HEXAHEDRON, 8, verts);
            }
            else
            {
                debug1 << mName << "The file " << name << " contained cells "
                       "that are not hexes."<< endl;

                fatalError = true;
                break;
            }
        }
        else if(STRNCASECMP(line, "NBLOCK", 6) == 0)
        {
            char *comma = strstr(line, ",");
            if(comma != 0)
            {
                char *comma2 = strstr(comma+1, ",");
                if(comma2 != 0)
                {
                    *comma2 = '\0';
                    char *cols = comma + 1;
                    debug4 << mName << "Coordinate data stored in "
                           << atoi(cols) << " columns." << endl;
                    recognized = true;
                }
            }

            // Get the field format string. Use it to set expectedLineLength,
            // fieldWidth, and fieldStart.
            ifile.getline(line, 1024);
            if(line[0] == '(')
            {
                InterpretFormatString(line, firstFieldWidth, fieldStart, fieldWidth,
                                      expectedLineLength);
                debug4 << mName << "firstFieldWidth=" << firstFieldWidth
                       << ", fieldStart=" << fieldStart
                       << ", fieldWidth=" << fieldWidth 
                       << ", expectedLineLength=" << expectedLineLength
                       << endl;
                readingCoordinates = true;
            }
            else
            {
                debug1 << mName << "Malformed format string: " << line << endl;
                fatalError = true;
            }
        }
        else if(STRNCASECMP(line, "EBLOCK", 6) == 0)
        {
            char *comma = strstr(line, ",");
            if(comma != 0)
            {
                char *comma2 = strstr(comma+1, ",");
                if(comma2 != 0)
                {
                    *comma2 = '\0';
                    char *cols = comma + 1;
                    debug4 << mName << "Connectivity data stored in "
                           << atoi(cols) << " columns." << endl;
                    recognized = true;
                }
            }

            // Get the field format string. Use it to set expectedLineLength,
            // fieldWidth, and fieldStart.
            ifile.getline(line, 1024);
            if(line[0] == '(')
            {
                InterpretFormatString(line, firstFieldWidth, fieldStart, fieldWidth,
                                      expectedLineLength);
                debug4 << mName << "firstFieldWidth=" << firstFieldWidth
                       << ", fieldStart=" << fieldStart
                       << ", fieldWidth=" << fieldWidth
                       << ", expectedLineLength=" << expectedLineLength 
                       << endl; 
                readingConnectivity = true;
            }
            else
            {
                debug1 << mName << "Malformed format string: " << line << endl;
                fatalError = true;
            }
        }
        else if(STRNCASECMP(line, "/COM", 4) == 0)
        {
            if(title == "")
                title = std::string(line+6);
            recognized = true;
        }
        else if(STRNCASECMP(line, "/TITLE", 6) == 0)
        {
            title = std::string(line+8);
            recognized = true;
        }
        else if(STRNCASECMP(line, "/BATCH",  6) == 0 ||
                STRNCASECMP(line, "/NOPR",   5) == 0 ||
                STRNCASECMP(line, "/CONFIG", 7) == 0 ||
                STRNCASECMP(line, "/NOLIST", 7) == 0)
        {
            recognized = true;
        }
        else
        {
            expectedLineLength = 0;
            readingCoordinates = false;
            readingConnectivity = false;
        }
    }

    if(recognized && nLines == ALL_LINES && !fatalError)
        meshDS = ugrid;
    else
        ugrid->Delete();

    visitTimer->StopTimer(total, timerName);

    return recognized;
}

// ****************************************************************************
// Method: avtANSYSFileFormat::Interpret
//
// Purpose: 
//   Interprets the format string to deduce the field width and the line length
//   prescribed by the format string.
//
// Arguments:
//   fmt        : The format string.
//   fieldWidth : The width of an individual field.
//   linelen    : The length of the fields in the format string.
//
// Programmer: Brad Whitlock
// Creation:   Thu Jul 7 09:55:59 PDT 2005
//
// Modifications:
//   
// ****************************************************************************

void
avtANSYSFileFormat::Interpret(const char *fmt, int &fieldWidth,
    int &linelen) const
{
    int i0, i1, i2;

    debug4 << "avtANSYSFileFormat::Interpret: " << fmt << endl;

    // Example: 6e16.9
    if(sscanf(fmt, "%de%d.%d", &i0, &i1, &i2) == 3)
    {
        linelen = i0 * i1 / 2;
        fieldWidth = i1;
    }
    // Example: 19i7
    else if(sscanf(fmt, "%di%d", &i0, &i1) == 2)
    {
        linelen = i0 * i1;
        fieldWidth = i1;
    }
    else
    {
        debug1 << "Invalid format string: " << fmt << endl;
    }
}

// ****************************************************************************
// Method: avtANSYSFileFormat::InterpretFormatString
//
// Purpose: 
//   Interprets a format string to get fieldStart, fieldWidth, and the expected
//   line length that the format string wants.
//
// Arguments:
//   line               : The line containing the format string.
//   firstFieldWidth    : The width of the first field.
//   fieldStart         : The starting location of the first field that we
//                        want to read.
//   fieldWidth         : The length of the field that we want to read.
//   expectedLineLength : The length of the lines that should be considered
//                        for parsing as coords or connectivity.
//
// Programmer: Brad Whitlock
// Creation:   Thu Jul 7 09:57:23 PDT 2005
//
// Modifications:
//   Brad Whitlock, Wed May 16 13:36:03 PDT 2012
//   Pass out the width of the first field.
//
// ****************************************************************************

void
avtANSYSFileFormat::InterpretFormatString(char *line, int &firstFieldWidth,
    int &fieldStart, int &fieldWidth, int &expectedLineLength) const
{
    char *fmt = line + 1;
    char *ptr = 0;

    expectedLineLength = 0;
    bool keepGoing = true;
    bool first = true;
    while(keepGoing)
    {
        int linelen = 0;

        if((ptr = strstr(fmt, ",")) != 0)
        {
            *ptr = '\0';
            Interpret(fmt, fieldWidth, linelen);
            if(first)
            {
                first = false;
                firstFieldWidth = fieldWidth;
            }
            expectedLineLength += linelen;
            fmt = ptr + 1;
        }
        else if((ptr = strstr(fmt, ")")) != 0)
        {
            *ptr = '\0';
            Interpret(fmt, fieldWidth, linelen);
            if(first)
            {
                first = false;
                firstFieldWidth = fieldWidth;
            }
            expectedLineLength += linelen;
            keepGoing = false;
        }
        else
            keepGoing = false;
    }

    fieldStart = expectedLineLength - fieldWidth;
}

// ****************************************************************************
//  Method: avtANSYSFileFormat::PopulateDatabaseMetaData
//
//  Purpose:
//      This database meta-data object is like a table of contents for the
//      file.  By populating it, you are telling the rest of VisIt what
//      information it can request from you.
//
//  Programmer: Brad Whitlock
//  Creation:   Tue Jul 5 17:24:35 PST 2005
//
// ****************************************************************************

void
avtANSYSFileFormat::PopulateDatabaseMetaData(avtDatabaseMetaData *md)
{
    debug4 << "avtANSYSFileFormat::PopulateDatabaseMetaData" << endl;
    md->SetDatabaseComment(title);
    AddMeshToMetaData(md, "mesh", AVT_UNSTRUCTURED_MESH, NULL, 1, 1,
                      3, 3);
}


// ****************************************************************************
//  Method: avtANSYSFileFormat::GetMesh
//
//  Purpose:
//      Gets the mesh associated with this file.  The mesh is returned as a
//      derived type of vtkDataSet (ie vtkRectilinearGrid, vtkStructuredGrid,
//      vtkUnstructuredGrid, etc).
//
//  Arguments:
//      meshname    The name of the mesh of interest.  This can be ignored if
//                  there is only one mesh.
//
//  Programmer: Brad Whitlock
//  Creation:   Tue Jul 5 17:24:35 PST 2005
//
// ****************************************************************************

vtkDataSet *
avtANSYSFileFormat::GetMesh(const char *meshname)
{
    debug4 << "avtANSYSFileFormat::GetMesh" << endl;
    vtkUnstructuredGrid *ugrid = vtkUnstructuredGrid::New();
    ugrid->ShallowCopy(meshDS);

    return ugrid;
}


// ****************************************************************************
//  Method: avtANSYSFileFormat::GetVar
//
//  Purpose:
//      Gets a scalar variable associated with this file.  Although VTK has
//      support for many different types, the best bet is vtkFloatArray, since
//      that is supported everywhere through VisIt.
//
//  Arguments:
//      varname    The name of the variable requested.
//
//  Programmer: Brad Whitlock
//  Creation:   Tue Jul 5 17:24:35 PST 2005
//
// ****************************************************************************

vtkDataArray *
avtANSYSFileFormat::GetVar(const char *varname)
{
    debug4 << "avtANSYSFileFormat::GetVar" << endl;

    // Can't read variables yet.
    EXCEPTION1(InvalidVariableException, varname);
}


// ****************************************************************************
//  Method: avtANSYSFileFormat::GetVectorVar
//
//  Purpose:
//      Gets a vector variable associated with this file.  Although VTK has
//      support for many different types, the best bet is vtkFloatArray, since
//      that is supported everywhere through VisIt.
//
//  Arguments:
//      varname    The name of the variable requested.
//
//  Programmer: Brad Whitlock
//  Creation:   Tue Jul 5 17:24:35 PST 2005
//
// ****************************************************************************

vtkDataArray *
avtANSYSFileFormat::GetVectorVar(const char *varname)
{
    debug4 << "avtANSYSFileFormat::GetVectorVar" << endl;

    // Can't read variables yet.
    EXCEPTION1(InvalidVariableException, varname);
}


