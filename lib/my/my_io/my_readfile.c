/*
** EPITECH PROJECT, 2022
** my_readfile
** File description:
** reads all bytes of a file
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

char *my_readfile(const char *filepath)
{
    struct stat statbuf;
    int fd = 0;
    char *str = NULL;

    stat(filepath, &statbuf);
    fd = open(filepath, O_RDONLY);
    str = malloc(sizeof(char) * (statbuf.st_size + 1));

    if (fd == -1 || str == NULL)
        return NULL;

    read(fd, str, statbuf.st_size);
    str[statbuf.st_size] = '\0';
    close(fd);
    return str;
}
