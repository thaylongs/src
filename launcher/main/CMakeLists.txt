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
#   Gunther H. Weber, Thu Jan 14 11:36:21 PST 2010
#   Added conditional target for separate socket bridge executable.
#
#   Kathleen Bonnell, Thu Feb 25 11:00:43 MST 2010 
#   Exclude testvcl on windows.
#
#   Brad Whitlock, Tue Nov 29 11:15:24 PST 2011
#   I moved SocketBridge to common.
#
#   Brad Whitlock, Fri May 18 16:09:34 PST 2012
#   Use different resource file.
#
#****************************************************************************/

SET(VCL_SOURCES
LauncherApplication.C
main.C
)

IF (NOT WIN32)
    # This keeps comm's exceptions visible when using -fvisibility=hidden
    ADD_DEFINITIONS(-DCOMM_EXPORTS)
ENDIF (NOT WIN32)

INCLUDE_DIRECTORIES(
${CMAKE_CURRENT_SOURCE_DIR}
${VISIT_COMMON_INCLUDES}
${VISIT_SOURCE_DIR}/launcher/rpc
${VISIT_SOURCE_DIR}/launcher/proxy
)

LINK_DIRECTORIES(${LIBRARY_OUTPUT_DIRECTORY} ${VTK_LIBRARY_DIRS})

ADD_EXECUTABLE(vcl ${VISIT_APPLICATION_STYLE} ${VCL_SOURCES} ${VISIT_VCL_RESOURCE_FILE})
TARGET_LINK_LIBRARIES(vcl vclrpc visitcommon ${CMAKE_THREAD_LIBS} ${DL_LIB})

IF (VISIT_CREATE_SOCKET_RELAY_EXECUTABLE)
    ADD_EXECUTABLE(visit_socket_relay SocketRelayMain.C)
    TARGET_LINK_LIBRARIES(visit_socket_relay visitcommon ${CMAKE_THREAD_LIBS} ${DL_LIB})
    VISIT_INSTALL_TARGETS(visit_socket_relay)
ENDIF (VISIT_CREATE_SOCKET_RELAY_EXECUTABLE)

IF (NOT WIN32)
    ADD_EXECUTABLE(testvcl EXCLUDE_FROM_ALL testvcl.C)
    TARGET_LINK_LIBRARIES(testvcl vclproxy vclrpc visitcommon ${CMAKE_THREAD_LIBS} ${DL_LIB})
ENDIF (NOT WIN32)
VISIT_INSTALL_TARGETS(vcl)
