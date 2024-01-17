#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @stack: Pointer to the head of the stack.
 *
 * Return: No return value.
 */
void free_stack(stack_t *stack)
{
    stack_t *current;

    current = stack;
    while (stack)
    {
        current = stack->next;
        free(stack);
        stack = current;
    }
}
