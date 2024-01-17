#include "monty.h"

/**
 * f_push - Adds a node to the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void f_push(stack_t **stack, unsigned int line_number)
{
    int value, i = 0, flag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            i++;
        for (; bus.arg[i] != '\0'; i++)
        {
            if (bus.arg[i] > 57 || bus.arg[i] < 48)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: Error: usage: push integer\n", line_number);
            fclose(bus.file);
            free(bus.content);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: Error: usage: push integer\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    value = atoi(bus.arg);
    if (bus.lifi == 0)
        addnode(stack, value);
    else
        addqueue(stack, value);
}
