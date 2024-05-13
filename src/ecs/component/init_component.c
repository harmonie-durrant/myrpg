/*
** EPITECH PROJECT, 2023
** ECS_test
** File description:
** component_creator
*/

#include <stdlib.h>
#include "ecs.h"

component_t *create_component(comp_type_t type, void *data)
{
    component_t *component = NULL;

    component = malloc(sizeof(component_t));
    if (!component) {
        return NULL;
    }
    component->type = type;
    component->data = data;
    component->destroy = NULL;
    component->print = NULL;
    component->update = NULL;
    component->next = NULL;
    return component;
}

int append_component(component_t **head, component_t *new)
{
    if (new == NULL) {
        return -1;
    }
    if (*head != NULL) {
        new->next = *head;
    }
    *head = new;
    return 0;
}
