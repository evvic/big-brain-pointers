cmake_minimum_required(VERSION 3.10)
project(MemoryLibrary)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add the library
add_library(memory SHARED src/unique_ptr.cpp)

# Add the executable for testing
add_executable(test_memory tests/main.cpp)

# Link the library to the test executable
target_link_libraries(test_memory memory)
