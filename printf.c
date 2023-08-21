#include "main.h"

void output_buffer(char buffer[], int *buffer_index);

/**
 * my_printf - Custom printf function
 * @format: format string
 * Return: Number of characters printed
 */
int my_printf(const char *format, ...)
{
	int i, total_printed = 0, char_count = 0;
	int format_flags, format_width,
	    format_precision, format_size, buffer_index = 0;
	va_list args;
	char output_buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			output_buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				output_buffer(output_buffer, &buffer_index);
			/* write(1, &format[i], 1);*/
			char_count++;
		}
		else
		{
			output_buffer(output_buffer, &buffer_index);
			format_flags = get_format_flags(format, &i);
			format_width = get_format_width(format, &i, args);
			format_precision = get_format_precision(format, &i, args);
			format_size = get_format_size(format, &i);
			++i; __format
			int printed_count = handle_format(format, &i, args, output_buffer,
				format_flags, format_width,
				format_precision, format_size);
			if (printed_count == -1)
				return (-1);
			char_count += printed_count; i
		}
	}

	output_buffer(output_buffer, &buffer_index);

	va_end(args);

	return (char_count);
}

/**
 * output_buffer - Outputs the contents of the buffer if it's not empty
 * @buffer: Character buffer
 * @buffer_index: Index at which to add the next character
 */
void output_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
