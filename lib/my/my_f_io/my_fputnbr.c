/*
** EPITECH PROJECT, 2023
** my_fputnbr
** File description:
** my_fputnbr
*/

#include "my.h"

int my_fputnbr(int fd, int nb)
{
    int total = 0;

    if (nb < 0) {
        my_fputchar(fd, '-');
        nb *= -1;
        total++;
    }
    if (nb >= 10) {
        total += my_fputnbr(fd, nb / 10);
        total += my_fputnbr(fd, nb % 10);
    } else {
        total += my_fputchar(fd, nb + '0');
    }
    return total;
}
