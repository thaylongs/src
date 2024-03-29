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
//                              avtH5PartWriter.C                            //
// ************************************************************************* //

#include <visit-config.h>
#include <avtH5PartWriter.h>

// VisIt
#include <avtDatabaseMetaData.h>

#include <avtCallback.h>
#include <InvalidVariableException.h>
#include <InvalidFilesException.h>
#include <NonCompliantFileException.h>
#include <BadIndexException.h>
#include <DebugStream.h>
#include <TimingsManager.h>

#include <DBOptionsAttributes.h>
#include <Expression.h>

// H5Part
#include <H5Part.h>
#include <H5Block.h>
#include <H5BlockTypes.h>

// FastBit
#ifdef HAVE_LIBFASTBIT
  #include <fastbit-config.h>

  #if FASTBIT_IBIS_INT_VERSION < 1020000
    #error "The H5Part plugin requires FastBit 1.2.0 or newer."
  #endif

  #include "hdf5_fastquery.h"
  #include "HistogramCache.h"

  #include <avtDataRangeSelection.h>
  #include <avtHistogramSpecification.h>
  #include <avtIdentifierSelection.h>
#endif

// VTK
#include <vtkCell.h>
#include <vtkCellData.h>
#include <vtkCellTypes.h>
#include <vtkCellArray.h>
#include <vtkPointData.h>
#include <vtkVisItCellDataToPointData.h>
#include <vtkUnsignedIntArray.h>
#include <vtkFloatArray.h>
#include <vtkDoubleArray.h>
#include <vtkPolyData.h>
#include <vtkRectilinearGrid.h>
#include <vtkStructuredGrid.h>
#include <vtkUnstructuredGrid.h>

#ifdef PARALLEL
#include <avtParallel.h>
#endif

#ifndef WIN32
#include <unistd.h>
#endif
#include <snprintf.h>

int    avtH5PartWriter::INVALID_CYCLE = -INT_MAX;
double avtH5PartWriter::INVALID_TIME = -DBL_MAX;

// ****************************************************************************
//  Method: avtH5PartWriter::avtH5PartWriter
//
//  Purpose:
//      Gets the H5Part writer options
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//
// ****************************************************************************

avtH5PartWriter::avtH5PartWriter(DBOptionsAttributes *writeOpts)
{
    // Defaults
    addFastBitIndexing = true;
    sortedKey = std::string("unsorted");
    createParentFile = false;
    
    parentFilename = std::string("visit_ex_db_parent");
    
    // Check options
    if (writeOpts != NULL)
    {
        for (int i = 0; i < writeOpts->GetNumberOfOptions(); ++i)
        {
            if (writeOpts->GetName(i) == "Add FastBit indexing")
                addFastBitIndexing = writeOpts->GetBool("Add FastBit indexing");

            else if (writeOpts->GetName(i) == "Sort variable")
                sortedKey = writeOpts->GetString("Sort variable");

            else if (writeOpts->GetName(i) == "Create a parent file")
                createParentFile = writeOpts->GetBool("Create a parent file");

            else if (writeOpts->GetName(i) == "Parent file name")
                parentFilename = writeOpts->GetString("Parent file name");

        }
    }
    
    parentFilename += std::string(".h5part");
}


// ****************************************************************************
//  Method: avtH5PartWriter::~avtH5PartWriter
//
//  Purpose:
//      Destructor
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//
// ****************************************************************************

avtH5PartWriter::~avtH5PartWriter()
{
}


// ****************************************************************************
//  Method: avtH5PartWriter::OpenFile
//
//  Purpose:
//      Opens the H5Part file
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//
// ****************************************************************************

void
avtH5PartWriter::OpenFile(const std::string &stemname, int nb)
{
    filename = stemname + std::string(".h5part");

    int mode = writeContext.Rank() == 0 ? H5PART_WRITE : H5PART_APPEND;

    file = H5PartOpenFile( filename.c_str(), mode );
    
    if (!file)
        EXCEPTION1(InvalidFilesException, filename);

    // This function was once supported by H5Part and will be again in the new
    // release. Until it is widely available, comment it out.
    if (H5PartFileIsValid(file) != H5PART_SUCCESS)
    {
        debug1 << "avtH5PartWriter::OpenFile: "
               << "H5PartFileIsValid check failed." << std::endl;

        H5PartCloseFile(file);
        EXCEPTION1(InvalidFilesException, filename);
    }

    if (H5PartSetStep(file, 0) != H5PART_SUCCESS)
    {
      int ts = GetInput()->GetInfo().GetAttributes().GetTimeIndex();

      std::ostringstream msg;
      msg << "Cannot activate time step " << ts << " for file"
          << filename << ".";

      debug1 << "avtH5PartWriter::OpenFile: "
             << msg.str() << std::endl;

      EXCEPTION2(NonCompliantFileException, "H5Part WriteChunk",
                 msg.str());
    }
}


// ****************************************************************************
//  Method: avtH5PartWriter::WriteHeaders
//
//  Purpose:
//      Gets the mesh and variables to be written
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//
// ****************************************************************************

void
avtH5PartWriter::WriteHeaders(const avtDatabaseMetaData *md,
                              const std::vector<std::string> &scalars,
                              const std::vector<std::string> &vectors,
                              const std::vector<std::string> &materials)
{
    time     = GetTime();
    cycle    = GetCycle();

    if(  writeContext.Rank() == 0 )
    {
      if (cycle != INVALID_CYCLE)
      {
        if( H5PartWriteStepAttrib ( file, "Cycle", H5PART_INT32, &cycle, 1 ) != H5PART_SUCCESS)
          {
            debug1 << "avtH5PartWriter::OpenFile: "
                   << "H5PartWriteStepAttrib failed" << std::endl;
            
            H5PartCloseFile(file);
            EXCEPTION1(InvalidFilesException, filename);
          }
      }

      if (time != INVALID_TIME )
      {
        if( H5PartWriteStepAttrib ( file, "Time", H5PART_FLOAT64, &time, 1 ) != H5PART_SUCCESS)
          {
            debug1 << "avtH5PartWriter::OpenFile: "
                   << "H5PartWriteStepAttrib failed" << std::endl;
            
            H5PartCloseFile(file);
            EXCEPTION1(InvalidFilesException, filename);
          }
      }
    }

    meshname = GetMeshName(md);
    
    variableList = scalars;

    if( addFastBitIndexing )
    {
        bool foundSortedKey = false;

     // for( const auto &varName: variableList )
        for( int i=0; i<variableList.size(); ++i)
        {
         // if( varName == sortedKey )
            if( variableList[i] == sortedKey )
            {
                foundSortedKey = true;
                break;
            }
        }

        if( sortedKey != std::string("unsorted") && !foundSortedKey )
        {
            EXCEPTION2(NonCompliantFileException, "H5Part WriteHeaders",
                       "Can not find the specified sortedKey variable");
        }
    }
}


// ****************************************************************************
//  Method: avtH5PartWriter::WriteChunk
//
//  Purpose:
//      This writes out one chunk of an avtDataset.
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//
// ****************************************************************************

void
avtH5PartWriter::WriteChunk(vtkDataSet *ds, int chunk)
{
    switch (ds->GetDataObjectType())
    {
       case VTK_POLY_DATA:
         WritePolyData((vtkPolyData *) ds, chunk);
         break;

       default:
         EXCEPTION1(ImproperUseException, "Unsupported mesh type");
    }
}


// ****************************************************************************
//  Method: avtH5PartWriter::CloseFile
//
//  Purpose:
//      Closes the file.
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//
// ****************************************************************************

void
avtH5PartWriter::CloseFile(void)
{
    H5PartCloseFile(file);

    // The output is serial so if the last rank ...
    if( writeContext.Rank() == writeContext.Size()-1 )
    {
#ifdef HAVE_LIBFASTBIT
        // Add in the FastBit indexing
        if( addFastBitIndexing )
        {
          // Build the indexes for this time step only which is always
          // step#0. It like the data will be externally linked.
          HDF5_FQ fqReader;
          fqReader.openFile(filename.c_str(), H5PART_APPEND, true);
          fqReader.buildSpecificTimeIndex(0);
          fqReader.closeFile();
        }
#endif

        // Create a parent file and a link to this file.
        if( createParentFile )
        {
            WriteParentFile();
        }
    }
}


// ****************************************************************************
//  Method: avtH5PartWriter::SequentialOutput
//
//  Purpose:
//    Tell the writer whether the format needs MPI-rank sequential access to
//    write the output file.
//
//  Returns: True because we want to have each domain append to the existing
//           file that was created by its write group leader.
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//
// ****************************************************************************

bool
avtH5PartWriter::SequentialOutput() const
{
    return true;
}


// ****************************************************************************
//  Method: avtH5PartWriter::WriteUnstructuredMesh
//
//  Purpose: 
//    Writes one unstructured mesh's data as a H5Part zone.
//
//  Arguments:
//    sg : The unstructured data to save.
//    chunk : The domain id of the dataset.
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//
// ****************************************************************************

void
avtH5PartWriter::WriteUnstructuredMesh(vtkUnstructuredGrid *ug, int chunk)
{
    int dim = GetInput()->GetInfo().GetAttributes().GetSpatialDimension();
    int npts = ug->GetNumberOfPoints();
    int nzones = ug->GetNumberOfCells();

    // Write the variables line
    std::vector<std::string> coordVars;
    coordVars.push_back("X");
    coordVars.push_back("Y");
    if(dim > 2)
        coordVars.push_back("Z");

    //
    // Count the various cell types.
    //
    int nhex = 0;
    int ntet = 0;
    int npyr = 0;
    int nwdg = 0;
    int ntri = 0;
    int nquad = 0;
    for (int c = 0 ; c < nzones ; c++)
    {
        vtkCell *cell = ug->GetCell(c);
        switch (cell->GetCellType())
        {
          case VTK_HEXAHEDRON:
            nhex++;
            break;
          case VTK_TETRA:
            ntet++;
            break;
          case VTK_WEDGE:
            nwdg++;
            break;
          case VTK_PYRAMID:
            npyr++;
            break;
          case VTK_TRIANGLE:
            ntri++;
            break;
          case VTK_QUAD:
            nquad++;
            break;
          default:
            // ignore the rest
            break;
        }
    }
}


// ****************************************************************************
//  Method: avtH5PartWriter::WritePolyData
//
//  Purpose:
//    Saves a polydata dataset to H5Part format.
//
// Arguments:
//    pd    : The polydata to save.
//    chunk : The polydata to save.
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//
// ****************************************************************************

void
avtH5PartWriter::WritePolyData(vtkPolyData *pd, int chunk)
{
    if(pd->GetPolys()->GetNumberOfCells() > 0)
    {
        H5PartCloseFile(file);
        EXCEPTION1(ImproperUseException,
                   "The polydata dataset contains polygons "
                   "and that is not currently supported in the H5Part writer.");
    }

    if(pd->GetStrips()->GetNumberOfCells() > 0)
    {
        H5PartCloseFile(file);
        EXCEPTION1(ImproperUseException,
                   "The polydata dataset contains poly strips "
                   "and that is not currently supported in the H5Part writer.");
    }

    int nPoints = pd->GetVerts()->GetNumberOfCells();
    int nlines  = pd->GetLines()->GetNumberOfCells();

    H5PartSetChunkSize( file, nPoints );
    H5PartDefineStepName( file, "Step#0", 0 );

    vtkPoints *vtk_pts = pd->GetPoints();

    WritePoints(vtk_pts);
    WriteDataArrays(pd);
}


// ****************************************************************************
//  Method: avtH5PartWriter::WriteDataArrays
//
//  Purpose: 
//     Writes the data arrays for the dataset.
//
//  Arguments:
//    ds1 : The dataset
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//
// ****************************************************************************

void
avtH5PartWriter::WriteDataArrays(vtkDataSet *ds1)
{
    h5part_int64_t nparticles = ds1->GetNumberOfPoints();

    H5PartSetNumParticles( file, nparticles );

    vtkVisItCellDataToPointData *c2p = vtkVisItCellDataToPointData::New();
    c2p->SetInputData(ds1);
    c2p->Update();
    vtkUnstructuredGrid *ds2 = (vtkUnstructuredGrid*)(c2p->GetOutput());

    vtkPointData *pd1 = ds1->GetPointData();
    vtkPointData *pd2 = ds2->GetPointData();

    for (size_t v = 0 ; v < variableList.size() ; v++)
    {
        const char *varName = variableList[v].c_str();
        
        vtkDataArray *arr = pd1->GetArray(varName);

        if (!arr)
        {
            arr = pd2->GetArray(varName);

            if (!arr)
                EXCEPTION1(InvalidVariableException,
                           std::string("Couldn't find array ") +
                           variableList[v] + ".");
        }

        int ncomps = arr->GetNumberOfComponents();

        if (ncomps == 1)
        {
            if (arr->GetDataType() == VTK_FLOAT)
            {
                if (H5PartAppendDataFloat32(file, varName,
                    static_cast<h5part_float32_t*>(arr->GetVoidPointer(0)))
                    != H5PART_SUCCESS)
                {
                    H5PartCloseFile(file);
                    
                    EXCEPTION1(ImproperUseException,
                               std::string("Couldn't save array ") +
                               variableList[v] + ".");
                }
            }
            else if (arr->GetDataType() == VTK_DOUBLE)
            {
                if (H5PartAppendDataFloat64(file, varName,
                    static_cast<h5part_float64_t*>(arr->GetVoidPointer(0)))
                    != H5PART_SUCCESS)
                {
                    H5PartCloseFile(file);

                    EXCEPTION1(ImproperUseException,
                               std::string("Couldn't save array ") +
                               variableList[v] + ".");

                }
            }
        }
    }

    c2p->Delete();
}


// ****************************************************************************
//  Method: avtH5PartWriter::WritePoints
//
//  Purpose: 
//    Write the VTK points to the file.
//
//  Arguments:
//    pts : The points to write.
//    dim : How many of the coordinate dimensions should be written (2 or 3).
//
//  Programmer: Allen Sanderson
//  Creation:   31 Jan 2017
//   
// ****************************************************************************

void
avtH5PartWriter::WritePoints(vtkPoints *pts)
{ 
    h5part_int64_t status = H5PART_SUCCESS;
    h5part_int64_t nparticles = pts->GetNumberOfPoints();

    int dim = GetInput()->GetInfo().GetAttributes().GetSpatialDimension();

    H5PartSetNumParticles( file, nparticles );

    vtkDataArray *arr = pts->GetData();
    
    if( pts->GetDataType() == VTK_FLOAT )
    {
        float *ptr = (float *) arr->GetVoidPointer(0);

        h5part_float32_t *coordsWriteX, *coordsWriteY, *coordsWriteZ;
        coordsWriteX = new h5part_float32_t[nparticles];
        coordsWriteY = new h5part_float32_t[nparticles];
        if( dim == 3 )
          coordsWriteZ = new h5part_float32_t[nparticles];
        
        for (int i=0; i<nparticles; ++i)
        {
            coordsWriteX[i] = *ptr++;
            coordsWriteY[i] = *ptr++;
            if( dim == 3 )
              coordsWriteZ[i] = *ptr++;
        }
        
        status = H5PartAppendDataFloat32(file, "x", coordsWriteX);      
        status = H5PartAppendDataFloat32(file, "y", coordsWriteY);
        
        if( dim == 3 )
          status = H5PartAppendDataFloat32(file, "z", coordsWriteZ);

        delete[] coordsWriteX;
        delete[] coordsWriteY;
        delete[] coordsWriteZ;
    }
    else if( pts->GetDataType() == VTK_DOUBLE )
    {
        double *ptr = (double *) arr->GetVoidPointer(0);

        h5part_float64_t *coordsWriteX, *coordsWriteY, *coordsWriteZ;
        coordsWriteX = new h5part_float64_t[nparticles];
        coordsWriteY = new h5part_float64_t[nparticles];
        if( dim == 3 )
          coordsWriteZ = new h5part_float64_t[nparticles];
        
        for (int i=0; i<nparticles; ++i)
        {
            coordsWriteX[i] = *ptr++;
            coordsWriteY[i] = *ptr++;
            if( dim == 3 )
              coordsWriteZ[i] = *ptr++;
        }
        
        status = H5PartAppendDataFloat64(file, "x", coordsWriteX);      
        status = H5PartAppendDataFloat64(file, "y", coordsWriteY);
        
        if( dim == 3 )
          status = H5PartAppendDataFloat64(file, "z", coordsWriteZ);

        delete[] coordsWriteX;
        delete[] coordsWriteY;
        delete[] coordsWriteZ;
    }
    else
    {
        H5PartCloseFile(file);
        
        EXCEPTION2(NonCompliantFileException, "H5Part WritePoints",
                   "Unsupported value type for coordinates. "
                   "(Supported tyes are FLOAT32 and FLOAT64)");
    }

    if (status != H5PART_SUCCESS)
    {
        H5PartCloseFile(file);
        
        EXCEPTION2(NonCompliantFileException, "H5Part WritePoints",
                   "Could not write coordinates.");
    }
}


// ****************************************************************************
// Method: avtH5PartWriter::WriteParentFile
//
// Purpose: 
//   Write a HDF5 file that externally links to the data file. 
//
// Programmer: Allen Sanderson
// Creation:   31 Jan 2017
//
// ****************************************************************************

void
avtH5PartWriter::WriteParentFile()
{
    int timestep = GetInput()->GetInfo().GetAttributes().GetTimeIndex();

    herr_t status;
    hid_t index_id = 0;
    
    // Try to open the parent file initally.
    hid_t file_id = H5Fopen(parentFilename.c_str(), H5F_ACC_RDWR, H5P_DEFAULT);

    // File opened ...
    if( file_id >= 0 )
    {      
        // If indexing get the indexing group.
        if( addFastBitIndexing )
        {
            index_id = H5Gopen(file_id, "__H5PartIndex__", H5P_DEFAULT);

            if (index_id < 0)
            {
                H5Fclose(file_id);
                
                EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                           "H5Gopen (index group) failed");
            }
        }
    }
    // Could not open the parent file so try to create it.    
    else
    {
        file_id = H5Fcreate(parentFilename.c_str(),
                            H5F_ACC_EXCL, H5P_DEFAULT, H5P_DEFAULT);

        // Failed to create the file so bail out.
        if( file_id < 0 )
        {
            EXCEPTION1(InvalidFilesException, parentFilename.c_str());
        }

        // If indexing add the indexing group and the sortedKey attribute.
        if( addFastBitIndexing )
        {
            index_id = H5Gcreate(file_id, "__H5PartIndex__",
                                 H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
        
            if (index_id < 0)
            {
                H5Fclose(file_id);

                EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                           "H5Gcreate (index group) failed");
            }

            // There is zero gaurantee that the data was sorted
            // initally so set the attribute to unsorted.
            std::string aname("sortedKey");
          
            // Create the data space for the string attribute.
            hid_t dataspace_id = H5Screate(H5S_SCALAR);
            if( dataspace_id < 0 )
            {
                H5Fclose(file_id);
                
                EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                           "H5Screate failed");
            }
        
            hid_t   type_id = H5Tcopy(H5T_C_S1);
            if( type_id < 0 )
            {
                H5Fclose(file_id);

                EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                           "H5Tcopy failed");
            }

            hsize_t size = sortedKey.length();
            if( (status = H5Tset_size(type_id, size)) < 0 )
            {
                H5Sclose(dataspace_id);
                H5Tclose(type_id);
                H5Fclose(file_id);

                EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                           "H5Tset_size failed");
            }

            // Create the attribute.
            hid_t a_id = H5Acreate(file_id, aname.c_str(), type_id,
                                   dataspace_id,
                                   H5P_DEFAULT, H5P_DEFAULT);
        
            if( a_id < 0 )
            {
                H5Sclose(dataspace_id);
                H5Tclose(type_id);
                H5Fclose(file_id);

                EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                           "H5Acreate failed");
            }
        
            // Write the attribute data.
            if( (status = H5Awrite(a_id, type_id, sortedKey.c_str())) < 0 )
            {
                H5Sclose(dataspace_id);
                H5Sclose(a_id);
                H5Tclose(type_id);
                H5Fclose(file_id);

                EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                           "H5Awrite failed");
            }
        
            // Close the attribute.
            if( (status = H5Aclose(a_id)) < 0 )
            {
                H5Sclose(dataspace_id);
                H5Tclose(type_id);
                H5Fclose(file_id);

                EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                           "H5Aclose failed");
            }
        
            // Close the data space.
            if( (status = H5Sclose(dataspace_id)) < 0 )
            {
                H5Tclose(type_id);
                H5Fclose(file_id);

                EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                           "H5Sclose failed");
            }
        
            // Close the data type.
            if( (status = H5Tclose(type_id)) < 0 )
            {
                H5Fclose(file_id);

                EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                           "H5Tclose failed");
            }
        }
    }
  
    // Create an external like to the data.
    const int buffSize = 1024;
    char stepName[buffSize];
    SNPRINTF(stepName, buffSize, "Step#%d", timestep);
    
    if( (status = H5Lcreate_external(filename.c_str(), "Step#0", file_id,
                                     stepName, H5P_DEFAULT, H5P_DEFAULT)) < 0 )
    {
        H5Fclose(file_id);

        EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                   "H5Lcreate_external (steps) failed");
    }

    // Create an external like to the index data.
    if( addFastBitIndexing )
    {
        if( (status = H5Lcreate_external(filename.c_str(),
                                         "__H5PartIndex__/Step#0",
                                         index_id, stepName,
                                         H5P_DEFAULT, H5P_DEFAULT)) < 0 )
        {
            H5Gclose(index_id);
            H5Fclose(file_id);

            EXCEPTION2(NonCompliantFileException, "H5Part WriteParentFile",
                       "H5Lcreate_external (indexing) failed");
        }
    }    

    if( addFastBitIndexing )
      H5Gclose(index_id);
    
    H5Fclose(file_id);
}

