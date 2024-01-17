#include "monty.h"

/**
 * f_queue - Sets the queue mode (FIFO).
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void f_queue(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    bus.lifi = 1;
}

/**
 * addqueue - Adds a node to the tail of the stack.
 * @stack: Pointer to the stack head.
 * @new_value: New value to be inserted.
 *
 * Return: No return value.
 */
void addqueue(stack_t **stack, int new_value)
{
    stack_t *new_node, *aux;

    aux = *stack;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
    }
    new_node->n = new_value;
    new_node->next = NULL;
    if (aux)
    {
        while (aux->next)
            aux = aux->next;
    }
    if (!aux)
    {
        *stack = new_node;
        new_node->prev = NULL;
    }
    else
    {
        aux->next = new_node;
        new_node->prev = aux;
    }
}
