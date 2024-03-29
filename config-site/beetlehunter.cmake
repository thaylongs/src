##
## Setup VISITHOME variables.
##
SET(VISITHOME /home/biagas2/visit/thirdparty/2.13.0)

## Compiler flags.
##
VISIT_OPTION_DEFAULT(VISIT_C_COMPILER gcc TYPE FILEPATH)
VISIT_OPTION_DEFAULT(VISIT_CXX_COMPILER g++ TYPE FILEPATH)
VISIT_OPTION_DEFAULT(VISIT_C_FLAGS " -m64 -fPIC -fvisibility=hidden" TYPE STRING)
VISIT_OPTION_DEFAULT(VISIT_CXX_FLAGS " -m64 -fPIC -fvisibility=hidden" TYPE STRING)

##
## VisIt QT5 Option
##
VISIT_OPTION_DEFAULT(VISIT_QT5 ON TYPE BOOL)

##
## VisIt Paradis Option
##
VISIT_OPTION_DEFAULT(VISIT_PARADIS OFF TYPE BOOL)

##
## VisIt Thread Option
##
VISIT_OPTION_DEFAULT(VISIT_THREAD OFF TYPE BOOL)

##############################################################
##
## Database reader plugin support libraries
##
## The HDF4, HDF5 and NetCDF libraries must be first so that
## their libdeps are defined for any plugins that need them.
##
## For libraries with LIBDEP settings, order matters.
## Libraries with LIBDEP settings that depend on other
## Library's LIBDEP settings must come after them.
##############################################################
##

##
## Mesa
##
if(VISIT_USE_MESA)
  VISIT_OPTION_DEFAULT(VISIT_MESA_DIR ${VISITHOME}/mesa/7.10.2)
endif()

##
## Python
##
VISIT_OPTION_DEFAULT(VISIT_PYTHON_DIR ${VISITHOME}/python/2.7.11)

##
## PySide
##
VISIT_OPTION_DEFAULT(VISIT_PYSIDE_DIR ${VISITHOME}/pyside/2.0.0-2017.02.14)

##
## Qt
##
VISIT_OPTION_DEFAULT(VISIT_QT_DIR ${VISITHOME}/qt/5.6.1)

##
## VTK
##
SETUP_APP_VERSION(VTK 6.1.0)
VISIT_OPTION_DEFAULT(VISIT_VTK_DIR ${VISITHOME}/vtk/${VTK_VERSION})


##
## QWT
##
VISIT_OPTION_DEFAULT(VISIT_QWT_DIR ${VISITHOME}/qwt/6.1.2)

##
## BOOST
##
VISIT_OPTION_DEFAULT(VISIT_BOOST_DIR /home/biagas2/visit/boost_minimal_headers/1.60.0)

##
## MPICH
##
# Give VisIt information so it can install MPI into the binary distribution.
if (VISIT_PARALLEL)
  VISIT_OPTION_DEFAULT(VISIT_MPICH_DIR ${VISITHOME}/mpich/3.0.4)
  VISIT_OPTION_DEFAULT(VISIT_MPICH_INSTALL ON TYPE BOOL)
  # Tell VisIt the parallel compiler so it can deduce parallel flags
  VISIT_OPTION_DEFAULT(VISIT_MPI_COMPILER ${VISIT_MPICH_DIR}/bin/mpicc TYPE FILEPATH)
endif()

##
## AdvIO
##
VISIT_OPTION_DEFAULT(VISIT_ADVIO_DIR ${VISITHOME}/AdvIO/1.2)

##
## Boxlib
##
VISIT_OPTION_DEFAULT(VISIT_BOXLIB_DIR ${VISITHOME}/boxlib/1.3.5)

##
## CCMIO
##
VISIT_OPTION_DEFAULT(VISIT_CCMIO_DIR ${VISITHOME}/ccmio/2.6.1)

##
## CFITSIO
##
VISIT_OPTION_DEFAULT(VISIT_CFITSIO_DIR ${VISITHOME}/cfitsio/3006)

##
## SZIP
##
VISIT_OPTION_DEFAULT(VISIT_SZIP_DIR ${VISITHOME}/szip/2.1)

##
## ZLIB
##
VISIT_OPTION_DEFAULT(VISIT_ZLIB_DIR ${VISITHOME}/zlib/1.2.7)

##
## HDF5
##
VISIT_OPTION_DEFAULT(VISIT_HDF5_DIR ${VISITHOME}/hdf5/1.8.14)
VISIT_OPTION_DEFAULT(VISIT_HDF5_LIBDEP ${VISIT_SZIP_DIR}/lib sz ${VISIT_ZLIB_DIR}/lib z TYPE STRING)

##
## CGNS
##
VISIT_OPTION_DEFAULT(VISIT_CGNS_DIR ${VISITHOME}/cgns/3.2.1)
VISIT_OPTION_DEFAULT(VISIT_CGNS_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## Conduit
##
VISIT_OPTION_DEFAULT(VISIT_CONDUIT_DIR ${VISITHOME}/conduit/0.2.1)
VISIT_OPTION_DEFAULT(VISIT_CONDUIT_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## FastBit
##
SETUP_APP_VERSION(FASTBIT 2.0.3)
VISIT_OPTION_DEFAULT(VISIT_FASTBIT_DIR ${VISITHOME}/fastbit/${FASTBIT_VERSION})

##
## GDAL
##
VISIT_OPTION_DEFAULT(VISIT_GDAL_DIR ${VISITHOME}/gdal/1.10.0)

##
## H5Part
##
VISIT_OPTION_DEFAULT(VISIT_H5PART_DIR ${VISITHOME}/h5part/1.6.6)
VISIT_OPTION_DEFAULT(VISIT_H5PART_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## HDF4
##
VISIT_OPTION_DEFAULT(VISIT_HDF4_DIR ${VISITHOME}/hdf4/4.2.5)
VISIT_OPTION_DEFAULT(VISIT_HDF4_LIBDEP ${VISIT_SZIP_DIR}/lib sz ${VISIT_VTK_DIR}/lib vtkjpeg-${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION} TYPE STRING)

##
## MFEM 
##
VISIT_OPTION_DEFAULT(VISIT_MFEM_DIR ${VISITHOME}/mfem/3.3)

##
## Mili
##
VISIT_OPTION_DEFAULT(VISIT_MILI_DIR ${VISITHOME}/mili/15.1)
##

##
## NetCDF
##
VISIT_OPTION_DEFAULT(VISIT_NETCDF_DIR ${VISITHOME}/netcdf/4.1.1)
VISIT_OPTION_DEFAULT(VISIT_NETCDF_LIBDEP HDF5_LIBRARY_DIR hdf5_hl HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## Silo
##
VISIT_OPTION_DEFAULT(VISIT_SILO_DIR ${VISITHOME}/silo/4.10.2)
VISIT_OPTION_DEFAULT(VISIT_SILO_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## Xdmf
##
VISIT_OPTION_DEFAULT(VISIT_XDMF_DIR ${VISITHOME}/Xdmf/2.1.1)
VISIT_OPTION_DEFAULT(VISIT_XDMF_LIBDEP HDF5_LIBRARY_DIR hdf5  VTK_LIBRARY_DIRS vtklibxml2-${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}  TYPE STRING)

