#ifndef PRINTF_HEADER
#define PRINTF_HEADER
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

int _strlen(char *s);
int print(long int n);
int _prontf(const char *format, va_list args);
int _printf(const char *format, ...);
int FromDeci(unsigned long int n, int base);
int lowercaseDeciFunc(long int n, int base);
void unsigned_ntostring(unsigned long int number, int base, char *buffer);
void ntotring(long long int number, int base, char *buffer);
void uppercase_ntostring(unsigned long int number, int base, char *buffer);
/*****************************************************************************/
/**
 * uppercase_ntostring - Like unsigned ntostring but returns uppercase chars.
 * @number: Number to be transformed, only positives.
 * @base: Transforms from base ten to base base
 * @buffer: Holds the data momentarily.
 */

void uppercase_ntostring(unsigned long int number, int base, char *buffer)
{
int digit;
int cur = 0;
int i;
char buf[65];
	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
	}
	for (i = 0; i < 65; i++)
		buf[i] = 0;
	while (number)
	{
		digit = number % base;
		if (digit >= 10)
			buf[cur++] = 'A' + (digit - 10);
		else
			buf[cur++] = '0' + digit;
		number /= base;
	}
	for (i = cur - 1; i != 0; i--)
		*buffer++ = buf[i];
	*buffer++ = buf[0];
	*buffer = 0;
}
/*****************************************************************************/
/**
 * ntostring - Calls upon unsignedntostring to turn a number into a string.
 * @number: Number to be transformed, negative or positive.
 * @base: Also transforms to base from base ten.
 * @buffer: Holds the data temporarily.
 */

void ntostring(long long int number, int base, char *buffer)
{
	if (number < 0)
	{
		*buffer++ = '-';
		number = -number;
	}
	unsigned_ntostring(number, base, buffer);
}
/*****************************************************************************/
/**
 * unsigned_ntostring - Transforms a number into a string.
 * @number: Number to be transformed, positive due to ntostrings transofmration
 * @base: Transforms to (base 10) from base.
 * @buffer: Holds data temporarily
 */

void unsigned_ntostring(unsigned long int number, int base, char *buffer)
{
int digit;
int cur = 0;
int i;
char buf[65];

	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
	}
	for (i = 0; i < 65; i++)
		buf[i] = 0;
	while (number)
	{
		digit = number % base;
		if (digit >= 10)
			buf[cur++] = 'a' + (digit - 10);
		else
			buf[cur++] = '0' + digit;
		number /= base;
	}
	for (i = cur - 1; i != 0; i--)
		*buffer++ = buf[i];
*buffer++ = buf[0];
*buffer = 0;
}
/*****************************************************************************/
/**
 * _strlen - Function that measures the lenght of a string.
 * @s: String to be measured.
 * Return: Returns the lenght of the string to the function.
 */

int _strlen(char *s)
{
int i;
	for (i = 0; s[i]; i++)
	;
return (i);
}
/****************************************************************************/
/**
 * print - prints a number using recursion, scraped for better functions.
 * @n: Number to be printed.
 * Return: No return.
 */
int print(long int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
		print(n / 10);
	putchar(n % 10 + '0');
}
/*****************************************************************************/
/**
 * _printf - Formatted printing function.
 * @format: String with possible format instructions.
 * Return: Returns the lenght of the printed output.
 */

int _printf(const char *format, ...)
{
int strlen = 0;
int escapeSequences = 0;
int escapeSeqArray[] = {'d', 'i', 'c', 's', '%', 'u', 'x', 'X', 'p', 'o'};
int arrayIterator;
va_list args;
int VaArg_len = 0;

	va_start(args, format);
	VaArg_len += _prontf(format, args);
	va_end(args);
	for (strlen = 0; format[strlen]; strlen++)
		if (format[strlen] == '%')
		{
			for (arrayIterator = 0; escapeSeqArray[arrayIterator]; arrayIterator++)
				if (format[strlen + 1] == escapeSeqArray[arrayIterator])
				{
					escapeSequences++;
					strlen++;
					break;
				}
		}
	printf("%d\n%d\n%d\n", VaArg_len, strlen, escapeSequences);
	return (strlen - (escapeSequences * 2) + VaArg_len);
}
/*****************************************************************************/
/**
 * FromDeci - Scrapped due to instability and bad output.
 * @n: Number to be printed.
 * @base: Base to be transform number into.
 * Return: Returns the amount of characters printed.
 */

int FromDeci(unsigned long n, int base)
{
unsigned long decimalnum, quotient, remainder;
int i, j = 0;
char hexadecimalnum[100];
int strlen = 0;

decimalnum = n;
quotient = decimalnum;
	while (quotient != 0)
	{
		remainder = quotient % base;
		if (remainder <= 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 55 + remainder;
		quotient = quotient / base;
	}
	for (i = j; i >= 0; i--)
	{
		putchar(hexadecimalnum[i]);
		strlen++;
	}
	return (strlen);
}
/*****************************************************************************/
/**
 * lowercaseDeciFunc - Prints a number from base ten to base but in lowercase.
 * @n: Number to be transformed and printed.
 * @base: Base to transfrom number into.
 * Return: Returns amount of characters printed.
 */

int lowercaseDeciFunc(long n, int base)
{
long decimalnum, quotient, remainder;
int i, j = 0;
int strlen = 0;
char hexadecimalnum[100];
decimalnum = n;
quotient = decimalnum;
	while (quotient != 0)
	{
		remainder = quotient % base;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 55 + remainder;
		quotient = quotient / base;
	}
	for (i = j; i >= 0; i--)
		if (hexadecimalnum[i] > 'A' && hexadecimalnum[i] < 'Z')
		{
			putchar(hexadecimalnum[i] + 32);
			strlen++;
		}
		else
		{
			putchar(hexadecimalnum[i]);
			strlen++;
		}
	return (strlen);
}
/*****************************************************************************/
/**
 * _prontf - Prints argument in the _printf function.
 * @format: Instruction on how to process argument.
 * @args: Argument to be printed instead of the format.
 * Return: Returns the lenght of the argument printed.
 */

int _prontf(const char *format, va_list args)
{
int ctr = 0;
int foundPercent = 0;
int VaArg_len = 0;
int iterate = 0;

	while (format[ctr])
	{
		if (!(foundPercent))
		{
			if (format[ctr] == '%')
			{
				foundPercent = 1;
			}
			else
			{
				putchar(format[ctr]);
			}
		}
		else if (foundPercent)
		{
			switch (format[ctr])
			{
			case 's':
			{
			char *StringFormatReplacement = va_arg(args, char *);

			VaArg_len += _strlen(StringFormatReplacement);
			while (StringFormatReplacement[iterate])
			{
				putchar(StringFormatReplacement[iterate]);
				iterate++;
			}
			break;
			}
			case 'c':
			{
			char CharFormatReplacement = va_arg(args, int);

			putchar(CharFormatReplacement);
			VaArg_len++;
			break;
			}
			case '%':
			{
			VaArg_len++;
			putchar('%');
			break;
			}
			case 'd':
			{
			int DecimalFormatReplacement = va_arg(args, int);
			char buf[32];
			int i;

			ntostring(DecimalFormatReplacement, 10, buf);
			for (i = 0; buf[i]; i++)
			{
				VaArg_len++;
				putchar(buf[i]);
			}
			break;
			}
			case 'i':
			{
			int IntegerFormatReplacement = va_arg(args, int);
			char buf[32];
			int i;

			ntostring(IntegerFormatReplacement, 10, buf);
			for (i = 0; buf[i]; i++)
			{
				VaArg_len++;
				putchar(buf[i]);
			}
			break;
			}
			case 'u':
			{
			unsigned int UnsignedIntReplacement = va_arg(args, unsigned int);
			char buf[32];
			int i;

			ntostring(UnsignedIntReplacement, 10, buf);
			for (i = 0; buf[i]; i++)
			{
				putchar(buf[i]);
				VaArg_len++;
			}
			break;
			}
			case 'x':
			{
			long long HexFormatReplacement = va_arg(args, unsigned int);
			char buf[25];
			int i;

			ntostring(HexFormatReplacement, 16, buf);
			for (i = 0; buf[i]; i++)
			{
				putchar(buf[i]);
				VaArg_len++;
			}
			break;
			}
			case 'X':
			{
			long long HexFormatBigboy = va_arg(args, unsigned int);
			char buf[25];
			int i;

			uppercase_ntostring(HexFormatBigboy, 16, buf);
			for (i = 0; buf[i]; i++)
			{
				putchar(buf[i]);
				VaArg_len++;
			}
			break;
			}
			case 'o':
			{
			long OctalFormatReplacement = va_arg(args, unsigned int);
			char buf[32];
			int i;

			ntostring(OctalFormatReplacement, 8, buf);
			for (i = 0; buf[i]; i++)
			{
				putchar(buf[i]);
				VaArg_len++;
			}
			break;
			}
			case 'p':
			{
			putchar('0');
			putchar('x');
			VaArg_len += 2;
			void *PointerFormatReplacement = va_arg(args, void *);
			char buf[32];
			int i;

			ntostring((unsigned long int)PointerFormatReplacement, 16, buf);
			for (i = 0; buf[i]; i++)
			{
			VaArg_len++;
			putchar(buf[i]);
			}
			break;
			}
			default:
			{
				putchar(format[ctr - 1]);
				putchar(format[ctr]);
				break;
			}
			}
			foundPercent = 0;
		}
		ctr++;
	}
	return (VaArg_len);
}
#endif
