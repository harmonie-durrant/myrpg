/*
** EPITECH PROJECT, 2023
** ECS_test
** File description:
** component_printer
*/

#include <stdlib.h>
#include "my.h"
#include "ecs.h"
#include "rpg.h"

void print_component_list(component_t *head)
{
    component_t *curr = head;

    if (!curr) {
        return;
    }
    while (curr) {
        curr->print(curr->data);
        my_fputchar(2, '\n');
        curr = curr->next;
    }
}
