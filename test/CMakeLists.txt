cmake_minimum_required(VERSION 3.10)

project(stack_tests C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

enable_testing()

# Create the test executable
add_executable(test_stack
    test_stack.c
    ../stack.c
)

# Make sure the compiler can find stack.h
target_include_directories(test_stack PRIVATE ..)

target_compile_options(test_stack PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(test_stack PRIVATE m)

add_test(NAME test_stack COMMAND test_stack)