cmake_minimum_required (VERSION 2.8)

project (CppPrimeFifth)

file(GLOB_RECURSE X_SOURCES "src/*.cpp")
file(GLOB_RECURSE X_HEADERS "src/*.h")

set (INC "")
foreach (_headerFile ${X_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INC ${_dir})
endforeach()

include_directories(${INC})
add_executable (bin ${X_SOURCES})
