#include "main.h"

/**
* print_line - prints a line
* @n: parameter to hold value
* Return: start
*/

void print_line(int n)
{
	int start = 0;

	while (start < n)
	{
		_putchar('_');
		start++;
	}
	_putchar('\n');
}
