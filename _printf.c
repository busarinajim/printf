#include "main.h"
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr = format;

	va_start(args, format);

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*ptr == 's')
			{
				char *str = va_arg(args, char *);
				while (*str != '\0')
				{
					write(1, str, 1);
					str++;
					count++;
				}
			}
			else if (*ptr == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		else
		{
			write(1, ptr, 1);
			count++;
		}
		ptr++;
	}

	va_end(args);

	return count;
}

