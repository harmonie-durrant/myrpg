/*
** EPITECH PROJECT, 2023
** template_project
** File description:
** my_str_replace
*/

#include <stdlib.h>

char *my_str_replace(char *str, char *replace_str, int start, int finish)
{
    char *left = NULL;
    char *right = NULL;
    char *tmp = NULL;
    char *new_str = NULL;

    if (finish < 0)
        finish = my_strlen(str) + finish + 1;
    if (start > finish)
        return NULL;
    left = my_str_extract(str, 0, start);
    right = my_str_extract(str, finish, -1);
    tmp = my_strcat_new(left, replace_str, "");
    new_str = my_strcat_new(tmp, right, "");
    free(left);
    free(right);
    free(tmp);
    return new_str;
}
