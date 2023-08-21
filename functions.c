#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_custom_char - Prints a character
 * @args: List of arguments
 * @output_buffer: Buffer for output
 * @format_flags: Active format flags
 * @field_width: Field width
 * @precision_val: Precision value
 * @size_modifier: Size modifier
 * Return: Number of characters printed
 */
int print_custom_char(va_list args, char output_buffer[],
	int format_flags, int field_width, int precision_val, int size_modifier)
{
	char c = va_arg(args, int);

	return (write_char_to_buffer(c, output_buffer, format_flags,
				field_width, precision_val, size_modifier));
}
/************************* PRINT A STRING *************************/
/**
 * print_custom_string - Prints a string
 * @args: List of arguments
 * @output_buffer: Buffer for output
 * @format_flags: Active format flags
 * @field_width: Field width
 * @precision_val: Precision value
 * @size_modifier: Size modifier
 * Return: Number of characters printed
 */
int print_custom_string(va_list args, char output_buffer[],
	int format_flags, int field_width, int precision_val, int size_modifier)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision_val);
	UNUSED(size_modifier);

	if (str == NULL)
	{
		str = "(null)";
		if (precision_val >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision_val >= 0 && precision_val < length)
		length = precisio_val;

	if (field_width > length)
	{
		if (format_flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = field_width - length; i > 0; i--)
				write(1, " ", 1);
			return (field_width);
		}
		else
		{
			for (i = field_width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (field_width);
		}
	}
	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_custom_percent - Prints a percent sign
 * @args: List of arguments
 * @output_buffer: Buffer for output
 * @format_flags: Active format flags
 * @field_width: Field width
 * @precision_val: Precision value
 * @size_modifier: Size modifier
 * Return: Number of characters printed
 */
int print_custom_percent(va_list args, char output_buffer[],
	int format_flags, int field_width, int precision_val, int size_modifier)
{
	UNUSED(args);
	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision_val);
	UNUSED(size_modifier);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_custom_int - Print an integer
 * @args: List of arguments
 * @output_buffer: Buffer for output
 * @format_flags: Active format flags
 * @field_width: Field width
 * @precision_val: Precision value
 * @size_modifier: Size modifier
 * Return: Number of characters printed
 */
int print_custom_int(va_list args, char output_buffer[],
	int format_flags, int field_width, int precision_val, int size_modifier)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_size_number(n, size_modifier);

	if (n == 0)
		output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		output_buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number_to_buffer(is_negative, i, output_buffer, format_flags,
				field_width, precision_val, size_modifier));
}

/************************* PRINT BINARY *************************/
/**
 * print_custom_binary - Prints an unsigned binary number
 * @args: List of arguments
 * @output_buffer: Buffer for output
 * @format_flags: Active format flags
 * @field_width: Field width
 * @precision_val: Precision value
 * @size_modifier: Size modifier
 * Return: Number of characters printed
 */
int print_custom_binary(va_list args, char output_buffer[],
	int format_flags, int field_width, int precision_val, int size_modifier)
{
	unsigned int n, m, i, sum;
	unsigned int binary_digits[32];
	int count;

	UNUSED(output_buffer);
	UNUSED(format_flags); i
	UNUSED(field_width);
	UNUSED(precision_val);
	UNUSED(size_modifier);

	n = va_arg(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	binary_digits[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += binary_digits[i];
		if (sum || i == 31)
		{
			char binary_digits = '0' + binary_digits[i];

			write(1, &binary_char, 1);
			count++;
		}
	}
	return (count);
}
