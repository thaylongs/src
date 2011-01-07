#/project/projectdirs/visit/visit_3rdparty_euclid_opt/cmake/2.8.0/linux-x86_64_gcc-4.1/bin/cmake
##
## ./build_visit generated host.cmake
## created: Mon Dec  6 13:28:25 PST 2010
## system: Linux euclid.nersc.gov 2.6.18.194.17.4.el5-x86_64-bsdv3-prf #1 SMP Thu Oct 28 17:44:14 PDT 2010 x86_64 x86_64 x86_64 GNU/Linux
## by: hrchilds

##
## Setup VISITHOME & VISITARCH variables.
##
SET(VISITHOME /project/projectdirs/visit/visit_3rdparty_euclid_opt)
SET(VISITHOME2 /project/projectdirs/visit/visit_3rdparty_euclid)
SET(VISITARCH linux-x86_64_gcc-4.1)
VISIT_OPTION_DEFAULT(CMAKE_INSTALL_PREFIX /usr/common/graphics/visit)
VISIT_OPTION_DEFAULT(VISIT_INSTALL_THIRD_PARTY ON)
VISIT_OPTION_DEFAULT(VISIT_VERBOSE_MAKEFILE TRUE)

##
## Specify the location of the mesa.
##
VISIT_OPTION_DEFAULT(VISIT_MESA_DIR ${VISITHOME}/mesa/7.8.2/${VISITARCH})

##
## Specify the location of the vtk.
##
VISIT_OPTION_DEFAULT(VISIT_VTK_DIR ${VISITHOME}/vtk/5.0.0g/${VISITARCH}/lib/vtk-5.0/)

##
## Specify the Qt4 binary dir. 
## (qmake us used to locate & setup Qt4 dependencies)
##
VISIT_OPTION_DEFAULT(VISIT_QT_BIN ${VISITHOME}/qt/4.6.1/${VISITARCH}/bin)

##
## Specify the location of the python.
##
VISIT_OPTION_DEFAULT(VISIT_PYTHON_DIR ${VISITHOME}/python/2.6.4/${VISITARCH})

##
## Compiler flags.
##
VISIT_OPTION_DEFAULT(VISIT_C_COMPILER gcc)
VISIT_OPTION_DEFAULT(VISIT_CXX_COMPILER g++)
VISIT_OPTION_DEFAULT(CMAKE_BUILD_TYPE Release)
VISIT_OPTION_DEFAULT(VISIT_C_FLAGS " -m64 -fPIC -fvisibility=hidden")
VISIT_OPTION_DEFAULT(VISIT_CXX_FLAGS " -m64 -fPIC -fvisibility=hidden")

##
## MPI Flags
##
VISIT_OPTION_DEFAULT(VISIT_MPI_C_FLAGS "-D_REENTRANT -DOMPI_SKIP_MPICXX -I /usr/common/usg/openmpi/1.4.1/gnu/include")
VISIT_OPTION_DEFAULT(VISIT_MPI_CXX_FLAGS "-D_REENTRANT -DOMPI_SKIP_MPICXX -I /usr/common/usg/openmpi/1.4.1/gnu/include")
VISIT_OPTION_DEFAULT(VISIT_MPI_LD_FLAGS "-L/usr/common/usg/openmpi/1.4.1/gnu/lib -Wl,--export-dynamic")
VISIT_OPTION_DEFAULT(VISIT_MPI_LIBS mpi open-rte open-pal dl nsl util pthread dl)
VISIT_OPTION_DEFAULT(VISIT_PARALLEL_RPATH "/usr/common/usg/openmpi/1.4.1/gnu/lib")
VISIT_OPTION_DEFAULT(VISIT_PARALLEL ON)

##############################################################
##
## Database reader plugin support libraries
##
## The HDF4, HDF5 and NetCDF libraries must be first so that
## their libdeps are defined for any plugins that need them.
##
##############################################################

##
## HDF4
##
VISIT_OPTION_DEFAULT(VISIT_HDF4_DIR ${VISITHOME}/hdf4/4.2.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_HDF4_LIBDEP ${VISITHOME}/szip/2.1/${VISITARCH}/lib sz /usr/lib jpeg)

##
## HDF5
##
VISIT_OPTION_DEFAULT(VISIT_HDF5_DIR ${VISITHOME}/hdf5/1.8.4/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_HDF5_LIBDEP ${VISITHOME}/szip/2.1/${VISITARCH}/lib sz /usr/lib z)

##
## NetCDF
##
VISIT_OPTION_DEFAULT(VISIT_NETCDF_DIR ${VISITHOME}/netcdf/4.1.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_NETCDF_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP})

##
## AdvIO
##
VISIT_OPTION_DEFAULT(VISIT_ADVIO_DIR ${VISITHOME}/AdvIO/1.2/${VISITARCH}/)

##
## Boxlib
##
VISIT_OPTION_DEFAULT(VISIT_BOXLIB_DIR ${VISITHOME}/boxlib/2010.10.01/${VISITARCH})

##
## CCMIO
##
VISIT_OPTION_DEFAULT(VISIT_CCMIO_DIR ${VISITHOME}/ccmio/2.6.1/${VISITARCH})

##
## CFITSIO
##
VISIT_OPTION_DEFAULT(VISIT_CFITSIO_DIR ${VISITHOME}/cfitsio/3006/${VISITARCH})

##
## CGNS
##
VISIT_OPTION_DEFAULT(VISIT_CGNS_DIR ${VISITHOME}/cgns/3.0.8/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_CGNS_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP})

##
## Exodus
##
VISIT_OPTION_DEFAULT(VISIT_EXODUSII_DIR ${VISITHOME}/exodus/4.46/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_EXODUSII_LIBDEP NETCDF_LIBRARY_DIR netcdf ${VISIT_NETCDF_LIBDEP})

##
## FastBit
##
VISIT_OPTION_DEFAULT(VISIT_FASTBIT_DIR ${VISITHOME}/fastbit/1.2.0/${VISITARCH})

##
## GDAL
##
VISIT_OPTION_DEFAULT(VISIT_GDAL_DIR ${VISITHOME2}/gdal/1.7.2/${VISITARCH})

##
## H5Part
##
VISIT_OPTION_DEFAULT(VISIT_H5PART_DIR ${VISITHOME2}/h5part/1.6.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_H5PART_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP})

##
## SZIP
##
VISIT_OPTION_DEFAULT(VISIT_SZIP_DIR ${VISITHOME}/szip/2.1/${VISITARCH})

##
## Silo
##
VISIT_OPTION_DEFAULT(VISIT_SILO_DIR ${VISITHOME}/silo/4.8/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_SILO_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP})

##
## Xdmf
##
VISIT_OPTION_DEFAULT(VISIT_XDMF_DIR ${VISITHOME}/Xdmf/2.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_XDMF_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP})

##
## Ice-T
##
VISIT_OPTION_DEFAULT(VISIT_ICET_DIR ${VISITHOME}/icet/0.5.4/${VISITARCH})

##
## ITAPS
##
## MOAB implementation
ITAPS_INCLUDE_DIRECTORIES(MOAB ${VISITHOME}/itaps/MOAB/3.99-10Jun10/${VISITARCH}/include)
ITAPS_FILE_PATTERNS(MOAB *.cub)
ITAPS_LINK_LIBRARIES(MOAB iMesh MOAB hdf5 sz z netcdf_c++ netcdf vtkGraphics)
ITAPS_LINK_DIRECTORIES(MOAB  ${VISITHOME}/itaps/MOAB/3.99-10Jun10/${VISITARCH}/lib  ${VISITHOME}/hdf5/1.8.4/${VISITARCH}/lib  ${VISITHOME}/szip/2.1/${VISITARCH}/lib  ${VISITHOME}/netcdf/4.1.1/${VISITARCH}/lib)
## FMDB implementation
ITAPS_INCLUDE_DIRECTORIES(FMDB ${VISITHOME}/itaps/FMDB/1.1-30Aug10/${VISITARCH}/include/FMDB)
ITAPS_FILE_PATTERNS(FMDB *.sms)
ITAPS_LINK_LIBRARIES(FMDB FMDB SCORECModel SCORECUtil vtkGraphics)
ITAPS_LINK_DIRECTORIES(FMDB ${VISITHOME}/itaps/FMDB/1.1-30Aug10/${VISITARCH}/lib)
## GRUMMP implementation
ITAPS_INCLUDE_DIRECTORIES(GRUMMP ${VISITHOME}/itaps/GRUMMP/0.5.0-03Jun10/${VISITARCH}/include)
ITAPS_FILE_PATTERNS(GRUMMP *.bdry *.smesh *.vmesh)
ITAPS_LINK_LIBRARIES(GRUMMP iMesh_GRUMMP GR_3D GR_surf GR_2D GR_base SUMAAlog_lite OptMS vtkGraphics)
ITAPS_LINK_DIRECTORIES(GRUMMP ${VISITHOME}/itaps/GRUMMP/0.5.0-03Jun10/${VISITARCH}/lib)

