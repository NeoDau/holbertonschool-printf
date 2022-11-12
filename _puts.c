#include "main.h"
#include <unistd.h>

/**
 * _puts - Prints a string to the stdout
 * @string: String to be printed
 * Return: Returns number of prints
 */

int _puts(char *string)
{
	int i;

	if (!(string))
		return (-1);
	for (i = 0; string[i]; i++)
		;
	write(1, string, i);
	return (i);
}

