add_executable(test_project test_project.c)
target_link_libraries(test_project PRIVATE project_lib)
add_test(NAME project_test COMMAND test_project)
    