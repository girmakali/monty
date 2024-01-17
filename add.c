#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void f_add(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    int len = 0, sum;

    current = *stack;
    while (current)
    {
        current = current->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: Error: can't add, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    sum = current->n + current->next->n;
    current->next->n = sum;
    *stack = current->next;
    free(current);
}
