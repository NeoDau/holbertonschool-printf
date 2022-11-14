#include "main.h"
#include <stdarg.h>
/**
 * formatFunc - Recieves a formats and turns out the function
 * @z: char used to get the func
 * Return: returns the function
 */

int (*formatFunc(char z))(va_list, int base, char *buf, int ind)
{
	int i;
	formatFunctions FuncArray[] = {
				       {'c', _putchar},
				       {'s', _puts},
				       {'i', ntostring},
				       {'d', ntostring},
				       {'%', printPercentage},
				       {'\0', NULL}
	};
	for (i = 0; FuncArray[i].specifier; i++)
		if (z == FuncArray[i].specifier)
			return (FuncArray[i].f);
	return (NULL);
}
