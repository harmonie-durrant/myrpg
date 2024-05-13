/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** str_tools
*/

#include <stdlib.h>
#include "my.h"

static int pop_str(char *str, int pos)
{
    int size = 0;

    size = my_strlen(str);
    if (size <= 1 || pos >= size) {
        return -1;
    }
    for (int i = pos; str[i] != '\0'; i++) {
        str[i] = str[i + 1];
    }
    str[size - 1] = '\0';
    return 0;
}

char *get_clean_str(const char *str)
{
    char target_char[] = " \t";
    char *clean_str = NULL;

    if ((clean_str = my_strdup(str)) == NULL) {
        return NULL;
    }
    for (int i = 0; clean_str[i] != '\0'; i++) {
        if (C_IN_STR(clean_str[i], target_char)) {
            pop_str(clean_str, i);
        }
    }
    return clean_str;
}

static int set_delim(const char *str, int *delim)
{
    if ((delim[0] = my_str_find(str, ':', 0)) == -1) {
        return -1;
    }
    delim[0]++;
    while (C_IN_STR(str[delim[0]], " \t")) {
        delim[0]++;
    }
    for (delim[1] = delim[0]; str[delim[1]] != '\0'; delim[1]++) {
        if (C_IN_STR(str[delim[1]], "\t\n")) {
            return 0;
        }
    }
    return 0;
}

char *parse_str(const char *str)
{
    int delim[2] = {0, 0};

    if (set_delim(str, delim) == -1) {
        return NULL;
    }
    return my_str_extract(str, delim[0], delim[1]);
}

char **parse_str_2d(char *tmp, char sep)
{
    char *parsed_str = NULL;
    char **output = NULL;

    parsed_str = parse_str(tmp);
    output = my_str_to_word_array(parsed_str, sep);
    free(parsed_str);
    return output;
}
