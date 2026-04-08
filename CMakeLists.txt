cmake_minimum_required(VERSION 3.24)
project(lab_c_tutor VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define a small library for reusable code.
add_library(project_lib 
            src/project.c
            src/thread_task.c)
target_include_directories(project_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

find_package(Threads REQUIRED)
target_link_libraries(project_lib PRIVATE Threads::Threads)


# Define the executable.
add_executable(lab_c_tutor src/main.c)
target_link_libraries(lab_c_tutor PRIVATE project_lib)

# Install targets and headers.
install(TARGETS lab_c_tutor project_lib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include)

# Enable testing support.
enable_testing()
add_subdirectory(tests)
