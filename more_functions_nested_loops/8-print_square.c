#include "main.h"

/**
* print_square - prints square
* @c: parameter to hold value
* Return: start
*/

int _putchar(char c);
void print_square(int size)
{
int i;
int j;

if (size < 1)
{	_putchar('\n'); }
else
{
	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size; i++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
}
