#include "monty.h"

/**
 * addnode - Adds a node to the head of the stack.
 * @stack: Pointer to the head of the stack.
 * @new_value: New value to be inserted.
 *
 * Return: No return value.
 */
void addnode(stack_t **stack, int new_value)
{
    stack_t *new_node, *aux;

    aux = *stack;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        exit(0);
    }
    if (aux)
        aux->prev = new_node;
    new_node->n = new_value;
    new_node->next = *stack;
    new_node->prev = NULL;
    *stack = new_node;
}
