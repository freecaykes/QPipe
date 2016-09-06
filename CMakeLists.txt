cmake_minimum_required (VERSION 2.8)

project (xmlog)
set (CMAKE_BUILD_TYPE Release)

# Version
set (xmlog_VERSION_MAJOR 1)

# include c++ 11
include (CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG ("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG ("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if (COMPILER_SUPPORTS_CXX11)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif (COMPILER_SUPPORTS_CXX0X)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else ()
        message (STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif ()

# headers
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)

# create library
add_library(xmlog SHARED src/XMLWriter.cpp src/ExecutableDispatcher.cpp src/ApplicationThread.cpp)

# Link library
add_subdirectory (lib)
target_include_directories (lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
