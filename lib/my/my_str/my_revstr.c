/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** Reverse a string
*/

#include <stdlib.h>
#include "my.h"

char* my_revstr(char *str)
{
    int size = my_strlen(str);
    char temp[size + 1];

    my_strcpy(temp, str);
    for (int i = 0; i < size; i++) {
        str[i] = temp[(size - 1) - i];
    }
    return str;
}
