cmake_minimum_required(VERSION 3.10)
project(cmpx)

# Set the include directory for the header-only library
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create a shared library from cmpx.cpp
add_library(cmpx SHARED cmpx.cpp)

# Add an example executable
add_executable(example example/main.cpp)

# Link the example executable with the shared library
target_link_libraries(example cmpx)
