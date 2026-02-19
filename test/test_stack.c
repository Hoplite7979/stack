#include "stack.h"

#include <assert.h>
#include <math.h>
#include <stddef.h>

// Compares two doubles with a tolerance to avoid strict floating-point equality issues.
static void assert_double_eq(double actual, double expected)
{
    const double epsilon = 1e-9;
    assert(fabs(actual - expected) < epsilon);
}

// Verifies stack creation succeeds and that a new stack starts empty with no error.
static void test_stack_create_and_initial_state(void)
{
    Stack* stack = stack_create();

    assert(stack != NULL);
    assert(stack_size(stack) == 0U);
    assert(stack_is_empty(stack));
    assert(stack_get_error(stack) == STACK_SUCCESS);

    stack_destroy(stack);
}

// Verifies every API function handles NULL inputs safely according to current implementation.
static void test_null_input_behavior(void)
{
    assert(stack_size(NULL) == 0U);
    assert(stack_is_empty(NULL));
    assert_double_eq(stack_top(NULL), 0.0);
    assert_double_eq(stack_pop(NULL), 0.0);
    assert(stack_get_error(NULL) == STACK_ERROR_NULL);

    stack_push(NULL, 42.0);
    stack_clear(NULL);
    stack_destroy(NULL);
}

// Verifies push/top/pop behavior and checks error transitions for normal and empty-stack cases.
static void test_push_top_pop_and_error_transitions(void)
{
    Stack* stack = stack_create();
    assert(stack != NULL);

    stack_push(stack, 3.25);
    assert(stack_size(stack) == 1U);
    assert(!stack_is_empty(stack));
    assert(stack_get_error(stack) == STACK_SUCCESS);

    assert_double_eq(stack_top(stack), 3.25);
    assert(stack_get_error(stack) == STACK_SUCCESS);

    assert_double_eq(stack_pop(stack), 3.25);
    assert(stack_size(stack) == 0U);
    assert(stack_is_empty(stack));
    assert(stack_get_error(stack) == STACK_SUCCESS);

    assert_double_eq(stack_pop(stack), 0.0);
    assert(stack_get_error(stack) == STACK_ERROR_EMPTY);

    assert_double_eq(stack_top(stack), 0.0);
    assert(stack_get_error(stack) == STACK_ERROR_EMPTY);

    stack_destroy(stack);
}

// Verifies the stack obeys LIFO order (last in, first out).
static void test_lifo_order(void)
{
    Stack* stack = stack_create();
    assert(stack != NULL);

    stack_push(stack, 1.0);
    stack_push(stack, 2.0);
    stack_push(stack, 3.0);

    assert(stack_size(stack) == 3U);
    assert_double_eq(stack_pop(stack), 3.0);
    assert_double_eq(stack_pop(stack), 2.0);
    assert_double_eq(stack_pop(stack), 1.0);
    assert(stack_is_empty(stack));

    stack_destroy(stack);
}

// Verifies stack_clear removes all elements and resets size/empty state without error.
static void test_clear(void)
{
    Stack* stack = stack_create();
    assert(stack != NULL);

    stack_push(stack, 10.0);
    stack_push(stack, 20.0);
    stack_push(stack, 30.0);

    assert(stack_size(stack) == 3U);
    stack_clear(stack);

    assert(stack_size(stack) == 0U);
    assert(stack_is_empty(stack));
    assert(stack_get_error(stack) == STACK_SUCCESS);

    stack_destroy(stack);
}

// Runs all unit tests in this file; the program exits non-zero if any assert fails.
int main(void)
{
    test_stack_create_and_initial_state();
    test_null_input_behavior();
    test_push_top_pop_and_error_transitions();
    test_lifo_order();
    test_clear();

    return 0;
}