/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** handle_dialogue
*/

#include "my.h"
#include "ecs.h"
#include "scene.h"
#include "banks.h"
#include "components/dialogue.h"
#include "types/s_types.h"

void draw_dialogue_box(c_dialogue_t *dialogue, rpg_t *rpg)
{
    sfSprite *txt_sp = NULL;
    sfSprite *avatar_sprite = NULL;
    v2f v_centre = {0,0};
    v2f v_size = {0,0};
    v2f v_pos = {0,0};

    if (!dialogue || !rpg)
        return;
    v_centre = sfView_getCenter(rpg->win->view);
    v_size = sfView_getSize(rpg->win->view);
    v_pos = (v2f){v_centre.x - v_size.x / 2, v_centre.y - v_size.y / 2};
    avatar_sprite = get_sprite_from_bank(rpg->sprite_bank, dialogue->type);
    if ((txt_sp = get_sprite_from_bank(rpg->sprite_bank, S_CHAT_BOX)) == NULL)
        return;
    sfSprite_setPosition(txt_sp, (v2f){467 + v_pos.x, 732 + v_pos.y});
    sfSprite_setScale(txt_sp, (v2f){1.45, 1.45});
    sfRenderWindow_drawSprite(rpg->win->window, txt_sp, NULL);
    sfSprite_setPosition(avatar_sprite, (v2f){542 + v_pos.x, 800 + v_pos.y});
    sfSprite_setScale(avatar_sprite, (v2f){0.75, 0.75});
    sfRenderWindow_drawSprite(rpg->win->window, avatar_sprite, NULL);
}

void toggle_dialogue_box(entity_t *npc_ent, int *show_box)
{
    if (!npc_ent)
        return;
    if (*show_box == 1)
        *show_box = 0;
    else
        *show_box = 1;
    return;
}
