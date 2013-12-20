cmake_minimum_required(VERSION 2.8.11)

project(HamcrestQt)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Enable CTest
enable_testing()

# Set version number variables
set(HAMCRESTQT_MAJOR_VERSION 0)
set(HAMCRESTQT_MINOR_VERSION 0)
set(HAMCRESTQT_PATCH_VERSION 1)
set(HAMCRESTQT_VERSION ${HAMCRESTQT_MAJOR_VERSION}.${HAMCRESTQT_MINOR_VERSION}.${HAMCRESTQT_PATCH_VERSION})

message(STATUS "Using CMake ${CMAKE_VERSION}")
message(${HAMCRESTQT_VERSION})
                              
# Setup the the lib and include directory on a per platform basis
if(CMAKE_COMPILER_IS_GNUCXX)
    include(GNUInstallDirs)
endif(CMAKE_COMPILER_IS_GNUCXX)

if(NOT DEFINED CMAKE_INSTALL_LIBDIR)
    set(CMAKE_INSTALL_LIBDIR lib)
endif(NOT DEFINED CMAKE_INSTALL_LIBDIR)

if(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
    set(CMAKE_INSTALL_INCLUDEDIR include)
endif(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)

### Dependencies ###

set(REQUIRED_QT_VERSION 5.0.0)
find_package(Qt5Core ${REQUIRED_QT_VERSION} REQUIRED NO_MODULE)
find_package(Qt5Test ${REQUIRED_QT_VERSION} REQUIRED NO_MODULE)

### Subdirs ###

add_subdirectory(src)
