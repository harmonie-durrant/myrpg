/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** return 1 if a number is prime, 0 otherwise
*/

int my_is_prime(int nb)
{
    int i = 2;

    while (i <= nb / 2) {
        if (nb % i != 0)
            i++;
        else
            return 0;
    }

    return 1;
}
