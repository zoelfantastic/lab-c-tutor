cmake_minimum_required(VERSION 3.24)
project(lab_c_tutor VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Accept TUTOR argument for selecting which task to build
if (NOT DEFINED TUTOR)
    set(TUTOR main)
endif()

# Validate that the selected TUTOR source file exists
set(TUTOR_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/${TUTOR}_task.c")
set(TUTOR_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/${TUTOR}_task.h")

if (NOT EXISTS "${TUTOR_SOURCE}")
    message(FATAL_ERROR "TUTOR source file not found: ${TUTOR_SOURCE}")
endif()

if (NOT EXISTS "${TUTOR_HEADER}")
    message(FATAL_ERROR "TUTOR header file not found: ${TUTOR_HEADER}")
endif()

message(STATUS "Building with TUTOR=${TUTOR}")
message(STATUS "Source: ${TUTOR_SOURCE}")
message(STATUS "Header: ${TUTOR_HEADER}")

# Define the library for common reusable code
add_library(project_lib src/thread_task.c src/mutex_task.c src/main_task.c)
target_include_directories(project_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Find threading library if needed
find_package(Threads REQUIRED)
target_link_libraries(project_lib PRIVATE Threads::Threads)

# Define the executable with the selected TUTOR source
add_executable(lab_c_tutor ${TUTOR_SOURCE})
target_include_directories(lab_c_tutor PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(lab_c_tutor PRIVATE project_lib Threads::Threads)

# # Install targets and headers.
install(TARGETS lab_c_tutor 
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include)

# # Enable testing support.
# enable_testing()
# add_subdirectory(tests)
