/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** print_entity
*/

#include "ecs.h"
#include "my.h"

void print_entity(entity_t *entity)
{
    if (!entity) {
        return;
    }
    my_printf("======\tENTITY %d: %p\t======\n\n", entity->id, entity);
    print_component_list(entity->component);
    my_printf("======\t  END %d: %p\t======\n\n", entity->id, entity);
}

void print_entity_list(entity_t *head)
{
    if (!head) {
        return;
    }
    print_entity(head);
    print_entity_list(head->next);
}
