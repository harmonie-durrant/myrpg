/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** 2d_array_tools
*/

#include <stdlib.h>

void free_2d_array(char **arr)
{
    if (!arr)
        return;
    for (size_t i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr);
}

int count_2d_array(char **arr)
{
    int size = 0;

    while (arr[size]) {
        size++;
    }
    return size;
}
