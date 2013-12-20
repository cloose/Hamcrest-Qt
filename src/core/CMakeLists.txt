#
# Hamcrest-Qt library
#
# Github: https://github.com/cloose/Hamcrest-Qt
#

set(hamcrestqtcore_SRCS
    basedescription.cpp
    description.cpp
    matcherassert.cpp
    stringdescription.cpp
    matcher/stringcontains.cpp
    matcher/stringendswith.cpp
    matcher/stringstartswith.cpp
)

set(hamcrestqtcore_HDRS
    basedescription.h
    basematcher.h
    description.h
    diagnosingmatcher.h
    matcher.h
    matcherassert.h
    selfdescribing.h
    stringdescription.h
    tostring_p.h
    matcher/allof.h
    matcher/anyof.h
    matcher/areequal_p.h
    matcher/is.h
    matcher/isanything.h
    matcher/isequal.h
    matcher/isnot.h
    matcher/shortcutcombination.h
    matcher/stringcontains.h
    matcher/stringendswith.h
    matcher/stringstartswith.h
    matcher/substringmatcher.h
)

add_library(HamcrestQtCore SHARED ${hamcrestqtcore_SRCS})
add_library(HamcrestQt::Core ALIAS HamcrestQtCore)
set_property(TARGET HamcrestQtCore PROPERTY EXPORT_NAME Core)

target_link_libraries(HamcrestQtCore PUBLIC Qt5::Core Qt5::Test)

# Set include directories for users of this library
message("$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>")
message("$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>")

target_include_directories(HamcrestQtCore
                           INTERFACE
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>")
                           
set_target_properties(HamcrestQtCore PROPERTIES VERSION ${HAMCRESTQT_VERSION})

set(CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/HamcrestQtCore")
set(INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_INCLUDEDIR}/HamcrestQtCore")

include(CMakePackageConfigHelpers)
configure_package_config_file(HamcrestQtCoreConfig.cmake.in HamcrestQtCoreConfig.cmake
                              INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR}
                              PATH_VARS INCLUDE_INSTALL_DIR)
                              
write_basic_package_version_file(HamcrestQtCoreConfigVersion.cmake
    VERSION ${HAMCRESTQT_VERSION}
    COMPATIBILITY SameMajorVersion)

install(TARGETS HamcrestQtCore DESTINATION ${CMAKE_INSTALL_LIBDIR} EXPORT HamcrestQtCoreTargets)

install(EXPORT HamcrestQtCoreTargets FILE HamcrestQtCoreTargets.cmake NAMESPACE HamcrestQt::
        DESTINATION ${CMAKECONFIG_INSTALL_DIR})

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/HamcrestQtCoreConfig.cmake"
        DESTINATION ${CMAKECONFIG_INSTALL_DIR})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/HamcrestQtCoreConfigVersion.cmake
        DESTINATION ${CMAKECONFIG_INSTALL_DIR})
        
install(FILES ${hamcrestqtcore_HDRS} DESTINATION ${INCLUDE_INSTALL_DIR})
