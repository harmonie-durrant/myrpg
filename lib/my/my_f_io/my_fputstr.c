/*
** EPITECH PROJECT, 2023
** my_fputstr
** File description:
** my_fputstr
*/

#include <unistd.h>
#include "my.h"

int my_fputstr(int fd, char *str)
{
    int size = my_strlen(str);

    if (size > 0) {
        return write(fd, str, size);
    }
    return 0;
}
