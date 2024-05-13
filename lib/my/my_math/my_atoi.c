/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** Write a function
*/

#include "my.h"

int my_atoi(char const *str)
{
    int nbr = 0;
    int neg = 1;
    int i = 0;
    int size = 0;

    size = my_strlen(str);
    if (str[0] == '-') {
        i++;
        neg = -1;
    }
    for (; i < size; i++) {
        nbr += (str[i] - '0') * my_compute_power_rec(10, size - i - 1);
    }
    return nbr * neg;
}
