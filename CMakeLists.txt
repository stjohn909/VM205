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

set(BCM2835_INCLUDE_PATH /usr/local/include)
set(BCM2835_LIBRARY_PATH /usr/local/lib)

find_library(BCM2835_LIB bcm2835 PATH ${BCM2835_LIBRARY_PATH})
set(BCM2835_LIBRARIES ${BCM2835_LIB})

# General includes
include_directories(include/)
include_directories(${BCM2835_INCLUDE_PATH})

# Source files
file(GLOB VM205_SOURCE src/*.c)

# Header files
file(GLOB VM205_HEADERS include/vm205/*.h)

# Create a library file
# add_library(vm205 SHARED ${VM205_SOURCE})
add_executable(vm205 ${VM205_SOURCE})

target_link_libraries(vm205 ${BCM2835_LIBRARIES})

# install(TARGETS vm205 LIBRARY DESTINATION lib)
# install(FILES ${VM205_HEADERS} DESTINATION include/vm205)