/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_sprite
*/

#include "components/ui_button.h"
#include "components/sprite.h"
#include "my.h"
#include "banks.h"
#include "ecs.h"

void print_sprite(void *data)
{
    c_sprite_t *sprite = (c_sprite_t*)data;

    my_fprintf(2, "SPRITE: %p\n", sprite);
    if (!sprite) {
        my_fprintf(2, "No sprite\n");
        return;
    }
    my_fprintf(2, "sfSprite: %p\n", sprite->sf_sprite);
    my_fprintf(2, "offset: (%d, %d)\n", sprite->offset.x, sprite->offset.y);
    my_fprintf(2, "max: (%d, %d)\n", sprite->max_size.x, sprite->max_size.y);
    my_fprintf(2, "rect: \n- left: %d\n- top: %d\n",
    sprite->rect.left, sprite->rect.top);
    my_fprintf(2, "- width: %d\n- height: %d\n",
    sprite->rect.width, sprite->rect.height);
}

void move_sprite_col(c_sprite_t *sprite)
{
    v2i offset = sprite->offset;
    v2i max = sprite->max_size;
    sfIntRect rect = sprite->rect;

    rect.left += offset.x;
    if (rect.left > max.x) {
        rect.left = 0;
    }
    sprite->rect = rect;
}

void set_sprite_pos_state(c_sprite_t *sprite, v2i pos)
{
    sprite->rect.top = pos.y;
    sprite->rect.left = pos.x;
    if (sprite->rect.left > sprite->max_size.x) {
        sprite->rect.left = 0;
    }
    if (sprite->rect.top > sprite->max_size.y) {
        sprite->rect.top = 0;
    }
}

int set_sprite_pos(c_sprite_t *sprite, v2i pos)
{
    sprite->rect.left = 0;
    for (int i = 0; i < pos.x; i++) {
        move_sprite_col(sprite);
    }
    return set_sprite_line(sprite, pos.y);
}
