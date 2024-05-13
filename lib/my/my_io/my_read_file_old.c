/*
** EPITECH PROJECT, 2022
** my_read_file
** File description:
** reads and returns the content of a file
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

char* my_read_file_old(const char* pathname)
{
    char* str = malloc(sizeof(char));
    char* temp = malloc(sizeof(char));
    int fd = open(pathname, O_RDONLY);
    int size = 1;

    read(fd, str, size);
    close(fd);
    while (my_strcmp(str, temp) != 0) {
        fd = open(pathname, O_RDONLY);
        size++;
        temp = my_realloc_str(temp, size);
        my_strcpy(temp, str);
        str = my_realloc_str(str, size);
        read(fd, str, size);
        close(fd);
    }
    free(temp);
    close(fd);
    return str;
}
