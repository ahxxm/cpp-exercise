cmake_minimum_required(VERSION 2.8)

project(cpp-exercise)

enable_testing()


# Download and install GoogleTest
find_package(Threads REQUIRED)

# http://www.kaizou.org/2014/11/gtest-cmake/
# Enable ExternalProject CMake module
include(ExternalProject)

ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/release-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)

# Create a libgtest target to be used as a dependency by test programs
ExternalProject_Get_Property(gtest source_dir binary_dir)


# Use C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

# CMakeLists.txt in subdirectories
add_subdirectory(cppp)
add_subdirectory(algo)
add_subdirectory(effective-modern-cpp)
