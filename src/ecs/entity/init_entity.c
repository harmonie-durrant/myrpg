/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** entity_creator
*/

#include <stdlib.h>
#include "ecs.h"

entity_t *create_entity(int id)
{
    static int default_id = 1000;
    entity_t *entity = NULL;

    entity = malloc(sizeof(entity_t));
    if (!entity) {
        return NULL;
    }
    if (id < 0) {
        entity->id = default_id;
        default_id++;
    } else {
        entity->id = id;
    }
    entity->component = NULL;
    entity->next = NULL;
    return entity;
}

void destroy_entity(entity_t *entity)
{
    if (!entity) {
        return;
    }
    destroy_component_list(entity->component);
    free(entity);
}

void destroy_entity_list(entity_t *head)
{
    if (head == NULL) {
        return;
    }
    destroy_entity_list(head->next);
    destroy_entity(head);
}
