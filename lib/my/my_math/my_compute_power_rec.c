/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** Write a function
*/

int my_compute_power_rec(int nb, int power)
{
    int total = nb;
    int i = 0;

    if (power == 0)
        return 1;
    power--;
    while (i < power) {
        total *= nb;
        i++;
    }
    return total;
}
