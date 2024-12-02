cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)

project(ExampleGTest LANGUAGES CXX)

include(FetchContent)

# Pulls googletest repo for make to build gtest and gmock
FetchContent_Declare(
    googletest
    GIT_REPOSITORY git@github.com:google/googletest.git
    GIT_TAG        35d0c365609296fa4730d62057c487e3cfa030ff
)

FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} src/dummy.cpp test/testDummy.cpp )

target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)

include(GoogleTest)

gtest_discover_tests(${PROJECT_NAME})

include_directories(include)

# set(CMAKE_THREAD_LIBS_INIT "-lpthread")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" "-pthread")
# set(CMAKE_HAVE_THREADS_LIBRARY 1)
# set(CMAKE_USE_WIN32_THREADS_INIT 0)
# set(CMAKE_USE_PTHREADS_INIT 1)
# set(THREADS_PREFER_PTHREAD_FLAG ON)
