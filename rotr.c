#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the stack head.
 * @line_number: Line number (unused).
 *
 * Return: No return value.
 */
void f_rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *copy;

    copy = *stack;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        return;
    }
    while (copy->next)
    {
        copy = copy->next;
    }
    copy->next = *stack;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*stack)->prev = copy;
    (*stack) = copy;
}
