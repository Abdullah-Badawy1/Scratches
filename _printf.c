#include "main.h"

int _printf(const char *format, ...)
{
	int i;
	char *s;
	char c;

	if (format == NULL)
	{
		return (-1);
	}

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
		}
		else
		{
			i++;

			if (format[i] == '\0')
			{
				break;
			}

			if (format[i] == '%')
			{
				putchar('%');
			}
			else if (format[i] == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				while (*s)
				{
					putchar(*s);
					s++;
				}
			}
		}
	}

	va_end(args);

	return (i);
}
