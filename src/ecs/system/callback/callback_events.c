/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** callback_events
*/

#include "components/ui_button.h"
#include "components/tag.h"
#include "components/is_active.h"
#include "components/dialogue.h"
#include "components/transform.h"
#include "components/sprite.h"
#include "systems/dialogue.h"
#include "scene.h"
#include "rpg.h"
#include "ecs.h"
#include "my.h"

static void call_entity_callbacks(entity_t *entity, rpg_t *rpg, v2f mpos)
{
    c_ui_button_t *ui_button_comp = NULL;
    c_transform_t *trans = NULL;
    c_sprite_t *sprite_comp = NULL;
    v2f tpos = {0,0};

    if (!entity || is_active(entity) == 0)
        return;
    ui_button_comp = get_component(entity->component, C_UI_BUTTON);
    trans = get_component(entity->component, C_TRANSFORM);
    sprite_comp = get_component(entity->component, C_SPRITE);
    if (!ui_button_comp || !trans || !sprite_comp ||
        !ui_button_comp->callback.callback || ui_button_comp->active == 0)
        return;
    tpos = (trans->follow_cam) ? getfollow_pos(trans, rpg) : trans->pos;
    if (mpos.x >= (int)(tpos.x) && mpos.y >= (int)(tpos.y) &&
        mpos.x <= (int)(tpos.x) + sprite_comp->rect.width &&
        mpos.y <= (int)(tpos.y) + sprite_comp->rect.height) {
        ui_button_comp->callback.callback(entity, rpg, ui_button_comp->val);
    }
}

static void call_ui_button_callback(scene_t *scene, rpg_t *rpg, v2f mpos)
{
    entity_group_t *group = NULL;
    entity_t *entity = NULL;

    if (!scene || !rpg)
        return;
    group = scene->entity_groups;
    while (group) {
        entity = group->entity;
        while (entity) {
            call_entity_callbacks(entity, rpg, mpos);
            entity = entity->next;
        }
        group = group->next;
    }
    return;
}

void mouse_released(rpg_t *rpg, entity_t *npc_ent, int *show_dialogue)
{
    sfRenderWindow *window = rpg->win->window;
    sfView *view = rpg->win->view;
    sfEvent evt = rpg->win->event;
    v2i mouse_p = {0, 0};
    v2f mouse_p_f = {0, 0};

    mouse_p = sfMouse_getPositionRenderWindow(window);
    mouse_p_f = sfRenderWindow_mapPixelToCoords(window, mouse_p, view);
    call_ui_button_callback(rpg->current_scene, rpg, mouse_p_f);
    if (evt.key.code == sfKeyE)
        toggle_dialogue_box(npc_ent, show_dialogue);
}

void toggle_pause(scene_t *c_scene, entity_t *pause_ind)
{
    c_is_active_t *tag_comp = NULL;

    if (c_scene->id == 0 || !pause_ind)
        return;
    tag_comp = get_component(pause_ind->component, C_IS_ACTIVE);
    if (!(tag_comp->val)) {
        show_entity_with_tag("logo", c_scene);
        show_entity_with_tag("pause_bg", c_scene);
        show_entity_with_tag("resume", c_scene);
        show_entity_with_tag("settings", c_scene);
        show_entity_with_tag("mainmenu", c_scene);
        return;
    }
    hide_entity_with_tag("logo", c_scene);
    hide_entity_with_tag("pause_bg", c_scene);
    hide_entity_with_tag("resume", c_scene);
    hide_entity_with_tag("settings", c_scene);
    hide_entity_with_tag("mainmenu", c_scene);
}

void key_released(rpg_t *rpg, sfEvent evt)
{
    scene_t *c_scene = rpg->current_scene;
    entity_t *pause_ind = NULL;

    my_printf("RELEASED: %d\n", evt.key.code);
    if (evt.key.code == sfKeyEscape) {
        my_printf("[ESC]\n");
        pause_ind = find_entity_with_tag("logo", c_scene);
        toggle_pause(c_scene, pause_ind);
    }
}
