/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** get_transform
*/

#include <unistd.h>
#include <stdlib.h>
#include "components/is_active.h"
#include "ecs.h"
#include "rpg.h"
#include "my.h"

void print_is_active(void *data)
{
    c_is_active_t *is_active = (c_is_active_t*)data;

    my_fprintf(2, "[IS_ACTIVE]: %p\n", data);
    if (!data) {
        my_fprintf(2, "IS_ACTIVE is NULL\n");
        return;
    }
    my_fprintf(2, "val: %d\n", is_active->val);
}

void set_active(int active, entity_t *entity)
{
    c_is_active_t *is_active = NULL;

    if ((is_active = get_component(entity->component, C_IS_ACTIVE)) == NULL) {
        return;
    }
    is_active->val = active;
}

int is_active(entity_t *entity)
{
    c_is_active_t *is_active = NULL;

    if ((is_active = get_component(entity->component, C_IS_ACTIVE)) == NULL) {
        return 1;
    }
    if (!entity) {
        return 0;
    }
    return is_active->val;
}
