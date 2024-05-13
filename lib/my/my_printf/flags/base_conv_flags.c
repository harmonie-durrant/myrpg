/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** number base conversion flags
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

void printf_b_flag(va_list list)
{
    my_putbase(va_arg(list, int), 2, 0);
}

void printf_x_flag(va_list list)
{
    my_putbase(va_arg(list, int), 16, 0);
}

void printf_o_flag(va_list list)
{
    my_putbase(va_arg(list, int), 8, 0);
}

void printf_capx_flag(va_list list)
{
    my_putbase(va_arg(list, int), 16, 1);
}

void printf_p_flag(va_list list)
{
    int nbr = va_arg(list, int);
    int ptr = (unsigned int)nbr;
    my_putstr("0x");
    my_putbase(ptr, 16, 0);
}
