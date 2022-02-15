cmake_minimum_required(VERSION 3.0)
project(cpp-exercise)
enable_testing()

# enable conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Boost: always use multi-threaded, include as system to supress warning
find_package(Threads REQUIRED)
find_package(Boost 1.78 REQUIRED)
if (Boost_FOUND)
  message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
  message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
  message(STATUS "Boost_VERSION: ${Boost_VERSION}")
  include_directories(${Boost_INCLUDE_DIRS})
endif (Boost_FOUND)
set(Boost_USE_MULTI_THREADED ON)
# include_directories(SYSTEM "${Boost_INCLUDE_DIRS}")


# Use C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# enable profiler for gprof, and force to use gold linker
# Usage:
#   ./bin; gprof bin gmon.out;
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold -fsanitize=address,leak,undefined -fno-omit-frame-pointer -pg")
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto=thin")
endif()

# CMakeLists.txt in subdirectories
add_subdirectory(cppp)
add_subdirectory(algo)
add_subdirectory(effective-modern-cpp)
add_subdirectory(clrs)
