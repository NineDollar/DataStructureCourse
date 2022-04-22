include_directories(../../include/courseDesign/)
include_directories(../../googletest/include/gtest)

aux_source_directory(. DIR_LIB)
add_library(courseDesign ${DIR_LIB})
target_link_libraries(courseDesign gtest gtest_main)
