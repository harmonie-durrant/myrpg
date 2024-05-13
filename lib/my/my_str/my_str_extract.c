/*
** EPITECH PROJECT, 2023
** my_str_extract
** File description:
** create a new string with the characters within the given delimiters
*/

#include <stdlib.h>
#include "my.h"

char *my_str_extract(const char *str, int start, int finish)
{
    char *extracted = NULL;
    int i = 0;
    int size = 0;

    if (finish < 0)
        finish = my_strlen(str) + finish + 1;
    size = finish - start + 1;
    extracted = malloc(sizeof(char) * size + 1);
    if (!extracted)
        return NULL;
    while (str[start] != '\0' && start < finish) {
        extracted[i] = str[start];
        start++;
        i++;
    }
    extracted[i] = '\0';
    return extracted;
}
