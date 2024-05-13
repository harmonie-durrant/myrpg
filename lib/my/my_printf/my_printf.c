/*
** EPITECH PROJECT, 2022
** mini printf
** File description:
** title
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static int handle_flags(const char* format, va_list list, int i)
{
    printf_flag_t flags[] = {
        {'b', printf_b_flag},  {'c', printf_c_flag},
        {'u', printf_u_flag}, {'f', printf_f_flag},
        {'d', printf_di_flag}, {'%', printf_perc_flag},
        {'i', printf_di_flag}, {'o', printf_o_flag},
        {'s', printf_s_flag},  {'x', printf_x_flag},
        {'F', printf_f_flag},  {'p', printf_p_flag},
        {'X', printf_capx_flag}
    };

    for (int c = 0; c < 17; c++) {
        if (format[i + 1] == flags[c].name) {
            flags[c].ptr(list);
            return 1;
        }
    }
    return 0;
}

void my_printf(const char* format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && handle_flags(format, list, i))
            i++;
        else
            my_putchar(format[i]);
    }
    va_end(list);
}
