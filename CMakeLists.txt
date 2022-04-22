cmake_minimum_required(VERSION 3.21)
project(DataStructureCourse)

set(CMAKE_CXX_STANDARD 14)

# 启用测试
enable_testing()

# 遍历所有源文件，增加到变量中
aux_source_directory(. DIR_SRCS)

# 子文件
add_subdirectory(lib/task2/)
add_subdirectory(lib/courseDesign/)
add_subdirectory(googletest/)

# 头文件
include_directories(include/task2/)
include_directories(include/courseDesign/)
include_directories(googletest/include/gtest/)

set(GTEST_LIB gtest gtest_main)

# 可执行文件
add_executable(main ${DIR_SRCS})
add_executable(my_test  ${CMAKE_SOURCE_DIR}/test/test.cpp)

# 链接库
target_link_libraries(main gtest gtest_main task2 courseDesign)
target_link_libraries(my_test gtest gtest_main task2 courseDesign)

# 测试
add_test(NAME my_test COMMAND my_test)