#include "monty.h"

/**
 * f_sub - Subtracts the top element from the second top element of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    int result, node_count;

    current = *stack;
    for (node_count = 0; current != NULL; node_count++)
        current = current->next;

    if (node_count < 2)
    {
        fprintf(stderr, "L%d: Error: can't sub, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    result = current->next->n - current->n;
    current->next->n = result;
    *stack = current->next;
    free(current);
}
