/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parser_group_utils
*/

#include <stdlib.h>
#include "scene.h"
#include "my.h"
#include "ecs.h"
#include "scene_parser.h"

static char *get_type_str_from_line(char *line)
{
    char *type_str = NULL;
    int i = 0;

    for (; line[i] != ':'; i++);
    if ((type_str = malloc(sizeof(char) * i + 1)) == NULL) {
        return NULL;
    }
    for (int j = 0; j < i; j++) {
        type_str[j] = line[j];
    }
    type_str[i] = '\0';
    return type_str;
}

static e_group_type get_group_type_from_str(char *str)
{
    if (!str)
        return G_T_ERROR;
    if (my_strcmp(str, "G_T_MAP") == 0)
        return G_T_MAP;
    if (my_strcmp(str, "G_T_PLAYER") == 0)
        return G_T_PLAYER;
    if (my_strcmp(str, "G_T_NPC") == 0)
        return G_T_NPC;
    if (my_strcmp(str, "G_T_MUSIC") == 0)
        return G_T_MUSIC;
    if (my_strcmp(str, "G_T_UI") == 0)
        return G_T_UI;
    if (my_strcmp(str, "G_T_MAP") == 0)
        return G_T_MAP;
    return G_T_OTHER;
}

entity_group_t *create_entity_groups(char **file_data_2d)
{
    entity_group_t *groups = NULL;
    entity_group_t *group = NULL;
    char *type_str = NULL;
    e_group_type group_type = G_T_OTHER;

    for (size_t i = 0; file_data_2d[i] != NULL; i++) {
        if (count_tabs(file_data_2d[i]) == 0) {
            add_entity_group(group, &groups);
            type_str = get_type_str_from_line(file_data_2d[i]);
            group_type = get_group_type_from_str(type_str);
            group = create_entity_group(group_type, NULL);
        }
    }
    add_entity_group(group, &groups);
    free(type_str);
    return groups;
}
