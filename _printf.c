#include "main.h"
/**
 * _printf - formatted printing to stdout
 * @format: string to be printed
 * Return: returns the lenght of the printed string
 */

int _printf(const char *format, ...)
{
	int escapeSeqArray[] = {'d', 'i', 'c', 's', '%', '\0'};
	int foundPercent = 0, foundF = 0, len = 0, i = 0, j = 0,
	base = 0, indicator = 0;
	char buf[32];
	va_list args;
	int (*_fprintf)(va_list args, int, char *, int);

	if (!format)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (!foundPercent)
		{
			if (format[i] == '%')
			{
				foundPercent = 1;
			}
			else
			{
				putchar(format[i]);
				len++;
			}
		}
		else if (foundPercent)
		{
			_fprintf = formatFunc(format[i]);
			if (!_fprintf)
				putchar(format[i - 1]), putchar(format[i]), len += 2;
			else
			{
				base = 10, indicator = 2;
				len += _fprintf(args, base, buf, indicator);
			}
			foundPercent = 0;
		}

	}
	va_end(args);
	return (len);
}
