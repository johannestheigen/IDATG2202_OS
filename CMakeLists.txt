cmake_minimum_required(VERSION 4.0)
project(IDATG2202_OS C)

set(CMAKE_C_STANDARD 11)

add_executable(IDATG2202_OS
        parallel_processes.c
        Parent_child.c
        Parent_child_writer.c
)
