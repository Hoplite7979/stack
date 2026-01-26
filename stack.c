#include "stack.h"

#include <stdlib.h>
#include <assert.h>

/// ============================================================
/// Internal Structures
/// ============================================================

typedef struct StackNode {
    double value;
    struct StackNode* next;
} StackNode;

struct Stack {
    StackNode* top;
    size_t size;
    StackError error;
};

/// New Error Function
StackError stack_get_error(const Stack* stack)
{
    if (!stack) {
        return STACK_ERROR_NULL;
    }

    return stack->error;
}

/// ============================================================
/// Creation / Destruction
/// ============================================================

/// (4)
Stack* stack_create(void)
{
    Stack* stack = malloc(sizeof(Stack));
    if (!stack) {
        return NULL;
    }

    stack->top = NULL;
    stack->size = 0;
    stack->error = STACK_SUCCESS;

    return stack;
}

/// (11)
void stack_destroy(Stack* stack)
{
    if (!stack) {
        return;
    }

    stack_clear(stack);
    free(stack);
}

/// ============================================================
/// Capacity / State
/// ============================================================

/// (6)
size_t stack_size(const Stack* stack)
{
    if (!stack) {
        return 0;
    }

    ((Stack*)stack)->error = STACK_SUCCESS;
    return stack->size;
}

/// (7)
bool stack_is_empty(const Stack* stack)
{
    if (!stack) {
        return true;
    }

    ((Stack*)stack)->error = STACK_SUCCESS;
    return stack->size == 0;
}

/// ============================================================
/// Element Access
/// ============================================================

/// (8)
double stack_top(const Stack* stack)
{
    if (!stack) {
        return 0.0;
    }

    if (stack->size == 0) {
        ((Stack*)stack)->error = STACK_ERROR_EMPTY;
        return 0.0;
    }

    ((Stack*)stack)->error = STACK_SUCCESS;
    return stack->top->value;
}

/// ============================================================
/// Modification Operations
/// ============================================================

/// (5)
void stack_push(Stack* stack, double value)
{
    if (!stack) {
        return;
    }

    StackNode* node = malloc(sizeof(StackNode));
    if (!node) {
        stack->error = STACK_ERROR_ALLOC;
        return;
    }

    node->value = value;
    node->next = stack->top;

    stack->top = node;
    stack->size++;
    stack->error = STACK_SUCCESS;
}

/// (9)
double stack_pop(Stack* stack)
{
    if (!stack) {
        return 0.0;
    }

    if (stack->size == 0) {
        stack->error = STACK_ERROR_EMPTY;
        return 0.0;
    }

    StackNode* node = stack->top;
    double value = node->value;

    stack->top = node->next;
    free(node);

    stack->size--;
    stack->error = STACK_SUCCESS;

    return value;
}

void stack_clear(Stack* stack)
{
    if (!stack) {
        return;
    }

    while (stack->top) {
        StackNode* node = stack->top;
        stack->top = node->next;
        free(node);
    }

    stack->size = 0;
    stack->error = STACK_SUCCESS;
}
