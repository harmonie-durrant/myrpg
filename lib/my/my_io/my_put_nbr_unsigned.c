/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** write a function
*/

#include "my.h"

int my_put_nbr_unsigned(unsigned int nbr)
{
    int total = 0;

    if (nbr <= 9) {
        my_putchar(48 + nbr);
        total++;
    }
    if (nbr >= 10) {
        total += my_put_nbr(nbr / 10);
        my_putchar(nbr % 10 + 48);
        total++;
    }
    return total;
}
