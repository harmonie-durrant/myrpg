/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** characters conversion flags
*/

#include <stdarg.h>
#include "my.h"

int fprintf_c_flag(int fd, va_list list)
{
    return my_fputchar(fd, va_arg(list, int));
}

int fprintf_s_flag(int fd, va_list list)
{
    return my_fputstr(fd, va_arg(list, char*));
}

int fprintf_perc_flag(int fd, va_list list)
{
    UNUSED(list);
    return my_fputchar(fd, '%');
}
