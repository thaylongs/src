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
#   Kathleen Biagas, Wed Oct 22 14:20:27 MST 2014
#   Send 'diagnostics/networktest' type argument to VISIT_TOOLS_ADD_FOLDER.
#
#****************************************************************************/

SET(TARGETS networktestclient networktestserver)

INCLUDE_DIRECTORIES(
${CMAKE_CURRENT_SOURCE_DIR}
${VISIT_COMMON_INCLUDES}
)

LINK_DIRECTORIES(
${LIBRARY_OUTPUT_DIRECTORY}
)

ADD_EXECUTABLE(networktestclient networktestclient.cpp)
TARGET_LINK_LIBRARIES(networktestclient visitcommon)

ADD_EXECUTABLE(networktestserver networktestserver.cpp)
TARGET_LINK_LIBRARIES(networktestserver visitcommon)

IF(VISIT_PARALLEL)
    ADD_PARALLEL_EXECUTABLE(networktestserver_par networktestserver.cpp)
    PARALLEL_EXECUTABLE_LINK_LIBRARIES(networktestserver_par visitcommon)
    SET(TARGETS ${TARGETS} networktestserver_par)
ENDIF(VISIT_PARALLEL)

VISIT_INSTALL_TARGETS(${TARGETS})
VISIT_TOOLS_ADD_FOLDER(diagnostics/networktest ${TARGETS})
