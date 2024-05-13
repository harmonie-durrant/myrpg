/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_str_has_prefix
*/

#include "my.h"

int my_str_has_prefix(const char *str, char *prefix)
{
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (prefix[i] == '\0') {
            return 1;
        }
        if (str[i] != prefix[i]) {
            break;
        }
    }
    if (prefix[i] == '\0') {
        return 1;
    }
    return 0;
}
