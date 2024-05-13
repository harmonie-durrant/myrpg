/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** draw_sprite
*/

#include "components/ui_button.h"
#include "components/sprite.h"
#include "my.h"
#include "banks.h"
#include "ecs.h"

sfSprite *get_current_sprite(c_sprite_t *sprite, c_transform_t *transform,
rpg_t *rpg, entity_t *entity)
{
    c_ui_button_t *btn = NULL;

    if (!sprite) {
        return NULL;
    }
    if (!entity || !rpg || !transform) {
        return sprite->sf_sprite;
    }
    if ((btn = get_component(entity->component, C_UI_BUTTON)) != NULL) {
        if (is_clicked(transform, rpg, sprite)) {
            set_sprite_pos_state(sprite, btn->pressed_pos);
            return sprite->sf_sprite;
        }
        if (is_hovered(transform, rpg, sprite)) {
            set_sprite_pos_state(sprite, btn->hover_pos);
            return sprite->sf_sprite;
        }
        set_sprite_pos_state(sprite, btn->default_pos);
    }
    return sprite->sf_sprite;
}

v2f getfollow_pos(c_transform_t *trans, rpg_t *rpg)
{
    sfView *view = rpg->win->view;
    v2f new_pos = {0, 0};
    v2f view_pos = sfView_getCenter(view);
    v2f view_size = sfView_getSize(view);

    view_pos.x -= (view_size.x / 2);
    view_pos.y -= (view_size.y / 2);
    new_pos.x = view_pos.x + trans->pos.x;
    new_pos.y = view_pos.y + trans->pos.y;
    return new_pos;
}

void draw_sprite(c_sprite_t *sprite, c_transform_t *trans, rpg_t *rpg,
entity_t *entity)
{
    sfSprite *sf_sprite = NULL;
    v2f scale = SPRITE_SCALE;
    v2f pos = {0, 0};
    float rotation = 0;

    if (trans) {
        scale = trans->scale;
        pos = (trans->follow_cam) ? getfollow_pos(trans, rpg) : trans->pos;
        rotation = trans->rot;
    }
    sf_sprite = get_current_sprite(sprite, trans, rpg, entity);
    if (sf_sprite == NULL) {
        my_fprintf(2, "ERROR: couldn't get sprite from bank (draw_sprite)\n");
        return;
    }
    sfSprite_setTextureRect(sf_sprite, sprite->rect);
    sfSprite_setScale(sf_sprite, scale);
    sfSprite_setPosition(sf_sprite, pos);
    sfSprite_setRotation(sf_sprite, rotation);
    sfRenderWindow_drawSprite(rpg->win->window, sf_sprite, NULL);
}
