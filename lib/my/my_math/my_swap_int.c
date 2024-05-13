/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** Write a function
*/

void my_swap_int(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}
