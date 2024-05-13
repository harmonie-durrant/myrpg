/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_group
*/

#include "ecs.h"
#include "window.h"

entity_t *get_entity_from_group(entity_group_t *groups, e_group_type type)
{
    entity_group_t *tmp = groups;

    if (!groups) {
        return NULL;
    }
    while (tmp != NULL) {
        if (tmp->type == type) {
            return tmp->entity;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void add_entity_group(entity_group_t *group, entity_group_t **groups)
{
    entity_group_t *tmp = NULL;

    tmp = *groups;
    if (!group) {
        return;
    }
    if (!*groups) {
        *groups = group;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = group;
}
