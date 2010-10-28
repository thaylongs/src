##
## /home/harrison37/hdrive/dev/branches/CPB3/src/svn_bin/build_visit generated host.cmake
## created: Mon Dec 14 16:22:27 PST 2009
## system: Linux beetown.llnl.gov 2.6.18-164.2.1.el5 #1 SMP Mon Sep 21 04:37:51 EDT 2009 i686 i686 i386 GNU/Linux
## by: harrison37

##
## Setup VISITHOME & VISITARCH variables.
##
SET(VISITHOME /scratch/harrison37/dev/libs)
SET(VISITARCH linux-i686_gcc-4.1)

VISIT_OPTION_DEFAULT(VISIT_PYTHON_FILTERS ON)

##
## Specify the location of the mesa.
##
VISIT_OPTION_DEFAULT(VISIT_MESA_DIR ${VISITHOME}/mesa/7.5/${VISITARCH})

##
## Specify the location of the vtk.
##
VISIT_OPTION_DEFAULT(VISIT_VTK_DIR ${VISITHOME}/vtk/5.0.0d/${VISITARCH}/lib/vtk-5.0/)

##
## Specify the Qt4 binary dir. 
## (qmake us used to locate & setup Qt4 dependencies)
##
VISIT_OPTION_DEFAULT(VISIT_QT_BIN /home/harrison37/apps/Trolltech/Qt-4.6.1/bin)

##
## Specify the location of the python.
##
VISIT_OPTION_DEFAULT(VISIT_PYTHON_DIR ${VISITHOME}/python/2.6.4/${VISITARCH})

##
## Compiler flags.
##

SET(CMAKE_BUILD_TYPE Debug)
VISIT_OPTION_DEFAULT(VISIT_C_COMPILER gcc)
VISIT_OPTION_DEFAULT(VISIT_CXX_COMPILER g++)
VISIT_OPTION_DEFAULT(VISIT_C_FLAGS "-fvisibility=hidden")
VISIT_OPTION_DEFAULT(VISIT_CXX_FLAGS "-Wno-deprecated -fPIC -fvisibility=hidden")

##
## Parallel Build Setup.
##
VISIT_OPTION_DEFAULT(VISIT_PARALLEL ON)
VISIT_OPTION_DEFAULT(VISIT_MPI_COMPILER mpic++)


##############################################################
##
## Database reader plugin support libraries
##
##############################################################

##
## AdvIO
##
VISIT_OPTION_DEFAULT(VISIT_ADVIO_DIR ${VISITHOME}/AdvIO/1.2/${VISITARCH}/)

##
## Boxlib
##
VISIT_OPTION_DEFAULT(VISIT_BOXLIB2D_DIR ${VISITHOME}/boxlib/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_BOXLIB3D_DIR ${VISITHOME}/boxlib/${VISITARCH})

##
## CFITSIO
##
VISIT_OPTION_DEFAULT(VISIT_CFITSIO_DIR ${VISITHOME}/cfitsio/3006/${VISITARCH})

##
## CGNS
##
VISIT_OPTION_DEFAULT(VISIT_CGNS_DIR ${VISITHOME}/cgns/2.4/${VISITARCH})

##
## Exodus
##
VISIT_OPTION_DEFAULT(VISIT_EXODUSII_DIR ${VISITHOME}/exodus/4.46/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_EXODUSII_LIBDEP NETCDF_LIBRARY_DIR netcdf)

##
## GDAL
##
VISIT_OPTION_DEFAULT(VISIT_GDAL_DIR ${VISITHOME}/gdal/1.3.2/${VISITARCH})

##
## H5Part
##
VISIT_OPTION_DEFAULT(VISIT_H5PART_DIR ${VISITHOME}/h5part/1.6.0/${VISITARCH})

##
## FastBit (failed to build on beetown)
## 
#VISIT_OPTION_DEFAULT(VISIT_FASTBIT_DIR ${VISITHOME}/fastbit/1.0.9/${VISITARCH})

##
## HDF4
##
VISIT_OPTION_DEFAULT(VISIT_HDF4_DIR ${VISITHOME}/hdf4/4.2.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_HDF4_LIBDEP ${VISITHOME}/szip/2.1/${VISITARCH}/lib sz /usr/lib jpeg)

##
## HDF5
##
VISIT_OPTION_DEFAULT(VISIT_HDF5_DIR ${VISITHOME}/hdf5/1.8.4/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_HDF5_LIBDEP ${VISITHOME}/szip/2.1/${VISITARCH}/lib sz)

##
## Mili
##
VISIT_OPTION_DEFAULT(VISIT_MILI_DIR ${VISITHOME}/mili/1.10.0/${VISITARCH})

##
## NetCDF
##
VISIT_OPTION_DEFAULT(VISIT_NETCDF_DIR ${VISITHOME}/netcdf/3.6.3/${VISITARCH})

##
## SZIP
##
VISIT_OPTION_DEFAULT(VISIT_SZIP_DIR ${VISITHOME}/szip/2.1/${VISITARCH})

##
## CCMIO
##
VISIT_OPTION_DEFAULT(VISIT_CCMIO_DIR ${VISITHOME}/ccmio/2.6.1/${VISITARCH})

##
## Silo
##
VISIT_OPTION_DEFAULT(VISIT_SILO_DIR ${VISITHOME}/silo/4.7.2/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_SILO_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP})

##
## Visus
##

##
## Ice-T
##
VISIT_OPTION_DEFAULT(VISIT_ICET_DIR ${VISITHOME}/icet/0.5.4/${VISITARCH})

##
## ITAPS
##
## MOAB implementation
ITAPS_INCLUDE_DIRECTORIES(MOAB ${VISITHOME}/itaps/MOAB/3.99-20Apr09/${VISITARCH}/include)
ITAPS_FILE_PATTERNS(MOAB *.cub)
ITAPS_LINK_LIBRARIES(MOAB iMesh MOAB hdf5 sz z netcdf_c++ netcdf vtkGraphics)
ITAPS_LINK_DIRECTORIES(MOAB  ${VISITHOME}/itaps/MOAB/3.99-20Apr09/${VISITARCH}/lib  ${VISITHOME}/hdf5/1.8.2/${VISITARCH}/lib  ${VISITHOME}/szip/2.1/${VISITARCH}/lib  ${VISITHOME}/netcdf/3.6.3/${VISITARCH}/lib)
## FMDB implementation
ITAPS_INCLUDE_DIRECTORIES(FMDB ${VISITHOME}/itaps/FMDB/1.0-15Apr09/${VISITARCH}/include/FMDB)
ITAPS_FILE_PATTERNS(FMDB *.sms)
ITAPS_LINK_LIBRARIES(FMDB FMDB SCORECModel SCORECUtil vtkGraphics)
ITAPS_LINK_DIRECTORIES(FMDB ${VISITHOME}/itaps/FMDB/1.0-15Apr09/${VISITARCH}/lib)
## GRUMMP implementation
ITAPS_INCLUDE_DIRECTORIES(GRUMMP ${VISITHOME}/itaps/GRUMMP/0.5.0-20Apr09/${VISITARCH}/include)
ITAPS_FILE_PATTERNS(GRUMMP *.bdry *.smesh *.vmesh)
ITAPS_LINK_LIBRARIES(GRUMMP iMesh_GRUMMP GR_3D GR_surf GR_2D GR_base SUMAAlog_lite OptMS vtkGraphics)
ITAPS_LINK_DIRECTORIES(GRUMMP ${VISITHOME}/itaps/GRUMMP/0.5.0-20Apr09/${VISITARCH}/lib)

