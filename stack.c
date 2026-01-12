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
};

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

    return stack;
}

/// (11)
void stack_destroy(Stack* stack)
{
    assert(stack != NULL);
    assert(stack->size == 0);  // Must be empty per spec

    free(stack);
}

/// ============================================================
/// Capacity / State
/// ============================================================

/// (6)
size_t stack_size(const Stack* stack)
{
    assert(stack != NULL);
    return stack->size;
}

/// (7)
bool stack_is_empty(const Stack* stack)
{
    assert(stack != NULL);
    return stack->size == 0;
}

/// ============================================================
/// Element Access
/// ============================================================

/// (8)
double stack_top(const Stack* stack)
{
    assert(stack != NULL);
    assert(stack->size > 0);

    return stack->top->value;
}

/// ============================================================
/// Modification Operations
/// ============================================================

/// (5)
void stack_push(Stack* stack, double value)
{
    assert(stack != NULL);

    StackNode* node = malloc(sizeof(StackNode));
    assert(node != NULL);

    node->value = value;
    node->next = stack->top;

    stack->top = node;
    stack->size++;
}

/// (9)
double stack_pop(Stack* stack)
{
    assert(stack != NULL);
    assert(stack->size > 0);

    StackNode* node = stack->top;
    double value = node->value;

    stack->top = node->next;
    free(node);

    stack->size--;

    return value;
}

/// (10)
void stack_clear(Stack* stack)
{
    assert(stack != NULL);

    while (stack->top != NULL) {
        StackNode* node = stack->top;
        stack->top = node->next;
        free(node);
    }

    stack->size = 0;
}
