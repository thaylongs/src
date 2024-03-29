#*****************************************************************************
#
# Copyright (c) 2000 - 2017, Lawrence Livermore National Security, LLC
# Produced at the Lawrence Livermore National Laboratory
# LLNL-CODE-442911
# All rights reserved.
#
# This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
# full copyright notice is contained in the file COPYRIGHT located at the root
# of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
#
# Redistribution  and  use  in  source  and  binary  forms,  with  or  without
# modification, are permitted provided that the following conditions are met:
#
#  - Redistributions of  source code must  retain the above  copyright notice,
#    this list of conditions and the disclaimer below.
#  - Redistributions in binary form must reproduce the above copyright notice,
#    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
#    documentation and/or other materials provided with the distribution.
#  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
#    be used to endorse or promote products derived from this software without
#    specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
# ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
# LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
# DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
# SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
# CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
# LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
# OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
# DAMAGE.
#
# Modifications:
#
#    Gunther H. Weber, Thu Jan 28 14:33:36 PST 2010
#    Added hack/workaround that ensures that the static MPI libraries get added
#    to the end of the link line. In essence, we add a dummy/empty library
#    that has the MPI libraries as dependencies. This libary is added to the
#    end of the link line of parallel executables. Doing so ensures that cmake
#    will add the depencies of this dummy library, i.e., the MPI libraries, to
#    the end of the link line.
#
#    Hank Childs, Sat Aug 21 11:56:26 PDT 2010
#    Rename DDF as DataBinning.
#
#    Brad Whitlock, Mon Dec 13 16:06:42 PST 2010
#    I added CumulativeQueryNamedSelectionExtension.
#
#    Brad Whitlock, Fri May 18 16:09:34 PST 2012
#    Use different resource file.
#
#    Kathleen Biagas, Thu Jun 21 15:19:02 MST 2012 
#    Call ADD_TARGET_DEFINTIONS to add "HAVE_ICET", as the function deals
#    correctly with a target already having some COMPILE_DEFINITIONS set.
#
#    Brad Whitlock, Thu Apr 11 15:59:49 PDT 2013
#    Add check for X11. Change how we get zlib.
#
#    Eric Brugger, Tue Sep 30 15:03:30 PDT 2014
#    Add the EAVL library to the list of link libraries.
#
#    Burlen Loring, Thu Sep  3 22:35:11 PDT 2015
#    I added the ProgrammableCompositer, a helper class
#    used by the NetworkManager.
#
#****************************************************************************/

SET(LIBENGINE_SOURCES
ProgrammableCompositer.C
DataNetwork.C
ClonedDataNetwork.C
CumulativeQueryNamedSelectionExtension.C
Engine.C
EngineBase.C
LoadBalancer.C
MesaDisplay.C
Netnodes.C
NetworkManager.C
VisItDisplay.C
)

# If the engine is static then we need some static symbol lookup functions
IF(VISIT_STATIC)
    SET(ENGINE_STATIC_SOURCES EngineStaticSymbolLocator.C)
ENDIF(VISIT_STATIC)

IF (NOT WIN32 AND NOT APPLE AND VISIT_USE_X)
    SET(LIBENGINE_SOURCES ${LIBENGINE_SOURCES} XDisplay.C)
ENDIF (NOT WIN32 AND NOT APPLE AND VISIT_USE_X)
IF (NOT WIN32)
    # This keeps comm's exceptions visible when using -fvisibility=hidden
    ADD_DEFINITIONS(-DCOMM_EXPORTS)
ENDIF (NOT WIN32)

INCLUDE_DIRECTORIES(
${CMAKE_CURRENT_SOURCE_DIR}
${VISIT_COMMON_INCLUDES}
${VISIT_SOURCE_DIR}/third_party_builtin/cognomen/src
${VISIT_SOURCE_DIR}/third_party_builtin/cognomen/src/cog
${VISIT_SOURCE_DIR}/engine/proxy
${VISIT_SOURCE_DIR}/engine/rpc
${VISIT_SOURCE_DIR}/avt/DBAtts/MetaData
${VISIT_SOURCE_DIR}/avt/DBAtts/SIL
${VISIT_SOURCE_DIR}/avt/DataBinning
${VISIT_SOURCE_DIR}/avt/Database/Database
${VISIT_SOURCE_DIR}/avt/Database/Ghost
${VISIT_SOURCE_DIR}/avt/Expressions/Abstract
${VISIT_SOURCE_DIR}/avt/Expressions/CMFE
${VISIT_SOURCE_DIR}/avt/Expressions/Conditional
${VISIT_SOURCE_DIR}/avt/Expressions/Derivations
${VISIT_SOURCE_DIR}/avt/Expressions/General
${VISIT_SOURCE_DIR}/avt/Expressions/ImageProcessing
${VISIT_SOURCE_DIR}/avt/Expressions/Management
${VISIT_SOURCE_DIR}/avt/Expressions/Math
${VISIT_SOURCE_DIR}/avt/Expressions/MeshQuality
${VISIT_SOURCE_DIR}/avt/FileWriter
${VISIT_SOURCE_DIR}/avt/Filters
${VISIT_SOURCE_DIR}/avt/Math
${VISIT_SOURCE_DIR}/avt/VisWindow/VisWindow
${VISIT_SOURCE_DIR}/avt/Pipeline/AbstractFilters
${VISIT_SOURCE_DIR}/avt/Pipeline/Data
${VISIT_SOURCE_DIR}/avt/Pipeline/Pipeline
${VISIT_SOURCE_DIR}/avt/Pipeline/Sinks
${VISIT_SOURCE_DIR}/avt/Pipeline/Sources
${VISIT_SOURCE_DIR}/avt/Plotter
${VISIT_SOURCE_DIR}/avt/Plotter/vtk
${VISIT_SOURCE_DIR}/avt/Queries/Abstract
${VISIT_SOURCE_DIR}/avt/Queries/Misc
${VISIT_SOURCE_DIR}/avt/Queries/Pick
${VISIT_SOURCE_DIR}/avt/Queries/Queries
${VISIT_SOURCE_DIR}/avt/View
${VISIT_SOURCE_DIR}/avt/VisWindow/Colleagues
${VISIT_SOURCE_DIR}/avt/VisWindow/Proxies
${VISIT_SOURCE_DIR}/avt/VisWindow/Tools
${VISIT_SOURCE_DIR}/avt/VisWindow/VisWindow
${VISIT_SOURCE_DIR}/visit_vtk/full
${VISIT_SOURCE_DIR}/visit_vtk/lightweight
${VISIT_SOURCE_DIR}/visit_vtk/osmesa
${VTK_INCLUDE_DIRS}
${OPENGL_INCLUDE_DIR}
)

# Add link directories
LINK_DIRECTORIES(
${LIBRARY_OUTPUT_DIRECTORY}
${GLEW_LIBRARY_DIR}
${MESA_LIBRARY_DIR}
${EAVL_LIBRARY_DIR}
${VTK_LIBRARY_DIRS}
${TCMALLOC_LIBRARY_DIR}
${ALL_THIRDPARTY_IO_LIBRARY_DIR}
)


#********************************* SERIAL ************************************
ADD_LIBRARY(engine_ser ${LIBENGINE_SOURCES})
IF (WIN32)
    SET_TARGET_PROPERTIES(engine_ser PROPERTIES OUTPUT_NAME enginelib_ser)
ENDIF (WIN32)
TARGET_LINK_LIBRARIES(engine_ser
visitcommon
enginerpc
avtview
avtwriter_ser
avtplotter_ser
avtquery_ser
avtviswindow_ser
avtpipeline_ser
)

IF(MESA_FOUND)
    TARGET_LINK_LIBRARIES(engine_ser visit_vtk_osmesa)
ENDIF(MESA_FOUND)



# These 3 variables are only defined when building statically.
# engine_ser_exe_EDatabase_ser = The list of database libE libraries needed to link
# engine_ser_exe_EOperator_ser = The list of operator libE libraries needed to link
# engine_ser_exe_EPlot_ser = The list of plot libE libraries needed to link

ADD_EXECUTABLE(engine_ser_exe ${VISIT_APPLICATION_STYLE} main.C ${ENGINE_STATIC_SOURCES} ${VISIT_ENGINE_SER_RESOURCE_FILE})
SET_TARGET_PROPERTIES(engine_ser_exe PROPERTIES OUTPUT_NAME engine_ser)
TARGET_LINK_LIBRARIES(engine_ser_exe 
    ${engine_ser_exe_IDatabase}
    ${engine_ser_exe_EDatabase_ser}
    ${engine_ser_exe_IOperator}
    ${engine_ser_exe_EOperator_ser}
    ${engine_ser_exe_IPlot}
    ${engine_ser_exe_EPlot_ser}
    engine_ser 
    visit_verdict 
    vtkjpeg
    vtkpng
    ${VTKZLIB_LIB}
    ${VTK_FREETYPE_LIBRARIES}
    vtkftgl
    ${ALL_THIRDPARTY_IO_LIB}
    ${TCMALLOC_LIB}
    ${CMAKE_THREAD_LIBS} 
    ${ZLIB_LIB}
    ${EAVL_LIB}
)

# If we're building statically then the engine can't be linked until the plugin
# sources are built
IF(VISIT_STATIC)
    ADD_DEPENDENCIES(engine_ser_exe
        ${engine_ser_exe_IDatabase}
        ${engine_ser_exe_EDatabase_ser}
        ${engine_ser_exe_IOperator}
        ${engine_ser_exe_EOperator_ser}
        ${engine_ser_exe_IPlot}
        ${engine_ser_exe_EPlot_ser}
    )
ENDIF(VISIT_STATIC)

VISIT_INSTALL_TARGETS(engine_ser engine_ser_exe)

#********************************* PARALLEL **********************************
IF(VISIT_PARALLEL)
    SET(ENGINE_PAR_SOURCES MPIXfer.C)
    # If we have Ice-T then add more sources to the build
    IF(ICET_FOUND)
        SET(ICET_SOURCES IceTNetworkManager.C)
        INCLUDE_DIRECTORIES(${ICET_INCLUDE_DIR})
        LINK_DIRECTORIES(${ICET_LIBRARY_DIR})
    ENDIF(ICET_FOUND)

    ADD_PARALLEL_LIBRARY(engine_par ${LIBENGINE_SOURCES} ${ENGINE_PAR_SOURCES} ${ICET_SOURCES})
    IF (WIN32)
        SET_TARGET_PROPERTIES(engine_par PROPERTIES OUTPUT_NAME enginelib_par)
    ENDIF (WIN32)

    # If we have Ice-T then add -DHAVE_ICET to the compilation flags.
    IF(ICET_FOUND)
        ADD_TARGET_DEFINITIONS(engine_par "HAVE_ICET")
        IF(APPLE)
            # We need to link with OpenGL on Mac when we have IceT.
            SET(ICET_OPENGL ${OPENGL_gl_LIBRARY})
        ENDIF(APPLE)

        IF(VISIT_STATIC)
            SET(ICET_STATIC_LIB ${ICET_LIB} ${ICET_OPENGL} ${VISIT_PARALLEL_LIBS})
        ELSE(VISIT_STATIC)
            SET(ICET_DYNAMIC_LIB ${ICET_LIB} ${ICET_OPENGL})
        ENDIF(VISIT_STATIC)
    ENDIF(ICET_FOUND)

    TARGET_LINK_LIBRARIES(engine_par
        visitcommon
        enginerpc
        avtview
        avtwriter_par
        avtplotter_par
        avtquery_par
        avtviswindow_par
        avtpipeline_par
        cognomen
        ${ICET_DYNAMIC_LIB}
    )

    IF(MESA_FOUND)
        TARGET_LINK_LIBRARIES(engine_par visit_vtk_osmesa)
    ENDIF(MESA_FOUND)

    IF(VISIT_NOLINK_MPI_WITH_LIBRARIES)
        ADD_LIBRARY(link_mpi_libs STATIC empty.c)
        TARGET_LINK_LIBRARIES(link_mpi_libs ${VISIT_PARALLEL_LIBS})
    ENDIF(VISIT_NOLINK_MPI_WITH_LIBRARIES)

    # For static builds with icet, don't add the parallel libs automatically. We
    # try to control it explicitly so icet comes before mpi on the link line.
    IF(ICET_FOUND AND VISIT_STATIC)
        SET(tmpval ${VISIT_NOLINK_MPI_WITH_LIBRARIES})
        SET(VISIT_NOLINK_MPI_WITH_LIBRARIES OFF)
    ENDIF(ICET_FOUND AND VISIT_STATIC)

    ADD_PARALLEL_EXECUTABLE(engine_par_exe ${VISIT_APPLICATION_STYLE} main.C ${ENGINE_STATIC_SOURCES} ${VISIT_ENGINE_PAR_RESOURCE_FILE})

    IF(ICET_FOUND AND VISIT_STATIC)
        SET(VISIT_NOLINK_MPI_WITH_LIBRARIES ${tmpval})
    ENDIF(ICET_FOUND AND VISIT_STATIC)

    SET_TARGET_PROPERTIES(engine_par_exe PROPERTIES OUTPUT_NAME engine_par)

    PARALLEL_EXECUTABLE_LINK_LIBRARIES(engine_par_exe
        ${engine_par_exe_IDatabase_par}
        ${engine_par_exe_EDatabase_par}
        ${engine_par_exe_IOperator_par}
        ${engine_par_exe_EOperator_par}
        ${engine_par_exe_IPlot_par}
        ${engine_par_exe_EPlot_par}
        engine_par
        visit_verdict 
        vtkjpeg
        vtkpng
        ${VTKZLIB_LIB}
        ${VTK_FREETYPE_LIBRARIES}
        vtkftgl
        ${ALL_THIRDPARTY_IO_LIB}
        ${ICET_STATIC_LIB}
        ${TCMALLOC_LIB}
        ${CMAKE_THREAD_LIBS} 
        ${ZLIB_LIB}
    )

    # If we're building statically then the engine can't be linked until the plugin
    # sources are built
    IF(VISIT_STATIC)
        ADD_DEPENDENCIES(engine_par_exe
            ${engine_par_exe_IDatabase_par}
            ${engine_par_exe_EDatabase_par}
            ${engine_par_exe_IOperator_par}
            ${engine_par_exe_EOperator_par}
            ${engine_par_exe_IPlot_par}
            ${engine_par_exe_EPlot_par}
        )
    ENDIF(VISIT_STATIC)

    VISIT_INSTALL_TARGETS(engine_par engine_par_exe)
ENDIF(VISIT_PARALLEL)
