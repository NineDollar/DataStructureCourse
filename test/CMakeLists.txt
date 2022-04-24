include_directories(../googletest/)
include_directories(../boost/)
include_directories(../spdlog/)

aux_source_directory(. DIR_LIB)
add_library(my_test_lib ${DIR_LIB})
target_link_libraries(my_test_lib gtest gtest_main)