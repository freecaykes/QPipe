cmake_minimum_required (VERSION 2.8)

project (xmlog_examples)
set (CMAKE_BUILD_TYPE Release)

# Version
set (xmlog_VERSION_MAJOR 1)

# include c++ 11
include (CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG ("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG ("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

add_executable (self_std_cout_capture ExampleStdCoutCapture.cpp)
add_executable (external_std_cout_capture ExampleStdCoutExternalCapture.cpp)

target_link_libraries (self_std_cout_capture LINK_SHARED lib)
target_link_libraries (external_std_cout_capture LINK_SHARED lib)
