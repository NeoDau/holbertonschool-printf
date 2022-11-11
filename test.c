#include <stdio.h>

int unsigned_ntostring(unsigned long int number, int base, char *buffer, int indicator)
{
  int digit;
  int j = 0;
  int i, lenreturn = 0;
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
	{
		if (indicator == 1)
		  buf[j++] = 'a' + (digit - 10);
		if (indicator == 2)
		  buf[j++] = 'A' + (digit - 10);
	}
      else
	buf[j++] = '0' + digit;
      number /= base;
    }
  for (i = j - 1; i != 0; i--)
    *buffer++ = buf[i];
  *buffer++ = buf[0];
  *buffer = 0;
  j = 0;
     for (i = 0; buf[i]; i++)
       j++;
     for (i = j; i >= 0; i--)
       {
	 putchar(buf[i]);
	 lenreturn++;
       }
     return (lenreturn);
}
int main()
{
  char buf[32];
  int len;
 int i = 123456789;
 len = unsigned_ntostring(i, 16, buf, 2);
 printf("\n%d\n", len);

}
