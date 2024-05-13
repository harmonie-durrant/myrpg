/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** return the square root integer of a number
*/

int my_compute_square_root(int nb)
{
    int i = 0;
    while (i * i < nb + 1) {i++;}

    return i - 1;
}
