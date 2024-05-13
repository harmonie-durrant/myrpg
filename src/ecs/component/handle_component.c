/*
** EPITECH PROJECT, 2023
** ECS_test
** File description:
** component_handler
*/

#include <stdlib.h>
#include "ecs.h"

void *get_component(component_t *head, comp_type_t type)
{
    component_t *curr = head;

    if (head == NULL) {
        return NULL;
    }
    while (curr) {
        if (curr->type == type)
            break;
        curr = curr->next;
    }
    return curr ? curr->data : NULL;
}

int remove_component(component_t **head, comp_type_t type)
{
    component_t *curr = *head;
    component_t *prev = *head;

    if (!curr)
        return -1;
    if (curr->type == type) {
        *head = curr->next;
        destroy_component(curr);
        return 0;
    }
    while (curr && curr->type != type) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        prev->next = curr->next;
        destroy_component(curr);
        return 0;
    }
    return -1;
}
