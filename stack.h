#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>   // for size_t

/// ============================================================
/// Stack Abstract Data Type (ADT)
/// Elements: double-precision floating point values
/// ============================================================

/// Description:
///		Opaque stack type
///		The internal structure is hidden from users of the API
 
typedef struct Stack Stack;

/// ============================================================
/// Creation / Destruction
/// ============================================================

/// Description:
///		Create a new empty stack. (4)
///
/// Preconditions:
///		None
///
/// Postconditions:
///		Returns a pointer to a newly created empty stack.
///
/// Time Complexity:
///		O(1)
///
/// Space Complexity:
///		O(1)
///
/// Returns:
///		Pointer to a Stack object, or NULL on allocation failure.

Stack* stack_create(void);

/// Descriptions:
///		Remove a stack and reclaim all associated memory. (11)
///
/// Preconditions:
///		stack != NULL
///		stack is empty
///
/// Postconditions:
///		All memory associated with the stack is reclaimed.
///
/// Time Complexity:
///		O(1)

id stack_destroy(Stack* stack);

/// ============================================================
/// Capacity / State
/// ============================================================
///
/// Description:
///		Return the number of elements in the stack. (6)
///
/// Preconditions:
///		stack != NULL
///
/// Time Complexity:
///		O(1)

size_t stack_size(const Stack* stack);

/// Descirpion:
///		Determine whether the stack is empty. (7)
/// 
/// Preconditions:
///		stack != NULL
/// 
/// Returns:
///		true if and only if the stack contains no elements
/// 
/// Time Complexity:
///		O(1)

bool stack_is_empty(const Stack* stack);

/// ============================================================
/// Element Access
/// ============================================================

/// Description:
///		Examine the top element of the stack without removing it. (8)
///
/// Preconditions:
///		stack != NULL
///		stack is not empty
///
/// Postconditions:
///		Stack remains unchanged
///
/// Time Complexity:
///		O(1)
///
/// Returns:
///		The value at the top of the stack

double stack_top(const Stack* stack);

/// ============================================================
/// Modification Operations
/// ============================================================

/// Description:
///		Push a value onto the top of the stack. (5)
///
/// Preconditions:
///		stack != NULL
///
/// Postconditions:
///		Stack size increases by one
///		value becomes the new top element
///
/// Time Complexity:
///		O(1)
///
/// Space Complexity:
///		O(N)

void stack_push(Stack* stack, double value);

/// Description:
///		Remove and return the top element of the stack. (9)
///
/// Preconditions:
///		stack != NULL
///		stack is not empty
///
/// Postconditions:
///		Stack size decreases by one
///
/// Time Complexity:
///		O(1)
///
/// Returns:
///		The value that was removed from the top of the stack
///
/// Error:
///		Behavior is undefined if stack is empty

double stack_pop(Stack* stack);

/// Description:
///		Remove all elements from the stack without examining them. (10)
/// 
/// Preconditions:
///		stack != NULL
/// 
/// Postconditions:
///		Stack becomes empty
/// 
/// Time Complexity:
///		O(N)
/// 
/// Space Complexity:
///		O(1) after completion

void stack_clear(Stack* stack);

#endif STACK_H
