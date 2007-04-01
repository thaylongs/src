/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkVisItUnstructuredGridReader.h,v $
  Language:  C++
  Date:      $Date: 2002/05/31 23:12:41 $
  Version:   $Revision: 1.47 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkVisItUnstructuredGridReader - read vtk unstructured grid data file
// .SECTION Description
// vtkVisItUnstructuredGridReader is a source object that reads ASCII or binary 
// unstructured grid data files in vtk format. (see text for format details).
// The output of this reader is a single vtkUnstructuredGrid data object.
// The superclass of this class, vtkVisItDataReader, provides many methods for
// controlling the reading of the data file, see vtkVisItDataReader for more
// information.
// .SECTION Caveats
// Binary files written on one system may not be readable on other systems.
// .SECTION See Also
// vtkUnstructuredGrid vtkVisItDataReader

#ifndef __vtkVisItUnstructuredGridReader_h
#define __vtkVisItUnstructuredGridReader_h

#include "vtkVisItDataReader.h"

class vtkUnstructuredGrid;

class vtkVisItUnstructuredGridReader : public vtkVisItDataReader
{
public:
  static vtkVisItUnstructuredGridReader *New();
  vtkTypeRevisionMacro(vtkVisItUnstructuredGridReader,vtkVisItDataReader);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Get the output of this reader.
  vtkUnstructuredGrid *GetOutput();
  vtkUnstructuredGrid *GetOutput(int idx)
    {return (vtkUnstructuredGrid *) this->vtkSource::GetOutput(idx); };
  void SetOutput(vtkUnstructuredGrid *output);
  
protected:
  vtkVisItUnstructuredGridReader();
  ~vtkVisItUnstructuredGridReader();

  void Execute();

  // Since the Outputs[0] has the same UpdateExtent format
  // as the generic DataObject we can copy the UpdateExtent
  // as a default behavior.
  void ComputeInputUpdateExtents(vtkDataObject *output);
  
private:
  vtkVisItUnstructuredGridReader(const vtkVisItUnstructuredGridReader&);  // Not implemented.
  void operator=(const vtkVisItUnstructuredGridReader&);  // Not implemented.
};

#endif


