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
#   Kathleen Biagas, Tues Oct 1 09:33:47 MST 2013
#   Removed VISIT_MSVC_VERSION from windows handling.
##
#****************************************************************************/

# Use the FASTBIT_DIR hint from the config-site .cmake file 

INCLUDE(${VISIT_SOURCE_DIR}/CMake/SetUpThirdParty.cmake)

IF(DEFINED FASTBIT_VERSION)
    IF(${FASTBIT_VERSION} VERSION_LESS "2.0.0")
      SET(FB_INCLUDE include)
    ELSE(${FASTBIT_VERSION} VERSION_LESS "2.0.0")
      SET(FB_INCLUDE include/fastbit)
    ENDIF(${FASTBIT_VERSION} VERSION_LESS "2.0.0")
ELSE(DEFINED FASTBIT_VERSION)
  SET(FB_INCLUDE include)
ENDIF(DEFINED FASTBIT_VERSION)

IF (WIN32)
    SET_UP_THIRD_PARTY(FASTBIT lib ${FB_INCLUDE} fastbit)
ELSE (WIN32)
    IF("${VISIT_CMAKE_PLATFORM}" STREQUAL "Linux")
        # Linux requires librt to resolve "clock_gettime"
        # add this as a general dep:
        #SET(FASTBIT_LIBDEP /usr/lib rt "${FASTBIT_LIBDEP}")
    ENDIF("${VISIT_CMAKE_PLATFORM}" STREQUAL "Linux")
    SET_UP_THIRD_PARTY(FASTBIT lib ${FB_INCLUDE} fastbit)
ENDIF (WIN32)

