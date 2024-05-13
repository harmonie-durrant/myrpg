/*
** EPITECH PROJECT, 2023
** my_fprintf
** File description:
** has the same behavior as the printf function but writes the output to fd
*/

#include <stdarg.h>
#include "my.h"
#include "my_fprintf.h"

static int handle_flags(int fd, const char* format, va_list list, int i)
{
    fprintf_flag_t flags[] = {
        {'b', fprintf_b_flag},  {'c', fprintf_c_flag},
        {'u', fprintf_u_flag}, {'f', fprintf_f_flag},
        {'d', fprintf_di_flag}, {'%', fprintf_perc_flag},
        {'i', fprintf_di_flag}, {'o', fprintf_o_flag},
        {'s', fprintf_s_flag},  {'x', fprintf_x_flag},
        {'F', fprintf_f_flag},  {'p', fprintf_p_flag},
        {'X', fprintf_capx_flag}
    };

    if (format[i] != '%') {
        return -1;
    }
    for (int c = 0; c < 17; c++) {
        if (format[i + 1] == flags[c].name) {
            return flags[c].ptr(fd, list);
        }
    }
    return -1;
}

void my_fprintf(int fd, const char* format, ...)
{
    va_list list;
    int total = 0;
    int tmp = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        tmp = handle_flags(fd, format, list, i);
        if (tmp != -1) {
            total += tmp;
            i++;
        } else {
            my_fputchar(fd, format[i]);
        }
    }
    va_end(list);
}
