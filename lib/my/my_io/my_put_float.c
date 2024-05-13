/*
** EPITECH PROJECT, 2022
** my put float
** File description:
** prints a float with the last 3 digits
*/

#include <stdio.h>
#include "my.h"

static void precision_pos(double nbr, int j, int whole)
{
    int decimal = (int)((nbr - whole) * my_compute_power_rec(10, j + 1));
    int temp = decimal;

    if (temp > 9) {
        while (temp > 9)
            temp -= 10;
    }
    if (temp >= 5) {
        decimal /= 10;
        decimal += 1;
    } else
        decimal /= 10;
    my_put_nbr(decimal);
}

static int my_put_float_pos(double nbr, int whole, int j, int decimal)
{
    int temp = decimal;

    my_put_nbr(whole);
    my_putchar('.');
    while (temp < my_compute_power_rec(10, j - 1)) {
        temp *= 10;
        if (temp == 0)
            temp += 9;
        my_putchar('0');
    }
    if (decimal > 9) {
        while (decimal % 10 == 0)
            decimal /= 10;
    }
    precision_pos(nbr, j, whole);
    return 0;
}

static void precision_neg(double nbr, int j, int whole)
{
    int decimal = (int)((nbr - whole) * my_compute_power_rec(10, j + 1));
    int temp = decimal;

    decimal *= -1;
    temp *= -1;
    if (temp > 9) {
        while (temp > 9)
            temp -= 10;
    }
    if (temp >= 5) {
        decimal /= 10;
        decimal += 1;
    } else
        decimal /= 10;
    my_put_nbr(decimal);
}

static int my_put_float_neg(double nbr, int whole, int j, int decimal)
{
    int temp = -1 * (decimal + 1);

    my_put_nbr(whole);
    my_putchar('.');
    while (temp < my_compute_power_rec(10, j - 1)) {
        temp *= 10;
        if (temp == 0)
            temp += 9;
        my_putchar('0');
    }
    decimal = decimal * (-1);
    if (decimal < -9) {
        while (decimal % 10 == 0)
            decimal /= 10;
    }
    precision_neg(nbr, j, whole);
    return 0;
}

void my_put_float(double nbr)
{
    int j = 6;
    int whole = (int)nbr;
    int decimal = (int)((nbr - whole) * my_compute_power_rec(10, j));
    int temp = decimal;

    if (nbr <= 0 && temp > 0.0000000001) {
        if (nbr < 0 && temp > -1)
            my_putchar('-');
        my_putstr("0.");
        for (;j > 0; j--)
            my_putchar('0');
        return;
    } if (nbr > -1) {
        my_putchar('-');
        nbr *= -1;
    } if (nbr < 0)
        my_put_float_neg(nbr, whole, j, decimal);
    else
        my_put_float_pos(nbr, whole, j , decimal);
}
