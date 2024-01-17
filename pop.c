#include "monty.h"

/**
 * f_pop - Removes the top element of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *top;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: Error: can't pop an empty stack\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    *stack = top->next;
    free(top);
}
