#include "main.h"
#include <stdarg.h>
#include <stddef.h>

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - printf function
 * @format: format specification
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int j, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, args);
			precision = get_precision(format, &j, args);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - function that prints contents of the buffer
 * @buffer: Array of characters
 * @buff_ind: the length of index at which to add the next character
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
