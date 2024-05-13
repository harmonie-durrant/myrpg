/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_
    #include <stdarg.h>

    typedef struct printf_flag_s {
        char name;
        void (*ptr)(va_list list);
    }printf_flag_t;

void printf_b_flag(va_list list);
void printf_c_flag(va_list list);
void printf_perc_flag(va_list list);
void printf_u_flag(va_list list);
void printf_capx_flag(va_list list);
void printf_di_flag(va_list list);
void printf_f_flag(va_list list);
void printf_o_flag(va_list list);
void printf_s_flag(va_list list);
void printf_x_flag(va_list list);
void printf_p_flag(va_list list);

#endif /* !MY_PRINTF_H_ */
