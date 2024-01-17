#include "monty.h"

/**
 * f_div - Divides the top two elements of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void f_div(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    int len = 0, quotient;

    current = *stack;
    while (current)
    {
        current = current->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: Error: can't divide, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: Error: division by zero\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    quotient = current->next->n / current->n;
    current->next->n = quotient;
    *stack = current->next;
    free(current);
}
