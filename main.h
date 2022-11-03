#ifndef _PRINTF_
#define _PRINTF_
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char ch;
	int (*f)()
} type_ch;

int _printf(const char *format, ...);

int _putchar(char c);

#endif
