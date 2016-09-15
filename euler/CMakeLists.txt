file(GLOB_RECURSE X_SOURCES "*.cpp")

# Make every single .cpp file compile as executable
foreach(sourcefile ${X_SOURCES})
    string( REPLACE ".cpp" "" testname ${sourcefile} )
    string( REPLACE "/" "" targetname ${testname} )
    add_executable(${targetname} ${sourcefile})

    add_dependencies(${targetname} gtest)
    include_directories(${source_dir}/include)
    target_link_libraries(${targetname} ${binary_dir}/libgtest.a)
    target_link_libraries(${targetname} ${binary_dir}/libgtest_main.a)
    target_link_libraries(${targetname} ${CMAKE_THREAD_LIBS_INIT})

    add_test(${sourcefile} ${targetname})


endforeach(sourcefile ${X_SOURCES})
