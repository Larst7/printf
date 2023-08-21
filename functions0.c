#include "main.h"

/*Print character*/

/**
* print_char - function that prints a character
* @buffer: A buffer for array for handling the print
* @flags:  calculates active flags
* @types: list of arguments
* @precision: specifies the precision
* @width: width of array
* @size: specifies the size
* handle_write_char: return type
* Return: number of characters printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);

return (handle_write_char(c, buffer, flags, width, precision, size));
}
/*Print String*/
/**
* print_string - a function that prints a string
* @types: list a of arguments
* @buffer: A buffer for array for handling the print
* @flags:  calculates active flags
* @width: get width
* @precision: specifies the precision
* @size: specifies the size
* Return: number of characters printed
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int len = 0, j;
char *strng = va_arg(types, char *);

UNUSED(width);
UNUSED(precision);
UNUSED(buffer);
UNUSED(flags);
UNUSED(size);

if (strng == NULL)
{
strng = "(null)";
if (precision >= 6)
strng = "      ";
}

while (strng[len] != '\0')
len++;

if (precision >= 0 && precision < len)
len = precision;

if (width > len)
{
if (flags & F_MINUS)
{
write(1, &strng[0], len);
for (j = width - len; j > 0; j--)
write(1, " ", 1);
return (width);
}
else
{
for (j = width - len; j > 0; j--)
write(1, " ", 1);
write(1, &strng[0], len);
return (width);
}
}
return (write(1, strng, len));
}

/*Print percentage symbol*/
/**
* print_percent - function that prints percent sign or symbol
* @types: list a of arguments
* @buffer: A buffer for array for handling the print
* @flags:  calculates active flags
* @width: width
* @precision: the precision
* @size: the size
* Return: number of characters printed
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(width);
UNUSED(precision);
UNUSED(buffer);
UNUSED(flags);
UNUSED(size);
return (write(1, "%%", 1));
}

/*Print integers**/
/**
* print_int - function that print integers
* @types: list a of arguments
* @buffer: A buffer for array for handling the print
* @flags:  calculates active flags
* @width: get width
* @precision: specifies the precision
* @size: specifies the size
* write_number: ...
* Return: number of characters printed
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int j = BUFF_SIZE - 2;
int is_negative = 0;
long int a = va_arg(types, long int);
unsigned long int numb;

a = convert_size_number(a, size);

if (a == 0)
buffer[j--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
numb = (unsigned long int)a;

if (a < 0)
{
numb = (unsigned long int)((-1) * a);
is_negative = 1;
}

while (numb > 0)
{
buffer[j--] = (numb % 10) + '0';
numb /= 10;
}

j++;

return (write_number(is_negative, j, buffer, flags, width, precision, size));
}

/*Binary Printing*/
/**
* print_binary - function that prints an unsigned number
* @types: list a of arguments
* @buffer: A buffer for array for handling the print
* @flags:  calculates active flags
* @width: width
* @precision: precision
* @size: size
* Return: number of characters printed
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int b, c, x, sum;
unsigned int n[32];
int count;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

b = va_arg(types, unsigned int);
c = 2147483648; /* (2 ^ 31) */
n[0] = b / c;
for (x = 1; x < 32; x++)
{
c /= 2;
n[x] = (b / c) % 2;
}
for (x = 0, sum = 0, count = 0; x < 32; x++)
{
sum += n[x];
if (sum || x == 31)
{
char z = '0' + n[x];

write(1, &z, 1);
count++;
}
}
return (count);
}
