/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** print_collider
*/

#include "components/collider.h"
#include "components/transform.h"
#include "my.h"

void print_collision(entity_t *entity1, entity_t *entity2)
{
    c_transform_t *tmp = NULL;

    if (entity2) {
        tmp = get_component(entity1->component, C_TRANSFORM);
        my_fprintf(2, "collision between %p ", entity1);
        my_fprintf(2, "at (%f, %f)", tmp->pos.x, tmp->pos.y);
        tmp = get_component(entity2->component, C_TRANSFORM);
        my_fprintf(2, "and %p ", entity2);
        my_fprintf(2, "at (%f, %f)\n\n", tmp->pos.x, tmp->pos.y);
    }
}

void print_collider(void *data)
{
    c_collider_t *coll = (c_collider_t *)data;
    v2f size = {0};

    my_fprintf(2, "[COLLIDER]: %p\n", coll);
    if (coll) {
        size = sfRectangleShape_getSize(coll->box);
        my_fprintf(2, "box: %p\n", coll->box);
        my_fprintf(2, "trigger: %p\n", coll->trigger);
        my_fprintf(2, "size: (%f, %f)\n", size.x, size.y);
    }
}
