#include "monty.h"

/**
 * f_pchar - Prints the char at the top of the stack, followed by a new line.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    current = *stack;
    if (!current)
    {
        fprintf(stderr, "L%d: Error: can't pchar, stack empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    if (current->n > 127 || current->n < 0)
    {
        fprintf(stderr, "L%d: Error: can't pchar, value out of range\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", current->n);
}
