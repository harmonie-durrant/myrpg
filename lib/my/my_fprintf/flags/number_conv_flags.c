/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** number conversion flags
*/

#include <stdarg.h>
#include "my.h"

int fprintf_di_flag(int fd, va_list list)
{
    return my_fputnbr(fd, va_arg(list, int));
}

int fprintf_f_flag(int fd, va_list list)
{
    return my_fputfloat(fd, va_arg(list, double), 6);
}

int fprintf_u_flag(int fd, va_list list)
{
    return my_fputnbr_unsigned(fd, va_arg(list, int));
}
