#include <stdio.h>

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: starting integer
 *
 * Description: Prints numbers separated by a comma and space,
 * ending with 98 and a newline.
 */
void print_to_98(int n)
{
	if (n <= 98)
	{
		while (n <= 98)
		{
			printf("%d", n);
			if (n != 98)
				printf(", ");
			n++;
		}
	}
	else
	{
		while (n >= 98)
		{
			printf("%d", n);
			if (n != 98)
				printf(", ");
			n--;
		}
	}
	printf("\n");
}
