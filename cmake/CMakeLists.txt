cmake_minimum_required(VERSION 3.13)

project(test)

message("C++ features known to current CMake: " ${CMAKE_CXX_KNOWN_FEATURES})
foreach(FEATURE ${CMAKE_CXX_KNOWN_FEATURES})
    message(${FEATURE})
endforeach()
message("C++ features known by CMake & implemented by compiler: ")
foreach(FEATURE ${CMAKE_CXX_COMPILE_FEATURES})
    message(${FEATURE})
endforeach()

