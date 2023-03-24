#include <stdio.h>
#include "variadic_functions.h"

/**
  * print_strings - ...
  * @separator: ...
  * @n: ...
  *
  * Return: ...
  */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	char *str;
	unsigned int i;

	if (n > 0)
	{
		va_start(args, n);

		for (i = 0; i < n; i++)
		{
			str = va_arg(args, char *);
			if (str == NULL)
				printf("%s", "(nil)");
			else
				printf("%s", str);

			if (i != n - 1 && separator != NULL)
				printf("%s", separator);
		}

		va_end(args);
	}

	printf("\n");
}
/**
 * print_float - Print float
 * @args: float
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_all - any given type of argument
 * @format: types of arguments being passed
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *sep;
	print_form_t print_form[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string}
	};
	int i, j;

	va_start(args, format);
	i = 0;
	sep = "";
	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (*print_form[j].c == format[i])
			{
				printf("%s", sep);
				print_form[j].f(args, sep);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
