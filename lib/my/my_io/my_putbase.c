/*
** EPITECH PROJECT, 2022
** my_putbase
** File description:
** display a decimal number in specified base
*/

#include "my.h"

int my_putbase(int nbr, int base, int upcase)
{
    char *base_string = upcase ? "0123456789ABCDEF" : "0123456789abcdef";
    int nbr2 = nbr;
    int total = 0;

    if (nbr2 < 0) {
            nbr2 *= (-1);
            my_putchar('-');
            total++;
        }
    if ((int)nbr2 / base) {
        total += my_putbase((int)nbr2 / base, base, upcase);
    }
    my_putchar(base_string[nbr2 % base]);
    return total;
}
