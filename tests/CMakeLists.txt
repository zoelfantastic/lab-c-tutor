add_executable(test_project test_project.c)
target_include_directories(test_project PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(test_project PRIVATE project_lib Threads::Threads)
add_test(NAME project_test COMMAND test_project)
    