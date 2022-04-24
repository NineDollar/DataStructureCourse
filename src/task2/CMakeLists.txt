include_directories(../../include/task2)

aux_source_directory(. DIR_LIB)
add_library(task2 ${DIR_LIB})