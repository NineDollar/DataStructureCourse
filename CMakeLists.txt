cmake_minimum_required(VERSION 3.21)
project(DataStructureCourse)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_SRCS)

include_directories(Include/Task2/)

add_executable(main ${DIR_SRCS})

add_subdirectory(Lib/Task2/)

target_link_libraries(main Task2)

