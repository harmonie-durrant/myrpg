/*
** EPITECH PROJECT, 2023
** template_project
** File description:
** returns 1 if the in_str contains the str sequence of characters
*/

#include <stdlib.h>
#include "my.h"

static int scan_str(const char *str, const char *in_str, int i)
{
    int j = 0;
    while (in_str[i] != '\0' && str[j] == in_str[i]) {
        i++;
        j++;
    }
    if (str[j] == '\0') {
        return 1;
    }
    return 0;
}

static char *get_lowcase_str(const char *str)
{
    char *str_dup = NULL;

    str_dup = my_strdup(str);
    if (!str_dup) {
        return NULL;
    }
    my_str_lowcase(str_dup);
    return str_dup;
}

static int abort_dup(char *target_str, char *search_str)
{
    free(target_str);
    free(search_str);
    return -1;
}

static int handle_case(char **target, char **search, char *str, char *in)
{
    *target = get_lowcase_str(str);
    *search = get_lowcase_str(in);
    if (!*target || !*search) {
        return abort_dup(*target, *search);
    }
    return 0;
}

int my_str_in(char *str, char *in_str, int case_insensitive)
{
    char *curr_str = str;
    char *curr_in = in_str;

    if (case_insensitive) {
        if (handle_case(&curr_str, &curr_in, str, in_str) == -1) {
            return -1;
        }
    }
    for (int i = 0; curr_in[i] != '\0'; i++) {
        if (curr_in[i] == curr_str[0]
        && scan_str(curr_str, curr_in, i) == 1) {
            return 1;
        }
    }
    if (case_insensitive) {
        free(curr_str);
        free(curr_in);
    }
    return 0;
}
