cmake_minimum_required(VERSION 3.0.0)
project(ActorPlus)


list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib/cmake-modules")



set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}\\test\\plugins)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


add_subdirectory(src)