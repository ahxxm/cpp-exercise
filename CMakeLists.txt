cmake_minimum_required(VERSION 2.8)
project(cpp-exercise)
enable_testing()


# Download and install GoogleTest
## http://www.kaizou.org/2014/11/gtest-cmake/
## Enable ExternalProject CMake module
find_package(Threads REQUIRED)
include(ExternalProject)
message(STATUS "Building gtest")
ExternalProject_Add(
  gtest
  URL https://github.com/google/googletest/archive/release-1.7.0.zip
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
  # Disable install step
  INSTALL_COMMAND ""
  )
## Create a libgtest target to be used as a dependency by test programs
ExternalProject_Get_Property(gtest source_dir binary_dir)


# Boost: always use multi-threaded, include as system to supress warning
find_package(Boost 1.68 COMPONENTS system filesystem unit_test_framework REQUIRED)
if (Boost_FOUND)
  message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
  message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
  message(STATUS "Boost_VERSION: ${Boost_VERSION}")
  include_directories(${Boost_INCLUDE_DIRS})
endif (Boost_FOUND)
set(Boost_USE_MULTI_THREADED ON)
include_directories(SYSTEM "${Boost_INCLUDE_DIRS}")


# Use C++14 standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# enable profiler for gprof, and force to use gold linker
# Usage:
#   ./bin; gprof bin gmon.out;
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold -fsanitize=address,leak,undefined -fno-omit-frame-pointer -pg")
endif()

# CMakeLists.txt in subdirectories
add_subdirectory(cppp)
add_subdirectory(algo)
add_subdirectory(effective-modern-cpp)
add_subdirectory(clrs)
