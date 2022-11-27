cmake_minimum_required(VERSION 3.0) # setting this is required
project(vm205)            # this sets the project name

# Glob all the source files to be built.
file(GLOB SRCS ./src/*.cpp )

add_library(libvm205 SHARED ${SRCS} )
target_include_directories(libvm205 PUBLIC ./include )
target_link_libraries(libvm205 SDL2 pigpio pigpiod_if2 GLESv2)

add_executable(${PROJECT_NAME} ./src/main.cpp )
target_include_directories(${PROJECT_NAME}  PUBLIC ./include/vm205 )
target_link_libraries(${PROJECT_NAME}  SDL2 libvm205 pigpio pigpiod_if2 GLESv2)
