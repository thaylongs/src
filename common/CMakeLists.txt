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
#   Hank Childs, Thu Jul 22 09:55:03 PDT 2010
#   Add attributes for multi-window saves.
#
#   Brad Whitlock, Fri Jul 23 11:14:02 PDT 2010
#   I added SelectionProperties and SelectionList.
#
#   Hank Childs, Thu Aug 19 12:26:29 PDT 2010
#   Move DDF to DataBinning.
#
#   Mark C. Miller, Fri Oct 29 10:02:16 PDT 2010
#   Added DBYieldedNoDataException
#
#   Brad Whitlock, Fri Dec 10 15:42:46 PST 2010
#   I added ThresholdOpAttributes, the bulk of the ThresholdAttributes. I also
#   added SelectionSummary and SelectionVariableSummary.
#
#
#   Mark C. Miller, Tue Feb  8 16:28:32 PST 2011
#   Added custom 'init' target for pareser re-gen. It was lost in transition
#   from autoconf to CMake.
#
#   Kathleen Biagas, Tue Aug 23 10:16:30 PDT 2011
#   Added QueryArgumentException.
#
#   Brad Whitlock, Mon Nov 28 16:20:55 PST 2011
#   I moved LaunchRPC to this directory from the launcher/rpc directory.
#
#   Cameron Christensen, Thursday, May 22, 2014
#   I added InvalidConversionException.
#
#   Kathleen Biagas, Mon Oct 31 15:23:31 PDT 2016
#   Add ZLIB_LIB to link libraries for visitcommon on Windows.
#
#   Kathleen Biagas, Tue Dec 20 15:43:20 PST 2016
#   Added GlyphTypes.
#
#****************************************************************************/

SET(COMM_SOURCES
comm/BadHostException.C
comm/BufferConnection.C
comm/CommunicationHeader.C
comm/Connection.C
comm/ConnectionGroup.C
comm/DConvert.C
comm/ExistingRemoteProcess.C
comm/FConvert.C
comm/FileConnection.C
comm/IConvert.C
comm/LaunchService.C
comm/LConvert.C
comm/ParentProcess.C
comm/RemoteProcess.C
comm/SocketBridge.C
comm/SocketConnection.C
comm/TypeRepresentation.C)
IF(WIN32)
    SET(COMM_WIN32_SOURCES comm/win32commhelpers.C)
ENDIF(WIN32)

SET(EXCEPTION_SOURCES
Exceptions/Database/BadPermissionException.C
Exceptions/Database/DBYieldedNoDataException.C
Exceptions/Database/FileDoesNotExistException.C
Exceptions/Database/InvalidDBTypeException.C
Exceptions/Database/InvalidFilesException.C
Exceptions/Database/InvalidSourceException.C
Exceptions/Database/InvalidTimeStepException.C
Exceptions/Database/InvalidVariableException.C
Exceptions/Database/InvalidZoneTypeException.C
Exceptions/Database/NonCompliantException.C
Exceptions/Database/NonCompliantFileException.C
Exceptions/Database/PointerNotInCacheException.C
Exceptions/Database/SiloException.C
Exceptions/Pipeline/AbortException.C
Exceptions/Pipeline/BadCellException.C
Exceptions/Pipeline/BadDomainException.C
Exceptions/Pipeline/BadIndexException.C
Exceptions/Pipeline/BadNodeException.C
Exceptions/Pipeline/BadVectorException.C
Exceptions/Pipeline/ExpressionException.C
Exceptions/Pipeline/GhostCellException.C
Exceptions/Pipeline/ImproperUseException.C
Exceptions/Pipeline/IncompatibleDomainListsException.C
Exceptions/Pipeline/IntervalTreeNotCalculatedException.C
Exceptions/Pipeline/InvalidCategoryException.C
Exceptions/Pipeline/InvalidCellTypeException.C
Exceptions/Pipeline/InvalidDimensionsException.C
Exceptions/Pipeline/InvalidLimitsException.C
Exceptions/Pipeline/InvalidMergeException.C
Exceptions/Pipeline/InvalidSetException.C
Exceptions/Pipeline/InvalidConversionException.C
Exceptions/Pipeline/LogicalIndexException.C
Exceptions/Pipeline/NoCurveException.C
Exceptions/Pipeline/NoDefaultVariableException.C
Exceptions/Pipeline/NoInputException.C
Exceptions/Pipeline/NonQueryableInputException.C
Exceptions/Pipeline/QueryArgumentException.C
Exceptions/Pipeline/StubReferencedException.C
Exceptions/Pipeline/UnexpectedValueException.C
Exceptions/Plotter/InvalidColortableException.C
Exceptions/Plotter/LibraryNotFoundException.C
)

SET(EXPRESSION_SOURCES
expr/ExprGrammar.C
expr/ExprInit.C
expr/ExprNode.C
expr/ExprParser.C
expr/ExprParseTreeNode.C
expr/ExprScanner.C
expr/InvalidExpressionException.C
expr/ParsingExprList.C
expr/RecursiveExpressionException.C
)

SET(MISC_SOURCES
misc/DebugStreamFull.C
misc/Environment.C
misc/FileFunctions.C
misc/InstallationFunctions.C
${VISIT_BINARY_DIR}/common/misc/ConfigureInfo.C
misc/PTY.C
misc/RuntimeSetting.C
misc/StackTimer.C
misc/TimingsManager.C
misc/VisItException.C
misc/VisItInit.C
)

SET(PARSER_SOURCES
parser/ConfiguratingItem.C
parser/ConfiguratingSet.C
parser/Dictionary.C
parser/Grammar.C
parser/Parser.C
parser/ParseTreeNode.C
parser/Rule.C
parser/Scanner.C
parser/Sequence.C
parser/Symbol.C
parser/Token.C
)

SET(PLUGIN_SOURCES
plugin/DatabasePluginInfo.C
plugin/DatabasePluginManager.C
plugin/InvalidDirectoryException.C
plugin/InvalidPluginException.C
plugin/OperatorPluginManager.C
plugin/PlotPluginManager.C
plugin/PluginBroadcaster.C
plugin/PluginManager.C
)

SET(PROXYBASE_SOURCES
proxybase/RemoteProxyBase.C
)

SET(STATE_SOURCES
state/AnimationAttributes.C
state/AnnotationAttributes.C
state/AnnotationObject.C
state/AnnotationObjectList.C
state/AppearanceAttributes.C
state/AttributeGroup.C
state/AttributeSubject.C
state/AttributeSubjectMap.C
state/AttributeSubjectSerialize.C
state/Axes2D.C
state/Axes3D.C
state/AxesArray.C
state/AxisAttributes.C
state/AxisLabels.C
state/AxisRestrictionAttributes.C
state/AxisTickMarks.C
state/AxisTitles.C
state/BoxExtents.C
state/ClientInformation.C
state/ClientInformationList.C
state/ClientMethod.C
state/ColorAttribute.C
state/ColorAttributeList.C
state/ColorControlPoint.C
state/ColorControlPointList.C
state/ColorTableAttributes.C
state/ColorTableManager.C
state/CompactSILRestrictionAttributes.C
state/ConfigManager.C
state/ConstructDataBinningAttributes.C
state/ContourOpAttributes.C
state/DatabaseAttributes.C
state/DatabaseCorrelation.C
state/DatabaseCorrelationList.C
state/DataNode.C
state/DBOptionsAttributes.C
state/DBPluginInfoAttributes.C
state/EngineList.C
state/EngineProperties.C
state/ExportDBAttributes.C
state/Expression.C
state/ExpressionList.C
state/FileOpenOptions.C
state/FontAttributes.C
state/GaussianControlPoint.C
state/GaussianControlPointList.C
state/GlobalAttributes.C
state/GlobalLineoutAttributes.C
state/GlyphTypes.C
state/LaunchProfile.C
state/LaunchRPC.C
state/MachineProfile.C
state/HostProfileList.C
state/InteractorAttributes.C
state/InternalResampleAttributes.C
state/KeepAliveRPC.C
state/KeyframeAttributes.C
state/LightAttributes.C
state/LightList.C
state/Line.C
state/LinearTransformAttributes.C
state/MapNode.C
state/MaterialAttributes.C
state/MeshManagementAttributes.C
state/MessageAttributes.C
state/MovieAttributes.C
state/NamespaceAttributes.C
state/NameschemeAttributes.C
state/Observer.C
state/ObserverToCallback.C
state/PickAttributes.C
state/PickVarInfo.C
state/PlaneAttributes.C
state/Plot.C
state/PlotInfoAttributes.C
state/PlotList.C
state/PlotQueryInfo.C
state/PluginManagerAttributes.C
state/PointAttributes.C
state/PrinterAttributes.C
state/ProcessAttributes.C
state/QueryAttributes.C
state/QueryList.C
state/QueryOverTimeAttributes.C
state/QuitRPC.C
state/RenderingAttributes.C
state/SaveWindowAttributes.C
state/SaveSubWindowAttributes.C
state/SaveSubWindowsAttributes.C
state/SeedMeAttributes.C
state/SelectionList.C
state/SelectionProperties.C
state/SelectionSummary.C
state/SelectionVariableSummary.C
state/SimulationUIValues.C
state/SILArrayAttributes.C
state/SILAttributes.C
state/SILMatrixAttributes.C
state/SILRestrictionAttributes.C
state/SimilarityTransformAttributes.C
state/SimpleObserver.C
state/SimulationCommand.C
state/SingleAttributeConfigManager.C
state/SphereAttributes.C
state/StatusAttributes.C
state/Subject.C
state/SurfaceFilterAttributes.C
state/SyncAttributes.C
state/ThresholdOpAttributes.C
state/TimeFormat.C
state/Variant.C
state/View2DAttributes.C
state/View3DAttributes.C
state/ViewAttributes.C
state/ViewAxisArrayAttributes.C
state/ViewCurveAttributes.C
state/ViewerClientAttributes.C
state/ViewerClientInformation.C
state/ViewerClientInformationElement.C
state/VisItRPC.C
state/VisualCueInfo.C
state/VisualCueList.C
state/WindowAttributes.C
state/WindowInformation.C
state/Xfer.C
state/XMLNode.C
state/JSONNode.C
)

SET(UTILITY_SOURCES
utility/AtomicProperties.C
utility/CoordUtils.C
utility/GeometricHelpers.C
utility/Namescheme.C
utility/StringHelpers.C
utility/Utility.C
utility/visit_gzstream.C
utility/void_ref_ptr.C
)
IF(WIN32)
    SET(UTILITY_WIN32_SOURCES utility/win32-regex.c)
    SET_SOURCE_FILES_PROPERTIES(utility/win32-regex.c 
        PROPERTIES LANGUAGE CXX)
ENDIF(WIN32)

INCLUDE_DIRECTORIES(
${VISIT_COMMON_INCLUDES}
)

ADD_LIBRARY(visitcommon
    ${COMM_SOURCES} ${COMM_WIN32_SOURCES}
    ${EXCEPTION_SOURCES}
    ${EXPRESSION_SOURCES}
    ${MISC_SOURCES}
    ${PARSER_SOURCES}
    ${PLUGIN_SOURCES}
    ${PROXYBASE_SOURCES}
    ${STATE_SOURCES}
    ${UTILITY_SOURCES} ${UTILITY_WIN32_SOURCES})

# Specify the libraries to link against on Windows
IF(WIN32)
    TARGET_LINK_LIBRARIES(visitcommon ws2_32 shlwapi userenv ${ZLIB_LIB})
ELSE(WIN32)
    TARGET_LINK_LIBRARIES(visitcommon ${ZLIB_LIB} ${CMAKE_THREAD_LIBS} ${DL_LIB})
    ADD_EXECUTABLE(StringHelpers_test utility/StringHelpers_test.C)
    TARGET_LINK_LIBRARIES(StringHelpers_test visitcommon ${ZLIB_LIB} ${CMAKE_THREAD_LIBS} ${DL_LIB})
    ADD_EXECUTABLE(Utility_test utility/Utility_test.C)
    TARGET_LINK_LIBRARIES(Utility_test visitcommon ${ZLIB_LIB} ${CMAKE_THREAD_LIBS} ${DL_LIB})
    ADD_EXECUTABLE(Namescheme_test utility/Namescheme_test.C)
    TARGET_LINK_LIBRARIES(Namescheme_test visitcommon ${ZLIB_LIB} ${CMAKE_THREAD_LIBS} ${DL_LIB})
    ADD_EXECUTABLE(MRUCache_test utility/MRUCache_test.C)
    ADD_EXECUTABLE(exprconfig expr/ExprConfig.C)
    TARGET_LINK_LIBRARIES(exprconfig visitcommon ${ZLIB_LIB} ${CMAKE_THREAD_LIBS} ${DL_LIB})
    ADD_EXECUTABLE(exprtest expr/test.C)
    TARGET_LINK_LIBRARIES(exprtest visitcommon ${ZLIB_LIB} ${CMAKE_THREAD_LIBS} ${DL_LIB})
    ADD_CUSTOM_TARGET(init)
    ADD_DEPENDENCIES(init exprconfig)
    ADD_CUSTOM_COMMAND(TARGET init POST_BUILD COMMAND exprconfig ExprInit.C
        WORKING_DIRECTORY ${VISIT_SOURCE_DIR}/common/expr)
ENDIF(WIN32)

VISIT_INSTALL_TARGETS(visitcommon)
