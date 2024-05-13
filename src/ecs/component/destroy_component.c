/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_component
*/

#include <stdlib.h>
#include "ecs.h"
#include "my.h"

void destroy_component(component_t *component)
{
    if (!component) {
        return;
    }
    component->destroy(component->data);
    free(component);
}

void destroy_component_list(component_t *head)
{
    if (!head) {
        return;
    }
    destroy_component_list(head->next);
    destroy_component(head);
}
