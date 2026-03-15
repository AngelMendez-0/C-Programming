cmake_minimum_required(VERSION 3.30)
project(CSCD240_Lab7_STARTER C)

set(CMAKE_C_STANDARD 11)

include_directories("CSCD240_Lab7 STARTER/__MACOSX/Lab9")
include_directories("CSCD240_Lab7 STARTER/__MACOSX/Lab9/utils")
include_directories("CSCD240_Lab7 STARTER/Lab7")
include_directories("CSCD240_Lab7 STARTER/Lab7/utils")

add_executable(CSCD240_Lab7_STARTER
    "CSCD240_Lab7 STARTER/Lab7/utils/fileUtils.c"
    "CSCD240_Lab7 STARTER/Lab7/utils/fileUtils.h"
    "CSCD240_Lab7 STARTER/Lab7/utils/utils.c"
    "CSCD240_Lab7 STARTER/Lab7/utils/utils.h"
    "CSCD240_Lab7 STARTER/Lab7/cscd240Lab7.c"
    "CSCD240_Lab7 STARTER/Lab7/lab7.c"
    "CSCD240_Lab7 STARTER/Lab7/lab7.h")
