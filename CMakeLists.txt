cmake_minimum_required(VERSION 4.0.1)
project (main)

# 设置 C 语言标准为 C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
aux_source_directory (src SRC_LIST)
include_directories (inc)
add_executable(main ${SRC_LIST})