/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** number base conversion flags
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int fprintf_b_flag(int fd, va_list list)
{
    return my_fputbase(fd, va_arg(list, int), 2, 0);
}

int fprintf_x_flag(int fd, va_list list)
{
    return my_fputbase(fd, va_arg(list, int), 16, 0);
}

int fprintf_o_flag(int fd, va_list list)
{
    return my_fputbase(fd, va_arg(list, int), 8, 0);
}

int fprintf_capx_flag(int fd, va_list list)
{
    return my_fputbase(fd, va_arg(list, int), 16, 1);
}

int fprintf_p_flag(int fd, va_list list)
{
    int total = 0;
    int nbr = 0;
    int ptr = 0;

    nbr = va_arg(list, int);
    ptr = (unsigned int)nbr;
    total += my_fputstr(fd, "0x");
    total += my_fputbase(fd, ptr, 16, 0);
    return total;
}
