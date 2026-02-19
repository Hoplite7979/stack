#include "test/test_stack.h"

#include <stdio.h>

int main(void)
{
    if (run_stack_tests() == 0) {
        printf("All stack tests passed.\n");
        return 0;
    }

    printf("Stack tests failed.\n");
    return 1;
}