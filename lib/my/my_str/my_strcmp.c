/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** write a function
*/

#include "my.h"

int my_strcmp(char const* s1, char const* s2)
{
    int i = 0;
    int size1 = my_strlen(s1);
    int size2 = my_strlen(s2);

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    if (s1[i] != s2[i] || size1 != size2)
        return size1 > size2 ? 1 : -1;
    return 0;
}
