cmake_minimum_required(VERSION 3.8)

add_library(owi_optional INTERFACE) 
target_include_directories(owi_optional INTERFACE include/) 
target_compile_features(owi_optional INTERFACE cxx_std_17)

add_subdirectory(examples)
add_subdirectory(tests)