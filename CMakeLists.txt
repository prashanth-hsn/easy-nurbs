cmake_minimum_required (VERSION 2.8.11)

project (easy_nurbs)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Set the cmake install path for find package to work.
set (CMAKE_PREFIX_PATH /home/prashanth/Qt5.7.0/5.7/gcc_64)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)

# Set the output directory
If(NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE Debug)
Endif(NOT CMAKE_BUILD_TYPE)

If(CMAKE_BUILD_TYPE EQUAL "Debug")
  set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/binaries/debug)
Elseif(CMAKE_BUILD_TYPE EQUAL "Release")
	set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/binaries/release)
Endif()

set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# All the source files are in ./src 
include_directories("{PROJECT_SOURCE_DIR}/src")

set (SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)


# Configure the version number in the cmake setup.
set (easy_nurbs_VERSION_MAJOR 1)
set (easy_nurbs_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${SOURCE_DIR}/easy_nurbs.h.in"
  "${CMAKE_BINARY_DIR}/easy_nurbs.h"
)
# add the binary tree to the search path for include files
# so that we will find easy_nurbs.h  
include_directories("${CMAKE_BINARY_DIR}")

set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set (SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

add_executable(easy_nurbs  WIN32 ${SOURCE_DIR}/easy_nurbs.cpp)
# Use the Widgets module from Qt 5.
target_link_libraries(easy_nurbs Qt5::Widgets)


# cmake -H. -Bbuild
# cmake --build build -- -j3