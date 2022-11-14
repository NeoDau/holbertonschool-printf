#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @args: The character to print
 * @b: unused
 * @s: unused
 * @ind: unused
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(va_list args, int b, char *s, int ind)
{
	char c = va_arg(args, int);
	int trash = b = ind = 0;

	s[trash] = 0;
	putchar(c);
	return (1 + trash);
}
