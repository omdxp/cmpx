cmake_minimum_required(VERSION 3.19)
project(cmpx)

include_directories(.)

add_library(cmpx SHARED cmpx)

set_target_properties(cmpx PROPERTIES LINKER_LANGUAGE CPP)

add_executable(example example/main.cpp)

target_link_libraries(example cmpx)

message("CMakeLists.txt updated successfully.")
