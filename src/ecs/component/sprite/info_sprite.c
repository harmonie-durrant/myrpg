/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** info_sprite
*/

#include "components/ui_button.h"
#include "components/sprite.h"
#include "my.h"
#include "banks.h"
#include "ecs.h"

int set_sprite_line(c_sprite_t *sprite, int line)
{
    sprite->rect.top = 0;
    for (int i = 0; i < line; i++) {
        sprite->rect.top += sprite->offset.y;
    }
    if (sprite->rect.top > sprite->max_size.y) {
        sprite->rect.top = 0;
        return -1;
    }
    return 0;
}

int is_hovered(c_transform_t *trans, rpg_t *rpg, c_sprite_t *sprite)
{
    v2i mpos_i = {0, 0};
    v2f tpos = {0, 0};
    v2f mpos = {0, 0};
    window_t *win = rpg->win;

    mpos_i = sfMouse_getPositionRenderWindow(win->window);
    mpos = sfRenderWindow_mapPixelToCoords(win->window, mpos_i, win->view);
    tpos = (trans->follow_cam) ? getfollow_pos(trans, rpg) : trans->pos;
    if (mpos.x >= tpos.x && mpos.y >= tpos.y &&
        mpos.x <= tpos.x + (float)(sprite->rect.width) &&
        mpos.y <= tpos.y + (float)(sprite->rect.height)) {
        return 1;
    }
    return 0;
}

int is_clicked(c_transform_t *trans, rpg_t *rpg, c_sprite_t *sprite)
{
    v2i mpos_i = {0, 0};
    v2f tpos = {0, 0};
    v2f mpos = {0, 0};
    window_t *win = rpg->win;
    sfBool is_pressed = sfFalse;

    mpos_i = sfMouse_getPositionRenderWindow(win->window);
    is_pressed = sfMouse_isButtonPressed(sfMouseLeft);
    mpos = sfRenderWindow_mapPixelToCoords(win->window, mpos_i, win->view);
    tpos = (trans->follow_cam) ? getfollow_pos(trans, rpg) : trans->pos;
    if (mpos.x >= tpos.x && mpos.y >= tpos.y &&
        mpos.x <= tpos.x + (float)(sprite->rect.width) &&
        mpos.y <= tpos.y + (float)(sprite->rect.height)) {
        return (is_pressed == sfTrue) ? 1 : 0;
    }
    return 0;
}
