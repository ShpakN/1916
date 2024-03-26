cmake_minimum_required(VERSION 3.26)
project(19_16 C)

set(CMAKE_C_STANDARD 11)

add_executable(19_16 main.c)
add_library(data_structures
        matrix/matrix.c
)
target_link_libraries(data_structures algorithms)