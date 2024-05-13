/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** Write a function
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int size = 0;
    int printed = 0;

    size = my_strlen(str);
    printed = write(1, str, size);
    return printed;
}
