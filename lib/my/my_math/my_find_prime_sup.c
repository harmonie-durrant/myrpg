/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** Write a function
*/

#include <stdio.h>
#include "my.h"

int my_find_prime_sup(int nb)
{
    nb++;

    while (!my_is_prime(nb))
        nb++;
    return nb;
}
