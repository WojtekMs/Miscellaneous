cmake_minimum_required(VERSION 3.1)

project(attributes)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -Wconversion -pedantic)

