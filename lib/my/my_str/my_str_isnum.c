/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** write a function
*/

#include "my.h"

int my_str_isnum(char const* str)
{
    int is_num = 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_is_between(str[i], 47, 58, 0))
            is_num = 0;

    return is_num;
}
