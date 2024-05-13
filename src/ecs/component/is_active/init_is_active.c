/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_transform
*/

#include <stdlib.h>
#include "components/is_active.h"
#include "ecs.h"

c_is_active_t *create_is_active(int val)
{
    c_is_active_t *is_active = NULL;

    is_active = malloc(sizeof(c_is_active_t));
    if (!is_active) {
        return NULL;
    }
    is_active->val = val;
    return is_active;
}

component_t *create_is_active_comp(int val)
{
    c_is_active_t *is_active = NULL;
    component_t *comp = NULL;

    if ((is_active = create_is_active(val)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_IS_ACTIVE, is_active)) == NULL) {
        destroy_is_active(is_active);
        return NULL;
    }
    comp->destroy = &destroy_is_active;
    comp->print = &print_is_active;
    return comp;
}

void destroy_is_active(void *data)
{
    free(data);
}
