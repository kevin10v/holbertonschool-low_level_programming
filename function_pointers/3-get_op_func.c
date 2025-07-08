#include "3-calc.h"
#include <stddef.h>

/**
 * get_op_func - selects the correct function to perform operation
 * @s: operator passed as argument
 * Return: pointer to the function or NULL
 */
int (*get_op_func(char *s))(int, int) {
op_t ops[] = {
{"+", op_add},
{"-", op_sub},
{"*", op_mul},
{"/", op_div},
{"%", op_mod},
{NULL, NULL}
};
int i = 0;

if (s == NULL || s[1] != '\0')
return (NULL);

while (ops[i].op != NULL && *(ops[i].op) != *s)
i++;

return (ops[i].op == NULL ? NULL : ops[i].f);
}
