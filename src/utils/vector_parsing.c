/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** vector_parsing
*/

#include <stdlib.h>
#include "window.h"
#include "my.h"
#include "rpg.h"

static int set_delim(char *str, int *delim)
{
    delim[0] = my_str_find(str, '{', 0) + 1;
    if (delim[0] == 0) {
        return -1;
    }
    delim[1] = my_str_find(str, ',', 0);
    if (delim[1] == -1) {
        return -1;
    }
    delim[2] = my_str_find(str, '}', 0);
    if (delim[2] == -1) {
        return -1;
    }
    return 0;
}

static int init_vector_parsing(const char *str, char **x_str, char **y_str)
{
    int delim[] = {0, 0, 0};
    char *c_str = NULL;

    if ((c_str = get_clean_str(str)) == NULL)
        return -1;
    if (set_delim(c_str, delim) == -1) {
        free(c_str);
        return -1;
    }
    if ((*x_str = my_str_extract(c_str, delim[0], delim[1])) == NULL) {
        free(c_str);
        return -1;
    }
    if ((*y_str = my_str_extract(c_str, delim[1] + 1, delim[2])) == NULL) {
        free(c_str);
        free(*x_str);
        return -1;
    }
    free(c_str);
    return 0;
}

v2i parse_v2i(const char *str)
{
    v2i vector = {0, 0};
    char *x_str = NULL;
    char *y_str = NULL;

    if (init_vector_parsing(str, &x_str, &y_str) == -1) {
        return ((v2i){-1, -1});
    }
    vector.x = my_atoi(x_str);
    vector.y = my_atoi(y_str);
    free(x_str);
    free(y_str);
    return vector;
}

v2f parse_v2f(const char *str)
{
    v2f vector = {0, 0};
    char *x_str = NULL;
    char *y_str = NULL;

    if (init_vector_parsing(str, &x_str, &y_str) == -1) {
        return ((v2f){-1, -1});
    }
    vector.x = my_atof(x_str);
    vector.y = my_atof(y_str);
    free(x_str);
    free(y_str);
    return vector;
}
