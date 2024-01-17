#include "monty.h"

/**
 * f_rotl - Rotates the stack to the top.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void f_rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *tmp = *stack, *aux;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        return;
    }

    aux = (*stack)->next;
    aux->prev = NULL;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = *stack;
    (*stack)->next = NULL;
    (*stack)->prev = tmp;
    (*stack) = aux;
}
