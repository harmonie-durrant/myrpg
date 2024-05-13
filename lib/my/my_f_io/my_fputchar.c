/*
** EPITECH PROJECT, 2023
** my_fputchar
** File description:
** my_fputchar
*/

#include <unistd.h>

int my_fputchar(int fd, char c)
{
    return write(fd, &c, 1);
}
