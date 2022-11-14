#include "main.h"

/**
 * ntostring - Calls upon unsignedntostring to turn a number into a string.
 * @args: Number to be transformed, negative or positive.
 * @base: Also transforms to base from base ten.
 * @buffer: Holds the data temporarily.
 * @indicator: Tells function to return upper or lower case.
 * Return: 0.
 */

int ntostring(va_list args, int base, char *buffer, int indicator)
{
	long int number = va_arg(args, int);
	int negative = 0;

	if (number < 0)
	{
		*buffer++ = '-';
		number = -number;
		negative = 1;
	}
	else if (number == 0)
	{
		putchar('0');
		return (1);
	}
	PosNtoString(number, base, buffer, indicator);
	if (negative)
		return (_printf("%s", buffer - 1)); /* this is pretty cool*/
	else
		return (_printf("%s", buffer));

}
