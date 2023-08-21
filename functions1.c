#include "main.h"

int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size) {
    // Implementation of print_unsigned function
    // ...

    return 0;  // Return the number of characters printed
}

int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size) {
    // Implementation of print_octal function
    // ...

    return 0;  // Return the number of characters printed
}

int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size) {
    return print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size);
}

int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size) {
    return print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size);
}

int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size) {
    // Implementation of print_hexa function
    // ...

    return 0;  // Return the number of characters printed
}
