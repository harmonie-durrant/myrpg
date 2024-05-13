/*
** EPITECH PROJECT, 2023
** my_fputfloat
** File description:
** my_fputfloat
*/

#include "my.h"

int my_fputfloat(int fd, float nb, int precision)
{
    int total = 0;

    if (nb < 0) {
        my_fputchar(fd, '-');
        nb *= -1;
        total++;
    }
    total += my_fputnbr(fd, (int)nb);
    total += my_fputchar(fd, '.');
    nb -= (int)nb;
    for (int i = 0; i < precision; i++) {
        nb *= 10;
        total += my_fputchar(fd, (int)nb + '0');
        nb -= (int)nb;
    }
    return total;
}
