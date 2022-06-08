cmake_minimum_required(VERSION 3.21)
project(DataStructureCourse)

set(CMAKE_CXX_STANDARD 11)
#
## C的解决办法
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")
## C++ 的解决办法
#set(CMAKE_CPP_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

# 启用测试
enable_testing()

# 遍历所有源文件，增加到变量中
aux_source_directory(. DIR_SRCS)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/courseDesign/prim DIR_SRCS_PRIM)
aux_source_directory(${CMAKE_SOURCE_DIR}/test/ DIR_SRCS_TEST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/courseDesign/kruskal DIR_SRCS_KRUSKAL)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/courseDesign/color_play DIR_SRCS_COLOR_PLAY)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/courseDesign/park DIR_SRCS_PARK)

# 子文件夹
add_subdirectory(src/task2/)
add_subdirectory(googletest/)
add_subdirectory(test/)

# 头文件
include_directories(boost/)
include_directories(spdlog/)
include_directories(include/task2/)
include_directories(include/courseDesign/prim)
include_directories(include/courseDesign/kruskal)
include_directories(googletest/)
set(GTEST_LIB gtest gtest_main)

# 可执行文件
add_executable(main ${DIR_SRCS})
add_executable(my_test ${DIR_SRCS_TEST})
add_executable(prim ${DIR_SRCS_PRIM})
add_executable(kruskal ${DIR_SRCS_KRUSKAL})
add_executable(color_play ${DIR_SRCS_COLOR_PLAY})
add_executable(park ${DIR_SRCS_PARK})

# 链接库
target_link_libraries(main gtest gtest_main task2)
target_link_libraries(my_test gtest gtest_main task2)

# 测试
add_test(NAME my_test COMMAND my_test)
add_executable(exp2-1 src/book/task2/exp2-1.cpp)
add_executable(exp2-2 src/book/task2/exp2-2.cpp)
add_executable(experiment2-2 src/book/task5/experiment2-2.cpp)
add_executable(experiment2-6 src/book/task8/experiment2-6.cpp)
add_executable(experiment2-10 src/book/task8/experiment2-10.cpp)
add_executable(experiment2-13 src/book/task2/experiment2-13.cpp)
add_executable(experiment2-14 src/book/task2/experiment2-14.cpp)
add_executable(experiment2-16 src/book/task2/experiment2-16.cpp)
add_executable(experiment2-1 src/book/task3/experiment2-1.cpp)
add_executable(experiment2-3 src/book/task8/experiment2-3.cpp)

add_executable(experiment2-9 src/book/task6/experiment2-9.cpp)
add_executable(experiment2-15 src/book/task6/experiment2-15.cpp)
add_executable(experiment1-2 src/book/task8/experiment1-2.cpp)
add_executable(experiment1-5 src/book/task7/experiment1-5.cpp)

add_executable(experiment1-4 src/book/task9/experiment1-4.cpp)

add_executable(experiment2-8 src/book/task8/experiment2-8.cpp)

add_executable(experiment1-7 src/book/task9/experiment1-7.cpp)