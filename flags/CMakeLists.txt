cmake_minimum_required(VERSION 3.1)

project(flags)

# cmake-format: off
# this is a global variable for the entire project (starts with CMAKE prefix)
# set(CMAKE_CXX_STANDARD 17)

# this sets the output directory for runtime targets (executables added by
# add_executable shared libraries added by add_library on DLL platforms [windows / OS] .dll) 
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
# cmake-format: on

add_executable(${PROJECT_NAME} main.cpp)

set(FLAGS -Wall -Wextra -Wconversion -pedantic -O3)

# thanks to this function we can set desired properties just for this one
# target, keeping the global properties untouched
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror
                                               -Wconversion)
