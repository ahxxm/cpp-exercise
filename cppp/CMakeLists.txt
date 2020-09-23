file(GLOB_RECURSE X_SOURCES "src/*.cpp")
file(GLOB_RECURSE X_HEADERS "src/*.h")

SET (INC "")
foreach (_headerFile ${X_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INC ${_dir})
endforeach()

include_directories(${INC})


# Make every single .cpp file compile as executable
foreach(sourcefile ${X_SOURCES})
    string( REPLACE ".cpp" "" testname ${sourcefile} )
    string( REPLACE "/" "" targetname ${testname} )
    add_executable(${targetname} ${sourcefile})

    include_directories(${source_dir}/include)
    target_link_libraries(${targetname} ${CMAKE_THREAD_LIBS_INIT} ${CONAN_LIBS})

    add_test(NAME ${sourcefile} COMMAND $<TARGET_FILE:${targetname}>)


endforeach(sourcefile ${X_SOURCES})
