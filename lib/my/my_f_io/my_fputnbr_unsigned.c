/*
** EPITECH PROJECT, 2023
** my_fputnbr_unsigned
** File description:
** my_fputnbr_unsigned
*/

#include "my.h"

int my_fputnbr_unsigned(int fd, unsigned int nbr)
{
    int total = 0;

    if (nbr <= 9) {
        my_fputchar(fd, 48 + nbr);
        total++;
    }
    if (nbr >= 10) {
        total += my_fputnbr(fd, nbr / 10);
        my_fputchar(fd, nbr % 10 + 48);
        total++;
    }
    return total;
}
