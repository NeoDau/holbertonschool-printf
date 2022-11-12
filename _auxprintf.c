#include "main.h"
int _prontf(const char *format, va_list args)
{
  int ctr = 0, i = 0, foundPercent = 0, len = 0;
  char buf[32];
  while (format[ctr])
    {
      if (!(foundPercent))
	{
	  if (format[ctr] == '%')
	    {
	      foundPercent = 1;
	    }
	  else
	     len += _putchar(format[ctr]);
	}
      else if (foundPercent)
	{
	  switch (format[ctr])
	    {
	    case 's':
	      {
		char *StringFormatReplacement = va_arg(args, char *);

		len += _puts(StringFormatReplacement);
		break;
	      }
	    case 'c':
	      {
		char CharFormatReplacement = va_arg(args, int);

		len += _putchar(CharFormatReplacement);
		break;
	      }
	    case '%':
		len += _putchar('%');
		break;
	    case 'd':
	      {
		int DecimalFormatReplacement = va_arg(args, int);

		ntostring(DecimalFormatReplacement, 10, buf, 2);
		len += _puts(buf);
		break;
	      }
	    case 'i':
	      {
		int IntegerFormatReplacement = va_arg(args, int);

		ntostring(IntegerFormatReplacement, 10, buf, 2);
		len += _puts(buf);
		break;
	      }
	    case 'u':
	      {
		unsigned int UnsignedIntReplacement = va_arg(args, unsigned int);

		ntostring(UnsignedIntReplacement, 10, buf, 2);
		len += _puts(buf);
		break;
	      }
	    case 'x':
	      {
		long HexFormatReplacement = va_arg(args, unsigned int);

		ntostring(HexFormatReplacement, 16, buf, 2);
		len += _puts(buf);
		break;
	      }
	    case 'X':
	      {
		long HexFormatBigboy = va_arg(args, unsigned int);

		ntostring(HexFormatBigboy, 16, buf, 1);
		len += _puts(buf);
		break;
	      }
	    case 'o':
	      {
		long OctalFormatReplacement = va_arg(args, unsigned int);

		ntostring(OctalFormatReplacement, 8, buf, 2);
		len += _puts(buf);
		break;
	      }
	    case 'p':
	      {
		void *PointerFormatReplacement = va_arg(args, void *);

		_putchar('0');
		_putchar('x');
		ntostring((unsigned long int)PointerFormatReplacement, 16, buf, 2);
		len += 2 + _puts(buf);
		break;
	      }
	    default:
	      {
		_putchar(format[ctr - 1]);
		_putchar(format[ctr]);
		break;
	      }
	    }
	  foundPercent = 0;
	}
      ctr++;
    }
  return (len);
}
