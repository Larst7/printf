#include "main.h"
#include <stdarg.h>

/*Printing unsigned numbers */
/**
 * print_unsigned - function that prints an unsigned number
 * @buffer: A buffer for array for handling the print
 * @flags:  calculates active flags
 * @types: list of arguments
 * @precision: specifies the precision
 * @width: width of array
 * @size: specifies the size
 * Return: number of characters printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[j--] = (numb % 10) + '0';
		numb /= 10;
	}

	j++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/*Print unsigned number in octal (base 8)*/
/**
 * print_octal - function that prints an unsigned
 * number in octal notation (base 8)
 * @buffer: A buffer for array for handling the print
 * @flags:  calculates active flags
 * @types: list of arguments
 * @precision: specifies the precision
 * @width: width of array
 * @size: specifies the size
 * Return: number of characters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[j--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && init_numb != 0)
		buffer[j--] = '0';

	x++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/* Print unsigned number in lower hexadecimal-base 10 */
/**
 * print_hexadecimal - function that prints an unsigned
 * number in hexadecimal notation- base 10
 * @buffer: A buffer for array for handling the print
 * @flags:  calculates active flags
 * @types: list of arguments
 * @precision: specifies the precision
 * @width: width of array
 * @size: specifies the size
 * Return: number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* Print an unsigned number in Upper hexadecimal-base 10 */
/**
 * print_hexa_upper - function that prints an unsigned
 * number in upper hexadecimal notation-base 10
 * @buffer: A buffer for array for handling the print
 * @flags:  calculates active flags
 * @types: list of arguments
 * @precision: specifies the precision
 * @width: width of array
 * @size: specifies the size
 * Return: number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* Print a hexadecimal number in upper or lower */
/**
 * print_hexa - function that prints a hexadecimal number in lower or upper
 * @types: list of arguments
 * @set_to: Array of values to map the number to
 * @buffer: A buffer for array for handling the print
 * @flags:  calculates active flags
 * @flag_ch: Calculates active flags
 * @width: width of array
 * @precision: specifies the precision
 * @size: specifies the size
 * @size: Size specification
 * Return: number of characters printe
 */
int print_hexa(va_list types, char set_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[j--] = set_to[numb % 16];
		numb /= 16;
	}

	if (flags & F_HASH && init_numb != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
