/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parser_entities_utils
*/

#include <stdlib.h>
#include "scene.h"
#include "my.h"
#include "ecs.h"
#include "scene_parser.h"

int create_entities_in_groups(entity_group_t *groups, char **file_data_2d)
{
    entity_group_t *c_group = NULL;
    entity_t *c_entity = NULL;

    c_group = groups;
    for (size_t i = 0; file_data_2d[i] != NULL; i++) {
        if (count_tabs(file_data_2d[i]) == 0) {
            c_group = (i == 0) ? groups : c_group->next;
        }
        if (count_tabs(file_data_2d[i]) == 1) {
            c_entity = create_entity(-1);
            append_entity(&c_group->entity, c_entity);
        }
    }
    return 0;
}
