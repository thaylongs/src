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
#    Gunther H. Weber, Thu Nov 21 18:24:53 PST 2013
#    Use instead PYSIDE_INCLUDE_DIR (set by findpackage PySide) instead of
#    VISIT_PYSIDE_DIR to support system PySide installs.
#
#    Kathleen Biagas, Tue Jan 24 11:06:12 PST 2017
#    Add support for Qt5.
#
#*****************************************************************************

if(VISIT_QT5)
    set(pyside_qt_includes
        ${Qt5Core_INCLUDE_DIRS}
        ${Qt5Gui_INCLUDE_DIRS}
        ${Qt5OpenGL_INCLUDE_DIRS})
else()
    set(pyside_qt_includes
        ${QT_QTCORE_INCLUDE_DIR}
        ${QT_QTGUI_INCLUDE_DIR}
        ${QT_QTOPENGL_INCLUDE_DIR}
        ${QT_INCLUDE_DIR})
endif()

set(pyside_gui_include_paths
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SHIBOKEN_INCLUDE_DIR}
    ${SHIBOKEN_PYTHON_INCLUDE_DIR}
    ${PYSIDE_INCLUDE_DIR}
    ${pyside_qt_includes}
    ${PYSIDE_INCLUDE_DIR}
    ${PYSIDE_INCLUDE_DIR}/QtCore
    ${PYSIDE_INCLUDE_DIR}/QtGui
    ${PYSIDE_INCLUDE_DIR}/QtOpenGL
    ${PYSIDE_INCLUDE_DIR}/QtWidgets
    ${VISIT_SOURCE_DIR}/gui/
    ${VISIT_SOURCE_DIR}/gui/main
    ${VISIT_SOURCE_DIR}/viewer/subjectproxy
    ${VISIT_SOURCE_DIR}/viewer/core
    ${VISIT_SOURCE_DIR}/viewer/main 
    ${VISIT_SOURCE_DIR}/viewer/main/ui
    ${VISIT_SOURCE_DIR}/viewer/proxy
    ${VISIT_SOURCE_DIR}/viewer/rpc
    ${VISIT_SOURCE_DIR}/vtkqt
    ${VISIT_SOURCE_DIR}/common/utility
    ${VISIT_SOURCE_DIR}/common/state
    ${VISIT_SOURCE_DIR}/common/misc
    ${VISIT_SOURCE_DIR}/common/comm
    ${VISIT_SOURCE_DIR}/common/plugin
    ${VISIT_SOURCE_DIR}/common/Exceptions/Pipeline
    ${VISIT_SOURCE_DIR}/avt/DBAtts/MetaData/
    ${VISIT_SOURCE_DIR}/avt/DBAtts/SIL
    ${VISIT_SOURCE_DIR}/avt/Math
    ${VISIT_SOURCE_DIR}/avt/VisWindow/VisWindow
    ${VISIT_SOURCE_DIR}/winutil
    ${VISIT_SOURCE_DIR}/visitpy/pyui/common
)

set(pyside_gui_link_libs
    #gui
    guiwrapper
    #viewersubjectproxy
    #${SHIBOKEN_PYTHON_LIBRARIES}
    #${SHIBOKEN_LIBRARY}
    #${PYSIDE_LIBRARY}
    #${QT_QTCORE_LIBRARY}
    ${QWT_LIBRARY}
    )

set(pyside_gui_sources ${CMAKE_CURRENT_SOURCE_DIR}/pysidegui.C) 
set(pyside_gui_gen_sources 
${CMAKE_CURRENT_BINARY_DIR}/pyside_gui/pysidegui_wrapper.cpp
${CMAKE_CURRENT_BINARY_DIR}/pyside_gui/guiwrapper_wrapper.cpp
${CMAKE_CURRENT_BINARY_DIR}/pyside_gui/pyside_gui_module_wrapper.cpp)

IF(WIN32)
  LINK_DIRECTORIES(${QT_SHAREDLIB_DIR} ${QT_LIBRARY_DIR})
ENDIF(WIN32)
LINK_DIRECTORIES(${QWT_LIBRARY_DIR})

#
# For dev build, we may need to link to mesa on Linux.
#
IF(MESA_FOUND)
    set(pyside_gui_link_libs ${pyside_gui_link_libs} ${MESA_LIB})
    LINK_DIRECTORIES(${LIBRARY_OUTPUT_DIRECTORY} ${MESA_LIBRARY_DIR})
ENDIF(MESA_FOUND)

#
# If we enable eavl, it will appear in the link line, so add ${EAVL_LIBRARY_DIR}
#
IF(EAVL_FOUND)
    LINK_DIRECTORIES(${EAVL_LIBRARY_DIR})
ENDIF()


PYSIDE_ADD_MODULE(pyside_gui
                  site-packages/visit
                  pyside_gui_sources
                  pyside_gui_gen_sources
                  pyside_gui_include_paths
                  pyside_gui_link_libs
                  global.h typesystem.xml)

