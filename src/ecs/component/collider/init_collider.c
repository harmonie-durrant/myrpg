/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_collider
*/

#include <stdlib.h>
#include "components/collider.h"
#include "banks.h"
#include "scene.h"

static void init_collider(c_collider_t *collider, v2f rect_size)
{
    sfRectangleShape_setFillColor(collider->box, (sfColor){0,255,0,125});
    sfRectangleShape_setSize(collider->box, rect_size);
    sfRectangleShape_setScale(collider->box, SPRITE_SCALE);
    collider->trigger_val = -1;
    collider->offset = (v2f){0, 0};
}

c_collider_t *create_collider(entity_t *entity, rpg_t *rpg,
v2f size, v2f pos)
{
    c_collider_t *collider = NULL;
    v2f rect_size = (size.x == 0 && size.y == 0) ? (v2f){1, 1} : size;

    if (!entity || !rpg)
        return NULL;
    if ((collider = malloc(sizeof(c_collider_t))) == NULL)
        return NULL;
    if ((collider->box = sfRectangleShape_create()) == NULL) {
        free(collider);
        return NULL;
    }
    sfRectangleShape_setPosition(collider->box, pos);
    collider->is_static = 0;
    collider->is_colliding = 0;
    collider->trigger = NULL;
    collider->trigger_vec = (v2f){-1, -1};
    init_collider(collider, rect_size);
    add_box_bank(rpg, entity, collider);
    return collider;
}

component_t *create_collider_comp(entity_t *entity, rpg_t *rpg,
v2f scale, v2f pos)
{
    c_collider_t *collider = NULL;
    component_t *comp = NULL;

    if ((collider = create_collider(entity, rpg, scale, pos)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_COLLIDER, collider)) == NULL) {
        destroy_collider(collider);
    }
    comp->print = &print_collider;
    comp->destroy = &destroy_collider;
    comp->update = &update_collider;
    return comp;
}

void destroy_collider(void *data)
{
    c_collider_t *collider = (c_collider_t *)data;

    sfRectangleShape_destroy(collider->box);
    free(collider);
}
