cmake_minimum_required (VERSION 2.8)

project (CppPrimeFifth)

# http://www.kaizou.org/2014/11/gtest-cmake/
# Enable ExternalProject CMake module
enable_testing()
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/release-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)


# Use C++14 standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

file(GLOB_RECURSE X_SOURCES "src/*.cpp")
file(GLOB_RECURSE X_HEADERS "src/*.h")

foreach (_headerFile ${X_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INC ${_dir})
endforeach()

# Make every single .cpp file compile as executable
foreach(sourcefile ${X_SOURCES})
    string( REPLACE ".cpp" "" testname ${sourcefile} )
    string( REPLACE "/" "" targetname ${testname} )
    add_executable(${targetname} ${sourcefile})

    # add_test(test_name filename)
    add_test(${sourcefile} ${targetname})
endforeach(sourcefile ${X_SOURCES})
