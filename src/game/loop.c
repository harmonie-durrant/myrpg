/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** loop
*/

#include "components/animator.h"
#include "components/is_active.h"
#include "components/ui_button.h"
#include "components/sound.h"
#include "systems/dialogue.h"
#include "systems/callback.h"
#include "components/dialogue.h"
#include "scene.h"
#include "rpg.h"
#include "update.h"
#include "splash.h"
#include "window.h"
#include "ecs.h"
#include "my.h"

void event_handler(rpg_t *rpg, int *show_dialogue)
{
    window_t *win = rpg->win;
    sfEvent evt = rpg->win->event;
    entity_t *npc_ent = is_player_close_to_npcs(rpg->current_scene);

    rpg->input = get_input();
    while (sfRenderWindow_pollEvent(win->window, &evt)) {
        if (evt.type == sfEvtResized) {
            sfRenderWindow_setView(win->window, win->view);
            sfView_setViewport(win->view, (sfFloatRect){0, 0, 1, 1});
        }
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (evt.type == sfEvtMouseButtonReleased)
            mouse_released(rpg, npc_ent, show_dialogue);
        if (evt.type == sfEvtKeyReleased)
            key_released(rpg, evt);
    }
    *show_dialogue = (npc_ent == NULL) ? 0 : *show_dialogue;
    if (*show_dialogue == 1)
        draw_dialogue_box(get_component(npc_ent->component, C_DIALOGUE), rpg);
}

static void draw_screen(rpg_t *rpg)
{
    if (rpg->current_scene->id == 0) {
        init_view(rpg->win, rpg->win->mode.width, rpg->win->mode.height);
    }
    sfRenderWindow_display(rpg->win->window);
    show_fps(rpg->win);
}

static void execute_frame(rpg_t *rpg, int *show_dialogue, splash_t *splash)
{
    sfRenderWindow_clear(rpg->win->window,
    rpg->current_scene->id == 1 ? sfBlack : WATER_COLOR);
    update_entity_group_list(rpg->current_scene->entity_groups, rpg);
    sfRenderWindow_setView(rpg->win->window, rpg->win->view);
    event_handler(rpg, show_dialogue);
    show_splash_screen(splash, rpg);
    draw_screen(rpg);
}

int start_game(rpg_t *rpg)
{
    window_t *win = NULL;
    splash_t *splash = NULL;
    int show_dialogue = 0;

    if (init_splash_screen(rpg, &splash) == 84)
        return 84;
    win = rpg->win;
    rpg->current_scene = get_scene(0, rpg);
    if (rpg->current_scene == NULL)
        return 84;
    play_scene_sound(rpg->current_scene, 1);
    while (sfRenderWindow_isOpen(win->window)) {
        execute_frame(rpg, &show_dialogue, splash);
    }
    return 0;
}
