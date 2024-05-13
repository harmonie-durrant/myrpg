/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** number_parsing
*/

#include <stdlib.h>
#include "my.h"

static int find_end(const char *str, int start, int is_float)
{
    int i = start;


    while (str[i] != '\0') {
        if (!(IS_NUM(str[i]) || (is_float && str[i] == '.'))) {
            break;
        }
        i++;
    }
    return i - 1;
}

static int find_start(const char *str)
{
    int i = 0;

    i = my_str_find(str, ':', 0);
    if (i == -1) {
        return -1;
    }
    for (; str[i] != '\0'; i++) {
        if (IS_NUM(str[i]) || str[i] == '-') {
            break;
        }
    }
    return i;
}

int parse_int(const char *str)
{
    int nbr = 0;
    char *nbr_str = NULL;
    int start = 0;
    int end = 0;

    if ((start = find_start(str)) == -1) {
        return -1;
    }
    if ((end = find_end(str, start, 0)) == -1) {
        return -1;
    }
    if ((nbr_str = my_str_extract(str, start, end + 1)) == NULL) {
        return -1;
    }
    nbr = my_atoi(nbr_str);
    free(nbr_str);
    return nbr;
}

float parse_float(const char *str)
{
    float nbr = 0;
    char *nbr_str = NULL;
    int start = 0;
    int end = 0;

    if ((start = find_start(str)) == -1) {
        return -1;
    }
    if ((end = find_end(str, start, 1)) == -1) {
        return -1;
    }
    if ((nbr_str = my_str_extract(str, start, end + 1)) == NULL) {
        return -1;
    }
    nbr = my_atof(nbr_str);
    free(nbr_str);
    return nbr;
}
