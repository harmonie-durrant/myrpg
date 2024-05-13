/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** write a function
*/

#include "my.h"

int my_str_isalpha(char const* str)
{
    int is_alpha = 1;
    int lower_case = 0;
    int upper_case = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        upper_case = my_is_between(str[i], 64, 91, 0);
        lower_case = my_is_between(str[i], 96, 123, 0);
        if (!lower_case && !upper_case)
            is_alpha = 0;
    }

    return is_alpha;
}
