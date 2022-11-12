/**
 * PosNtoString - Turns a number into a string
 * @number: Number to be turned
 * @base: Base number is going to be expresssed in
 * @buffer: Buffer number is stored into
 * @indicator: Prints uppercase for 1 lower for 2
 * Return: Returns lenght of printed characters
 */
int PosNtoString(unsigned long int number,
int base, char *buffer, int indicator)
{
	int digit, j, i, lenreturn;
	char buf[65];

	j = digit = lenreturn = i = 0;
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
	*buffer = j = 0;
	return (0);
}
