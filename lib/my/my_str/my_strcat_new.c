/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_strcat_new
*/

#include "stdlib.h"
#include "my.h"

char *my_strcat_new(const char *src, const char *dest, char *separator)
{
    char *str = NULL;
    int size = 0;
    int i = 0, itt = 0;
    int has_sep = separator != NULL;

    size = my_strlen(src) + my_strlen(dest) + 1;
    if (has_sep)
        size += my_strlen(separator);
    str = malloc(sizeof(char) * size);
    if (!str)
        return NULL;
    for (; src[i] != 0; i++)
        str[i] = src[i];
    if (has_sep)
        for (; separator[itt] != '\0'; itt++, i++)
            str[i] = separator[itt];
    for (itt = 0; dest[itt] != '\0'; itt++, i++)
        str[i] = dest[itt];
    str[i] = '\0';
    return str;
}
