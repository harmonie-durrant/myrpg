/*
** EPITECH PROJECT, 2022
** my_realloc_str
** File description:
** realloc a char array with a new size
*/

#include <stdlib.h>
#include "my.h"

char* my_realloc_str(char* str, int size)
{
    char* temp = malloc(sizeof(char) * size);
    my_strcpy(temp, str);
    free(str);
    return temp;
}
