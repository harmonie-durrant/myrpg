/*
** EPITECH PROJECT, 2023
** my_fprintf
** File description:
** my_fprintf
*/

#ifndef MY_FPRINTF_H_
    #define MY_FPRINTF_H_
    #include <stdarg.h>

    typedef struct fprintf_flag_s {
        char name;
        int (*ptr)(int fd, va_list list);
    }fprintf_flag_t;

int fprintf_b_flag(int fd, va_list list);
int fprintf_c_flag(int fd, va_list list);
int fprintf_perc_flag(int fd, va_list list);
int fprintf_u_flag(int fd, va_list list);
int fprintf_capx_flag(int fd, va_list list);
int fprintf_di_flag(int fd, va_list list);
int fprintf_f_flag(int fd, va_list list);
int fprintf_o_flag(int fd, va_list list);
int fprintf_s_flag(int fd, va_list list);
int fprintf_x_flag(int fd, va_list list);
int fprintf_p_flag(int fd, va_list list);

#endif /* !MY_FPRINTF_H_ */
