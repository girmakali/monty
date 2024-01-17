#include "monty.h"

/**
 * execute - Executes the opcode.
 * @content: Line content.
 * @stack: Pointer to the stack head.
 * @line_number: Line counter.
 * @file: Pointer to the Monty file.
 *
 * Return: 0 on success, 1 if unknown instruction.
 */
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
    instruction_t opst[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
    };
    unsigned int i = 0;
    char *opcode;

    opcode = strtok(content, " \n\t");
    if (opcode && opcode[0] == '#')
        return (0);
    bus.arg = strtok(NULL, " \n\t");
    while (opst[i].opcode && opcode)
    {
        if (strcmp(opcode, opst[i].opcode) == 0)
        {
            opst[i].f(stack, line_number);
            return (0);
        }
        i++;
    }
    if (opcode && opst[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    return (1);
}
