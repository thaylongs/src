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
#   Kathleen Biagas, Thu Mar 24 16:18:19 PDT 2016
#   Added install for qt libraries, and necessary plugins (eg platform
#   specific).  Create a qt.conf file to be installed in the bin dir that
#   tells Qt where to find the plugins.
#
#   Kevin Griffin, Wed Nov 2 10:04:28 PDT 2016
#   Added logic to install the correct MAC frameworks and static library.
#
#*****************************************************************************


# Configure for Qt5..
IF(NOT DEFINED VISIT_QT_DIR)
    MESSAGE(FATAL_ERROR "Qt5 installation directory not specified")
ENDIF()

set(QT_MOC_EXECUTABLE ${VISIT_QT_DIR}/bin/moc)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(QT5_INCLUDE_DIRS "")
set(QT5_LIBRARIES "")

set(visit_qt_modules Core Gui Widgets OpenGL Network PrintSupport Qml Xml UiTools)

if(LINUX)
    set (visit_qt_modules ${visit_qt_modules} X11Extras)
endif()

if(WIN32)
    set (visit_qt_modules ${visit_qt_modules} Svg)
endif()

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${VISIT_QT_DIR}/lib/cmake)
find_package (Qt5 REQUIRED ${visit_qt_modules})


foreach(mod ${visit_qt_modules})
  string(TOUPPER ${mod} upper_mod)
  if(NOT VISIT_QT_SKIP_INSTALL)
    if(WIN32 AND EXISTS ${VISIT_QT_DIR}/lib/Qt5${mod}.lib)
      THIRD_PARTY_INSTALL_LIBRARY(${VISIT_QT_DIR}/lib/Qt5${mod}.lib)
    elseif(APPLE)
      if(EXISTS ${VISIT_QT_DIR}/lib/Qt${mod}.framework)
          THIRD_PARTY_INSTALL_LIBRARY(${VISIT_QT_DIR}/lib/Qt${mod}.framework)
      else()
          get_target_property(lib_loc Qt5::${mod} LOCATION)
          THIRD_PARTY_INSTALL_LIBRARY(${lib_loc})
      endif()
    endif()
    # headers
    foreach(H ${Qt5${mod}_INCLUDE_DIRS})
      if(${H} MATCHES "/include/Qt")
        INSTALL(DIRECTORY ${H}
                DESTINATION ${VISIT_INSTALLED_VERSION_INCLUDE}/qt/include
                FILE_PERMISSIONS OWNER_WRITE OWNER_READ
                                   GROUP_WRITE GROUP_READ
                                   WORLD_READ
                DIRECTORY_PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE
                                        GROUP_WRITE GROUP_READ GROUP_EXECUTE
                                        WORLD_READ WORLD_EXECUTE
                PATTERN ".svn" EXCLUDE
        )
      endif()
    endforeach()
  endif()
endforeach()


set(QT_QTUITOOLS_LIBRARY ${Qt5UiTools_LIBRARIES})
set(QT_QTOPENGL_LIBRARY ${Qt5OpenGL_LIBRARIES})

# if/when we drop support for qt 4, perhaps leave these split and
# add Widgets or PrintSupport only where needed
set(QT_QTGUI_LIBRARY ${Qt5Gui_LIBRARIES} 
                     ${Qt5Widgets_LIBRARIES} 
                     ${Qt5PrintSupport_LIBRARIES})
set(QT_QTNETWORK_LIBRARY ${Qt5Network_LIBRARIES})
set(QT_QTXML_LIBRARY ${Qt5Xml_LIBRARIES})

# why is core not named the same as the others?
set(QT_QTCORE_LIBRARY ${Qt5Core_LIBRARIES})

if (LINUX)
    set(QT_QTX11EXTRAS_LIBRARY ${Qt5X11Extras_LIBRARIES})
endif()

if(NOT VISIT_QT_SKIP_INSTALL)
  # moc
  get_target_property(moc_location Qt5::moc LOCATION)
  MESSAGE(STATUS "moc location: ${moc_location}")
  install(PROGRAMS ${moc_location}
          DESTINATION ${VISIT_INSTALLED_VERSION_BIN}
          PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE
          GROUP_WRITE GROUP_READ GROUP_EXECUTE
          WORLD_READ WORLD_EXECUTE
  )

  set(qt_libs_install
        Qt5::Core
        Qt5::Gui
        Qt5::Network
        Qt5::OpenGL
        Qt5::PrintSupport
        Qt5::Widgets
        Qt5::Qml
        Qt5::Xml
  )
  if(LINUX)
      set(qt_libs_install ${qt_libs_install} Qt5::X11Extras)
  endif()
  if(WIN32)
      set(qt_libs_install ${qt_libs_install} Qt5::Svg)
  endif()

  if(NOT APPLE)
      foreach(qtlib ${qt_libs_install})
          get_target_property(qtlib_location ${qtlib} LOCATION)
          # On Linux, the library names are Qt5xxx.so.${QT_VERSION}
          # We need to remove the version part so that THIRD_PARTY_INSTALL_LIBRARY
          # will work correctly.
          if (LINUX)
              string(REPLACE ".${Qt5Core_VERSION}" ""
                     qtlib_location ${qtlib_location})
          endif()
          THIRD_PARTY_INSTALL_LIBRARY(${qtlib_location})
      endforeach()
  endif(NOT APPLE)


  # We need a qt.conf file telling qt where to find the plugins
  if(WIN32)
      file(WRITE ${VISIT_BINARY_DIR}/qt.conf "[Paths]\nPlugins=./qtplugins\n")
  else()
      file(WRITE ${VISIT_BINARY_DIR}/qt.conf "[Paths]\nPlugins=../lib/qtplugins\n")
  endif()

  install(FILES ${VISIT_BINARY_DIR}/qt.conf
          DESTINATION ${VISIT_INSTALLED_VERSION_BIN}
          PERMISSIONS OWNER_READ OWNER_WRITE
                      GROUP_READ GROUP_WRITE
                      WORLD_READ)

  # Platform plugins
  if (WIN32)
      install(DIRECTORY ${VISIT_QT_DIR}/plugins/platforms
              DESTINATION ${VISIT_INSTALLED_VERSION_BIN}/qtplugins)

      # We also need the platforms and the qt.conf in the build dir.
      file(COPY ${VISIT_QT_DIR}/plugins/platforms
           DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ThirdParty/qtplugins
           FILE_PERMISSIONS OWNER_READ OWNER_WRITE
                            GROUP_READ GROUP_WRITE
                            WORLD_READ
      )
      foreach(CFG ${CMAKE_CONFIGURATION_TYPES})
          file(WRITE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CFG}/qt.conf 
               "[Paths]\nPlugins=../ThirdParty/qtplugins\n")
      endforeach()
  else()
      install(DIRECTORY ${VISIT_QT_DIR}/plugins/platforms
              DESTINATION ${VISIT_INSTALLED_VERSION_LIB}/qtplugins)
  endif()

  if (LINUX)
      # Xcb related plugins
      install(DIRECTORY ${VISIT_QT_DIR}/plugins/xcbglintegrations
              DESTINATION ${VISIT_INSTALLED_VERSION_LIB}/qtplugins)

          # there is also a platform-plugin related library that
          # needs to be installed, but there doesn't seem to be
          # a way to find this via Qt's cmake mechanisms, hence this
          # hard-coded extra step
          THIRD_PARTY_INSTALL_LIBRARY(${VISIT_QT_DIR}/lib/libQt5XcbQpa.so)
  endif()
endif()
