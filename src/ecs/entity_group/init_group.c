/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** init_group
*/

#include <stddef.h>
#include <stdlib.h>
#include "ecs.h"

entity_group_t *create_entity_group(e_group_type type, entity_t *entity)
{
    entity_group_t *group = NULL;

    if (type == G_T_ERROR) {
        return NULL;
    }
    group = malloc(sizeof(entity_group_t));
    if (!group) {
        return NULL;
    }
    group->type = type;
    group->entity = entity;
    group->next = NULL;
    return group;
}

void destroy_entity_group_list(entity_group_t *group)
{
    if (!group) {
        return;
    }
    destroy_entity_group_list(group->next);
    destroy_entity_list(group->entity);
    free(group);
}
