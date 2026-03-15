cmake_minimum_required(VERSION 3.30)
project(FilesAndArrays_1__1_ C)

set(CMAKE_C_STANDARD 11)

include_directories(FilesAndArrays/FilesAndArrays/lab6-files_dynamic_arrays)
include_directories(FilesAndArrays/FilesAndArrays/lab6-files_dynamic_arrays/utils)

add_executable(FilesAndArrays_1__1_
    FilesAndArrays/FilesAndArrays/lab6-files_dynamic_arrays/utils/fileUtils.c
    FilesAndArrays/FilesAndArrays/lab6-files_dynamic_arrays/utils/fileUtils.h
    FilesAndArrays/FilesAndArrays/lab6-files_dynamic_arrays/utils/sortUtils.c
    FilesAndArrays/FilesAndArrays/lab6-files_dynamic_arrays/utils/sortUtils.h
    FilesAndArrays/FilesAndArrays/lab6-files_dynamic_arrays/cscd240Lab6.c
    FilesAndArrays/FilesAndArrays/lab6-files_dynamic_arrays/lab6.c
    FilesAndArrays/FilesAndArrays/lab6-files_dynamic_arrays/lab6.h)
