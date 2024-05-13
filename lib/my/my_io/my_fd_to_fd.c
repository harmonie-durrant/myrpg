/*
** EPITECH PROJECT, 2023
** template_project
** File description:
** write the content of a file descriptor into another
*/

#include <fcntl.h>
#include <unistd.h>

int my_fd_to_fd(int src, int dest)
{
    char c = 0;
    int total = 0;

    while (read(src, &c, 1) == 1) {
        write(dest, &c, 1);
        total++;
    }
    return total;
}
