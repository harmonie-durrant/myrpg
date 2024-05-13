/*
** EPITECH PROJECT, 2023
** my_atof
** File description:
** my_atof
*/

#include <stdlib.h>
#include "my.h"

float my_atof(char *arr)
{
    char **split_arr = NULL;
    float f_nb = 0;
    float current_nb = 0;

    if (!C_IN_STR('.', arr))
        return (float)my_atoi(arr);
    split_arr = my_str_to_word_array(arr, '.');
    if (!split_arr)
        return 0;
    f_nb += my_atoi(split_arr[0]);
    for (int i = 0; split_arr[1][i] != '\0'; i++) {
        current_nb = (float)(split_arr[1][i] - '0');
        f_nb += (1.0 / (float)my_compute_power_rec(10, i + 1)) * current_nb;
    }
    for (int i = 0; split_arr[i]; i++) {
        free(split_arr[i]);
    }
    free(split_arr);
    return f_nb;
}
