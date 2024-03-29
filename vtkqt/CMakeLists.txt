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
#    Kathleen Biagas, Tue Feb 5 15:15:27 PST 2013
#    Removed GUISupport, we use VTK's version now.
#
#****************************************************************************/

SET(VTKQT_SOURCES
vtkQtRenderWindow.C
vtkQtImagePrinter.C
)

INCLUDE_DIRECTORIES(
${VISIT_BINARY_DIR}/include
${VISIT_SOURCE_DIR}/include
${VISIT_SOURCE_DIR}/vtkqt
${VISIT_SOURCE_DIR}/common/utility
${VTK_INCLUDE_DIRS}
${QT_INCLUDE_DIR}
${QT_QTCORE_INCLUDE_DIR}
${QT_QTGUI_INCLUDE_DIR}
${QT_QTOPENGL_INCLUDE_DIR}
)

# Add link directories needed to use Qt and VTK.
LINK_DIRECTORIES(${QT_LIBRARY_DIR} ${VTK_LIBRARY_DIRS})

ADD_LIBRARY(vtkqt ${VTKQT_SOURCES})

# Specify the libraries to link against on Windows & Mac
IF(HAVE_LIB_R)
    TARGET_LINK_LIBRARIES(vtkqt vtkCommonCore vtkGUISupportQtOpenGL vtkIOImage vtkRenderingOpenGL vtkRenderingFreeTypeOpenGL ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${OPENGL_gl_LIBRARY} vtkFiltersStatisticsGnuR)
ELSE(HAVE_LIB_R)
    TARGET_LINK_LIBRARIES(vtkqt vtkCommonCore vtkGUISupportQtOpenGL vtkIOImage vtkRenderingOpenGL vtkRenderingFreeTypeOpenGL ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${OPENGL_gl_LIBRARY})
ENDIF(HAVE_LIB_R)
# Add vtk definitions
ADD_TARGET_DEFINITIONS(vtkqt "${VTK_DEFINITIONS}")


VISIT_INSTALL_TARGETS(vtkqt)

