cmake_minimum_required(VERSION 3.21)
project(DataStructureCourse)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_SRCS)

include_directories(Include/Task2/)
include_directories(Include/CourseDesign/)

add_executable(main ${DIR_SRCS})

add_subdirectory(Lib/Task2/)
add_subdirectory(Lib/CourseDesign/)

target_link_libraries(main Task2)
target_link_libraries(main CourseDesign)

