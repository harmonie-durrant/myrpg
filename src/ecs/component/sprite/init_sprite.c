/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_sprite
*/

#include <stdlib.h>
#include "components/sprite.h"
#include "banks.h"

c_sprite_t *create_sprite(sprite_bank_t *sprite_bank, e_sprite_type type,
v2i offset, v2i max_size)
{
    c_sprite_t *sprite = NULL;
    sfSprite *sf_sprite = NULL;

    sf_sprite = get_sprite_from_bank(sprite_bank, type);
    if (!sf_sprite) {
        return NULL;
    }
    sprite = malloc(sizeof(c_sprite_t));
    if (!sprite) {
        return NULL;
    }
    sprite->sf_sprite = get_sprite_from_bank(sprite_bank, type);
    sprite->offset = offset;
    sprite->max_size = max_size;
    sprite->rect = (sfIntRect){0, 0, offset.x, offset.y};
    sprite->is_active = 1;
    return sprite;
}

component_t *create_sprite_comp(sprite_bank_t *sprite_bank, e_sprite_type type,
v2i offset, v2i max_size)
{
    c_sprite_t *sprite = NULL;
    component_t *comp = NULL;

    if (!(sprite = create_sprite(sprite_bank, type, offset, max_size))) {
        return NULL;
    }
    if ((comp = create_component(C_SPRITE, sprite)) == NULL) {
        destroy_sprite(sprite);
        return NULL;
    }
    comp->destroy = &destroy_sprite;
    comp->print = &print_sprite;
    return comp;
}

void destroy_sprite(void *data)
{
    free(data);
}
