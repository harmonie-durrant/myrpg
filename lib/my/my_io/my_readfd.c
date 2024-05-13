/*
** EPITECH PROJECT, 2023
** my_readfd
** File description:
** my_readfd
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *my_readfd(int fd, int size)
{
    char *buf = NULL;

    if (size <= 0)
        size = BUFSIZ;
    buf = malloc(sizeof(char) * size);
    if (!buf)
        return NULL;
    size = read(fd, buf, size);
    if (size == -1) {
        free(buf);
        return NULL;
    }
    buf[size] = '\0';
    return buf;
}
