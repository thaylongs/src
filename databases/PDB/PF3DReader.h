#ifndef PF3D_READER_H
#define PF3D_READER_H
#include <PDBReader.h>

// ****************************************************************************
// Class: PF3DReader
//
// Purpose:
//   This class reads a PDB file generated by PF3D.
//
// Notes:      
//
// Programmer: Brad Whitlock
// Creation:   Thu Oct 10 08:48:46 PDT 2002
//
// Modifications:
//   Brad Whitlock, Tue Apr 29 13:26:31 PST 2003
//   I made it work with MTSD files.
//
//   Brad Whitlock, Thu Aug 7 16:54:57 PST 2003
//   Added cache argument to the constructor.
//
// ****************************************************************************

class PF3DReader : public PDBReader
{
public:
    PF3DReader(PDBfile *pdb, avtVariableCache *c);
    virtual ~PF3DReader();

    virtual bool Identify();
    virtual void GetTimeVaryingInformation(int, avtDatabaseMetaData *);
    virtual void PopulateDatabaseMetaData(avtDatabaseMetaData *);

    virtual void          GetCycles(std::vector<int> &cycles);
    virtual vtkDataSet   *GetMesh(int, const char *);
    virtual vtkDataArray *GetVar(int, const char *);
    virtual vtkDataArray *GetVectorVar(int, const char *);

protected:
    void GetMeshInfo(const char *meshName, float extents[6], int nNodes[3],
                     bool &ghostPresent, int first[3], int last[3]);
    void ComputeKludgeOffset();

    // Values that are read in when the file is opened.
    int    cycle;
    double dtime;
    double dx, dy, dz;       // Cell size
    double lx, ly, lz;       // Dimensions used in calculating extents.
    int    nx, ny, nz;       // Number of cells in each dimension for entire problem.
    int    nxg0, nyg0, nzg0; // Starting cell index for domain.
    int    nxg1, nyg1, nzg1; // End cell index for domain.
    int    nxl, nyl, nzl;    // Number of cells in each dimension for domain.
    int    ipol;             // Determines if certain variables exist on light mesh.
    int    domain;           // The domain index.
    int    nDomains;         // Number of domains for entire problem.

    int    kludgeOffset;     // Hack
};

#endif
