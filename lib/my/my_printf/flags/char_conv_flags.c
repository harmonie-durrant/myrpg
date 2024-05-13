/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** characters conversion flags
*/

#include <stdarg.h>
#include "my.h"

void printf_c_flag(va_list list)
{
    my_putchar(va_arg(list, int));
}

void printf_s_flag(va_list list)
{
    my_putstr(va_arg(list, char*));
}

void printf_perc_flag(va_list list)
{
    UNUSED(list);
    my_putchar('%');
}
