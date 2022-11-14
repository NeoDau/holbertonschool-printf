#include "main.h"
#include <unistd.h>

/**
 * _puts - Prints a string to the stdout
 * @args: String to be printed
 * @b: unused
 * @buf: unused
 * @ind: unused
 * Return: Returns number of prints
 */

int _puts(va_list args, int b, char *buf, int ind)
{
	char *string = va_arg(args, char *);
	int trash = b = ind = 0;
	int i;

	for (i = 0; buf[i]; i++)
		buf[i] = 0;
	if (!(string))
		return (-1);
	for (i = 0; string[i]; i++)
		putchar(string[i]);
	return (i + trash);
}

