/*
** EPITECH PROJECT, 2023
** my_is_between
** File description:
** returns 1 if val is between a and b
*/

int my_is_between(int val, int min, int max, int inclusive)
{
    if (inclusive)
        return val >= min && val <= max;
    return val > min && val < max;
}
