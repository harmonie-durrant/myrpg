/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_hitbox
*/

#include <stdlib.h>
#include "components/hitbox.h"

c_hitbox_t *create_hitbox(v2f offset, v2f size)
{
    c_hitbox_t *hitbox = NULL;

    if ((hitbox = malloc(sizeof(c_hitbox_t))) == NULL) {
        return NULL;
    }
    if ((hitbox->box = sfRectangleShape_create()) == NULL) {
        free(hitbox);
    }
    sfRectangleShape_setFillColor(hitbox->box, DEBUG_YELLOW);
    sfRectangleShape_setSize(hitbox->box, size);
    hitbox->is_active = 0;
    hitbox->offset = offset;
    hitbox->flip = 0;
    return hitbox;
}

component_t *create_hitbox_comp(v2f offset, v2f size)
{
    component_t *comp = NULL;
    c_hitbox_t *hitbox = NULL;

    if ((hitbox = create_hitbox(offset, size)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_HITBOX, hitbox)) == NULL) {
        destroy_hitbox(hitbox);
        return NULL;
    }
    comp->print = &print_hitbox;
    comp->destroy = &destroy_hitbox;
    comp->update = &update_hitbox;
    return comp;
}

void destroy_hitbox(void *data)
{
    c_hitbox_t *hitbox = (c_hitbox_t *)data;

    if (hitbox == NULL) {
        return;
    }
    sfRectangleShape_destroy(hitbox->box);
    free(hitbox);
}
