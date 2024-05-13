/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** dublicate a string and return the dublicated string adress
*/

#include <stdlib.h>
#include "my.h"

char* my_strdup(const char* str)
{
    int size = my_strlen(str);
    char* dup = malloc(sizeof(char) * (size + 1));
    int i = 0;

    for (; i < size; i++) {
        dup[i] = str[i];
    }

    dup[size] = '\0';
    return dup;
}
