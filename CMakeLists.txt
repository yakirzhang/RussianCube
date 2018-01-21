cmake_minimum_required(VERSION 3.7)
project(RussianCube)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)
add_executable(RussianCube ${SOURCE_FILES})
message(STATUS ${SOURCE_FILES})

include_directories(include)