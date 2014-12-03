#
# Copyright (C) 2014 Velleman nv
#
# This software may be modified and distributed under the terms
# of the MIT license.  See the LICENSE file for details.
#

cmake_minimum_required(VERSION 2.6)

# Project settings
project(vm205)
set(CMAKE_BUILD_TYPE Release)

# General includes
include_directories(include/)

# Source files
file(GLOB VM205_SOURCE src/*.c)

# Header files
file(GLOB VM205_HEADERS include/vm205/*.h)

# Create a library file
add_library(velbus SHARED ${VM205_SOURCE})

install(TARGETS vm205 LIBRARY DESTINATION lib)
install(FILES ${VM205_HEADERS} DESTINATION include/vm205)