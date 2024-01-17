#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
    stack_t *top;
    int len = 0, aux;

    top = *stack;

    while (top)
    {
        top = top->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: Error: can't swap, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    aux = top->n;
    top->n = top->next->n;
    top->next->n = aux;
}
