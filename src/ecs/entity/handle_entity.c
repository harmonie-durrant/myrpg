/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** entity_handler
*/

#include <stdlib.h>
#include "ecs.h"
#include "my.h"
#include "window.h"
#include "components/animator.h"
#include "components/sprite.h"
#include "components/tiles.h"

int append_entity(entity_t **head, entity_t *entity)
{
    if (entity == NULL) {
        return -1;
    }
    if (*head != NULL) {
        entity->next = *head;
    }
    *head = entity;
    return 0;
}

entity_t *get_entity(entity_t *head, int id)
{
    entity_t *curr = head;

    while (curr && curr->id != id) {
        curr = curr->next;
    }
    return curr;
}
