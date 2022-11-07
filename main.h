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
int FromDeci(unsigned long n, int base);
void lowercaseDeciFunc(long int n, int base);

////////////////////////////////////////////////////////////////////////////////
int _strlen(char *s)
{
  int i;
  for (i = 0; s[i]; i++)
    ;
  return (i - 1);
}
////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////
int _printf(const char *format, ...)
{
  int strlen;
  int escapeSequences = 0;
  int escapeSeqArray[] = {'d', 'i', 'c', 's', '%', 'u'};
  int arrayIterator;
  va_list args;
  int VaArg_len = 0;
  va_start(args, format);
  VaArg_len = _prontf(format, args);
  va_end(args);
  for (strlen = 0; format[strlen]; strlen++)
    if (format[strlen] == '%')
      {
	for (arrayIterator = 0; escapeSeqArray[arrayIterator]; arrayIterator++)
	  if (format[strlen + 1] == escapeSeqArray[arrayIterator])
	    {
	      strlen++;
	      escapeSequences += 1;
	    }
      }
  return (strlen - escapeSequences + VaArg_len);
}
//////////////////////////////////////////////////////////////////////////////////
int FromDeci(unsigned long n, int base)
{
  long decimalnum, quotient, remainder;
  int i, j = 0;
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
    putchar(hexadecimalnum[i]);
}
////////////////////////////////////////////////////////////////////////////////////
void lowercaseDeciFunc(long n, int base)
{
  long decimalnum, quotient, remainder;
  int i, j = 0;
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
      putchar(hexadecimalnum[i] + 32);
    else
      putchar(hexadecimalnum[i]);
}
////////////////////////////////////////////////////////////////////////////////////////
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
		VaArg_len = _strlen(StringFormatReplacement);
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
		break;
	      }
	    case '%':
	      putchar('%');
	      break;
	    case 'd':
	      {
		int DecimalFormatReplacement = va_arg(args, int);
		print(DecimalFormatReplacement);
		break;
	      }
	    case 'i':
	      {
		int IntegerFormatReplacement = va_arg(args, int);
		print(IntegerFormatReplacement);
		break;
	      }
	    case 'u':
	      {
		unsigned int UnsignedIntReplacement = va_arg(args, unsigned int);
		print(UnsignedIntReplacement);
		break;
	      }
	    case 'x':
	      {
		long long HexFormatReplacement = va_arg(args, unsigned int);
		lowercaseDeciFunc(HexFormatReplacement, 16);
		break;
	      }
	    case 'X':
	      {
		long long HexFormatBigboy = va_arg(args, unsigned int);
		FromDeci(HexFormatBigboy, 16);
		break;
	      }
	    case 'o':
	      {
		long long OctalFormatReplacement = va_arg(args, unsigned int);
		FromDeci(OctalFormatReplacement, 8);
		break;
	      }
	    case 'p':
	      {
		void *PointerFormatReplacement = va_arg(args, void *);
		putchar('0');
		putchar('x');
		lowercaseDeciFunc((unsigned long) PointerFormatReplacement, 16);
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
//////////////////////////////////////////////////////////////////////////////////////////////
#endif
