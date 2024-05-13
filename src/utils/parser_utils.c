/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parser_utils
*/

#include <stdlib.h>
#include "my.h"
#include "ecs.h"
#include "scene_parser.h"

int count_tabs(char *str)
{
    int i = 0;

    if (!str) {
        return -1;
    }
    for (; str[i] == '\t'; i++);
    return i;
}

static int my_array_len(char **arr)
{
    int i = 0;

    if (!arr) {
        return -1;
    }
    for (; arr[i]; i++);
    return i;
}

int get_sid_from_filepath(char *filepath)
{
    char **split_dot = NULL;
    char **split_slash = NULL;
    int id = 0;

    if ((split_dot = my_str_to_word_array(filepath, '.')) == NULL) {
        return -1;
    }
    if ((split_slash = my_str_to_word_array(split_dot[0], '/')) == NULL) {
        free_2d_array(split_dot);
        return -1;
    }
    id = my_atoi(split_slash[my_array_len(split_slash) - 1]);
    free_2d_array(split_dot);
    free_2d_array(split_slash);
    return id;
}

char *get_title_from_line(char *line)
{
    char *str = NULL;
    int start_i = 0;
    int end_i = 0;

    start_i = count_tabs(line);
    for (; line[end_i] != ':'; end_i++);
    if ((str = malloc(sizeof(char) * (end_i - start_i) + 1)) == NULL) {
        return NULL;
    }
    for (int i = start_i; i < end_i; i++) {
        str[i - start_i] = line[i];
    }
    str[end_i - start_i] = '\0';
    return str;
}

char *get_data_arg(char **data, char *arg_name)
{
    for (int i = 0; data[i]; i++) {
        if (my_str_has_prefix(data[i], arg_name)) {
            return data[i];
        }
    }
    return NULL;
}
