#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - checks if a string contains only digits
 * @s: the string to check
 * Return: 1 if all digits, 0 if not
 */
int is_number(char *s)
{
int i = 0;

if (s[0] == '\0')
return (0);

while (s[i])
{
if (!isdigit(s[i]))
return (0);
i++;
}
return (1);
}

/**
 * main - adds positive numbers
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 if success, 1 if error
 */
int main(int argc, char *argv[])
{
int i, sum = 0;

if (argc == 1)
{
printf("0\n");
return (0);
}

for (i = 1; i < argc; i++)
{
if (!is_number(argv[i]))
{
printf("Error\n");
return (1);
}
sum += atoi(argv[i]);
}

printf("%d\n", sum);
return (0);
}
