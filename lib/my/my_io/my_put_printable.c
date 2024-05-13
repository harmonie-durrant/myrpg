/*
** EPITECH PROJECT, 2022
** my put printable
** File description:
** Prints ascii char between 32 and 127.
** Else, prints a backslash with the octal value of the char
*/

#include "my.h"

int my_put_printable(char* str)
{
    int total = 0;

    for (int c = 0; str[c] != '\0'; c++) {
        if (str[c] < 32) {
            my_putchar('\\');
            total += my_putbase((int)str[c], 8, 0) + 1;
            continue;
        }
        my_putchar(str[c]);
        total++;
    }
    return total;
}
