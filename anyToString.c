#include "main.h"

/**
 * ntostring - Calls upon unsignedntostring to turn a number into a string.
 * @number: Number to be transformed, negative or positive.
 * @base: Also transforms to base from base ten.
 * @buffer: Holds the data temporarily.
 * @indicator: Tells function to return upper or lower case.
 * Return: 0.
 */

int ntostring(long long int number, int base, char *buffer, int indicator)
{
	if (number < 0)
	{
		*buffer++ = '-';
		number = -number;
	}
	PosNtoString(number, base, buffer, indicator);
	return (0);
}
