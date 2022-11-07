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
int FromDeci(long int n, int base);
int lowercaseDeciFunc(long int n, int base);
void unsigned_ntostring(long unsigned int number, int base, char *holder);
void ntotring(long long int number, int base, char *buffer);

////////////////////////////////////////////////////////////////////////////////////////////
void ntostring(long long int number, int base, char *buffer)
{
  if (number < 0)
    {
      *buffer++ = '-';
      number = -number;
    }
  unsigned_ntostring(number, base, buffer);
}
////////////////////////////////////////////////////////////////////////////////////////
void unsigned_ntostring(long unsigned int number, int base, char *buffer)
{
  if (number == 0) {
    *buffer++ = '0';
    *buffer = 0;
  }
  
  char buf[65];
  for (int i = 0; i < 65; i++)
    buf[i] = 0;
  
  int cur = 0;
  
  while (number) {
    int digit = number % base;
    if (digit >= 10) {
      buf[cur++] = 'a' + (digit - 10);
    } else {
      buf[cur++] = '0' + digit;
    }
    number /= base;
  }
  for (int i = cur - 1; i != 0; i--)
    *buffer++ = buf[i];
  *buffer++ = buf[0];
  *buffer = 0;
}
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
  int strlen = 0;
  int escapeSequences = 0;
  int escapeSeqArray[] = {'d', 'i', 'c', 's', '%', 'u', 'x', 'X', 'p'};
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
  return (strlen - (escapeSequences * 2) + VaArg_len);
}
//////////////////////////////////////////////////////////////////////////////////
int FromDeci(long n, int base)
{
  long decimalnum, quotient, remainder;
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
////////////////////////////////////////////////////////////////////////////////////
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
		VaArg_len = 1;
		break;
	      }
	    case '%':
	      {
		VaArg_len = 1;
		putchar('%');
		break;
	      }
	    case 'd':
	      {
		int DecimalFormatReplacement = va_arg(args, int);
		char buf[32];
		ntostring(DecimalFormatReplacement, 10, buf);
		for (int i = 0; buf[i]; i++)
		  putchar(buf[i]);
		break;
	      }
	    case 'i':
	      {
		int IntegerFormatReplacement = va_arg(args, int);
		char buf[32];
		ntostring(IntegerFormatReplacement, 10, buf);
		for (int i = 0; buf[i]; i++)
		  putchar(buf[i]);
		break;
	      }
	    case 'u':
	      {
		unsigned int UnsignedIntReplacement = va_arg(args, unsigned int);
		char buf[32];
		ntostring(UnsignedIntReplacement, 10, buf);
		for (int i = 0; buf[i]; i++)
		  putchar(buf[i]);
		break;
	      }
	    case 'x':
	      {
		long long HexFormatReplacement = va_arg(args, unsigned int);
		char buf[25];
		ntostring(HexFormatReplacement, 16, buf);
		for (int i = 0; buf[i]; i++)
		  putchar(buf[i]);
		break;
	      }
	    case 'X':
	      {
		long long HexFormatBigboy = va_arg(args, unsigned int);
		VaArg_len = FromDeci(HexFormatBigboy, 16);
		break;
	      }
	    case 'o':
	      {
		long OctalFormatReplacement = va_arg(args, unsigned int);
		char buf[32];
		ntostring(OctalFormatReplacement, 8, buf);
		for (int i = 0; buf[i]; i++)
		  putchar(buf[i]);
		break;
	      }
	    case 'p':
	      {
		putchar('0');
		putchar('x');
		void *PointerFormatReplacement = va_arg(args, void *);
		char buf[32];
		ntostring((long unsigned int)PointerFormatReplacement, 16, buf);
		for (int i = 0; buf[i]; i++)
		  putchar(buf[i]);
		break;
	      }
	    default:
	      {
		putchar(format[ctr - 1]);
		putchar(format[ctr]);
		VaArg_len += 2;
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
