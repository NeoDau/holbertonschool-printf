#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct formatFunctions - contains the formats
 * @specifier: format specifier
 * @f: pointer to formatting functions
 */
typedef struct formatFunctions
{
	char specifier;
	int (*f)(va_list args, int base, char *buffer, int indicator);
} formatFunctions;

int _printf(const char *format, ...);
int (*formatFunc(char c))(va_list, int base, char *buf, int ind);
int PosNtoString(long int number, int base, char *buffer, int indicator);
int ntostring(va_list args, int base, char *buffer, int indicator);
int _puts(va_list args, int base, char *buffer, int indicator);
int _putchar(va_list args, int base, char *buffer, int indicator);
int printPercentage(va_list __attribute__ ((unused)), int, char *, int);

#endif
