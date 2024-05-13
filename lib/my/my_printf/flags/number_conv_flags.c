/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** number conversion flags
*/

#include <stdarg.h>
#include "my.h"

void printf_di_flag(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

void printf_f_flag(va_list list)
{
    my_put_float(va_arg(list, double));
}

void printf_u_flag(va_list list)
{
    my_put_nbr_unsigned(va_arg(list, int));
}
