project(GNUextensions C)
set(CMAKE_C_FLAGS "-std=gnu99")
# set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_COMPILER clang)
add_executable(demo main.c)