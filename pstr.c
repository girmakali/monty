#include "monty.h"

/**
 * f_pstr - Prints the string starting at the top of the stack, followed by a new line.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void f_pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    (void)line_number;

    current = *stack;
    while (current)
    {
        if (current->n > 127 || current->n <= 0)
        {
            break;
        }
        printf("%c", current->n);
        current = current->next;
    }
    printf("\n");
}
