/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** get_line_data
*/

#include <stdlib.h>
#include "scene.h"
#include "my.h"
#include "ecs.h"
#include "components/sprite.h"
#include "scene_parser.h"

comp_type_t get_comp_type_str_from_line(char *str)
{
    char *title = NULL;
    comp_type_t c_type = 0;

    title = get_title_from_line(str);
    if (STR_EQ(title, "sprite")) {
        c_type = C_SPRITE;
    }
    return c_type;
}

char *get_data_from_line(char *line)
{
    char *str = NULL;
    int start_i = 0;
    int end_i = 0;

    start_i = count_tabs(line) + 2;
    for (; line[end_i] != '\0' && line[end_i] != '\n'; end_i++);
    str = malloc(sizeof(char) * (end_i - start_i) + 2);
    for (int i = start_i; i < end_i; i++)
        str[i - start_i] = line[i];
    str[end_i - start_i] = '\0';
    return str;
}

char **get_data_from_lines(char **file_data_2d, int i)
{
    char **data_str_2d = NULL;
    int counter = 0;

    for (size_t j = i + 1; file_data_2d[j] != NULL; j++) {
        if (count_tabs(file_data_2d[j]) != 3) {
            break;
        }
        counter++;
    }
    data_str_2d = malloc(sizeof(char *) * counter + 1);
    counter = i + 1;
    for (i = i + 1; file_data_2d[i] != NULL; i++) {
        if (count_tabs(file_data_2d[i]) == 3) {
            data_str_2d[counter - i] = get_data_from_line(file_data_2d[i]);
            counter += 2;
        } else
            break;
    }
    data_str_2d[counter - i] = NULL;
    return data_str_2d;
}
