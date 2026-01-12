cmake_minimum_required(VERSION 3.10)

project(stack_tests C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Create the test executable
add_executable(test_stack
    test_stack.c
    ../stack.c
)

# Make sure the compiler can find stack.h
target_include_directories(test_stack PRIVATE ..)
