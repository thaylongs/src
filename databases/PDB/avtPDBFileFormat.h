// ************************************************************************* //
//                           avtPDBFileFormat.h                              //
// ************************************************************************* //

#ifndef AVT_PDB_FILE_FORMAT_H
#define AVT_PDB_FILE_FORMAT_H

#include <avtSTSDFileFormat.h>
#include <PDBFactory.h>

// ****************************************************************************
// Class: avtPDBFileFormat
//
// Purpose:
//   Reads PDB files generated by the pF3d simulation code.
//
// Notes:      
//
// Programmer: Brad Whitlock
// Creation:   Wed Oct 9 08:01:41 PDT 2002
//
// Modifications:
//   
// ****************************************************************************

class avtPDBFileFormat : public avtSTSDFileFormat
{
  public:
                          avtPDBFileFormat(const char *);
    virtual              ~avtPDBFileFormat();
    
    virtual void          FreeUpResources(void);
    virtual const char   *GetType(void) { return "PDB File Format"; };
    
    virtual void         *GetAuxiliaryData(const char *var,
                                           const char *type,
                                           void *args,
                                           DestructorFunction &);

    virtual vtkDataSet   *GetMesh(const char *);
    virtual vtkDataArray *GetVar(const char *);
    virtual vtkDataArray *GetVectorVar(const char *);

    virtual void          PopulateDatabaseMetaData(avtDatabaseMetaData *);
    virtual void          PopulateIOInformation(avtIOInformation &);
  protected:

    // Data members
    PDBFactory factory;
    bool       initializedFactory;

    void       InitializeFactory();
};

#endif
