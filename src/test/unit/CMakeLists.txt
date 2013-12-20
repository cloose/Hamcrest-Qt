#
# Unit Test Project for Hamcrest-Qt library
#
# Github: https://github.com/cloose/Hamcrest-Qt
#
include_directories(${CMAKE_SOURCE_DIR}/src/core)

### unittest ###

set(unittest_SRCS
    main.cpp 
    alloftest.cpp 
    anyoftest.cpp 
    basedescriptiontest.cpp 
    basematchertest.cpp 
    isanythingtest.cpp 
    isequaltest.cpp 
    isnottest.cpp 
    istest.cpp 
    matcherasserttest.cpp 
    abstractmatcher.cpp
)

add_executable(unittest ${unittest_SRCS})
target_link_libraries(unittest HamcrestQtCore)
qt5_use_modules(unittest Test)

add_test(NAME unittest COMMAND unittest)
