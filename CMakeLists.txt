cmake_minimum_required (VERSION 2.8.11)

project (easy_nurbs)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Set the cmake install path for find package to work.
If(CMAKE_SYSTEM_NAME MATCHES "Windows")
  set (CMAKE_PREFIX_PATH "C:\\Qt\\5.7\\msvc2015_64")
Elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
  set (CMAKE_PREFIX_PATH /home/prashanth/Qt5.7.0/5.7/gcc_64)
Endif()

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5OpenGL)

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
set(SOURCES ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/mainwindow.cpp ${SOURCE_DIR}/glwidget.cpp ${SOURCE_DIR}/mainwindow.h  ${SOURCE_DIR}/glwidget.h ${SOURCE_DIR}/cnurb.cpp ${SOURCE_DIR}/cnurb.h
    ${SOURCE_DIR}/cpmesh.cpp ${SOURCE_DIR}/cpmesh.h ${SOURCE_DIR}/teapot.h
    ${SOURCE_DIR}/shader/passThrough.frag  ${SOURCE_DIR}/shader/passThrough.vert )


add_executable(easy_nurbs  WIN32 ${SOURCES})

# Use the Widgets module from Qt 5.
target_link_libraries(easy_nurbs Qt5::Widgets Qt5::OpenGL)

# Make sure the shaders are copied to the binary tree.
add_custom_command(TARGET easy_nurbs POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory  ${SOURCE_DIR}/shader $<TARGET_FILE_DIR:easy_nurbs>/shader)
