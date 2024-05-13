/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parse_ui_button
*/

#include <stdlib.h>
#include "components/sound.h"
#include "components/tag.h"
#include "components/ui_button.h"
#include "components/sprite.h"
#include "components/tag.h"
#include "types/s_types.h"
#include "scene_parser.h"
#include "scene.h"
#include "rpg.h"
#include "my.h"

void *toggle_settings(entity_t *entity, rpg_t *rpg, int val)
{
    UNUSED(entity);
    if (val == 0) {
        show_entity_with_tag("settings", rpg->current_scene);
        show_entity_with_tag("play", rpg->current_scene);
        show_entity_with_tag("quit", rpg->current_scene);
        hide_entity_with_tag("settings_background", rpg->current_scene);
        hide_entity_with_tag("back", rpg->current_scene);
        show_entity_with_tag("resume", rpg->current_scene);
        show_entity_with_tag("mainmenu", rpg->current_scene);
        return NULL;
    }
    hide_entity_with_tag("settings", rpg->current_scene);
    hide_entity_with_tag("play", rpg->current_scene);
    hide_entity_with_tag("quit", rpg->current_scene);
    show_entity_with_tag("settings_background", rpg->current_scene);
    show_entity_with_tag("back", rpg->current_scene);
    hide_entity_with_tag("settings", rpg->current_scene);
    hide_entity_with_tag("mainmenu", rpg->current_scene);
    return NULL;
}

void *toggle_pause_callback(entity_t *entity, rpg_t *rpg, int val)
{
    scene_t *c_scene = rpg->current_scene;

    UNUSED(entity);
    if (val == 0) {
        hide_entity_with_tag("logo", c_scene);
        hide_entity_with_tag("pause_bg", c_scene);
        hide_entity_with_tag("resume", c_scene);
        hide_entity_with_tag("settings", c_scene);
        hide_entity_with_tag("mainmenu", c_scene);
        return NULL;
    }
    show_entity_with_tag("logo", c_scene);
    show_entity_with_tag("pause_bg", c_scene);
    show_entity_with_tag("resume", c_scene);
    show_entity_with_tag("settings", c_scene);
    show_entity_with_tag("mainmenu", c_scene);
    return NULL;
}

callback_parser_t get_callback_from_str(char *callback_str)
{
    callback_parser_t callback = {NULL, NULL};
    callback_parser_t callbacks[] = {
        {"toggle_settings", &toggle_settings}, {"change_scene", &change_scene},
        {"toggle_pause", &toggle_pause_callback},
        {"quit", &quit_game},
        {NULL, NULL}
    };

    for (int i = 0; callbacks[i].callback_name != NULL; i++) {
        if (STR_EQ(callbacks[i].callback_name, callback_str)) {
            callback = callbacks[i];
        }
    }
    return callback;
}

static void set_parsing_values(c_ui_button_t *ui_button, char **data)
{
    char *callback_str = NULL;
    char *tmp = NULL;

    if ((tmp = get_data_arg(data, "default:")) != NULL)
        ui_button->default_pos = parse_v2i(tmp);
    if ((tmp = get_data_arg(data, "hover:")) != NULL)
        ui_button->hover_pos = parse_v2i(tmp);
    if ((tmp = get_data_arg(data, "pressed:")) != NULL)
        ui_button->pressed_pos = parse_v2i(tmp);
    if ((tmp = get_data_arg(data, "active:")) != NULL)
        ui_button->active = parse_int(tmp);
    if ((tmp = get_data_arg(data, "value:")) != NULL)
        ui_button->val = parse_int(tmp);
    if ((tmp = get_data_arg(data, "callback:")) != NULL) {
        callback_str = parse_str(tmp);
        ui_button->callback = get_callback_from_str(callback_str);
    }
    free(callback_str);
}

component_t *parse_ui_button_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    c_ui_button_t *ui_button = NULL;

    UNUSED(entity);
    UNUSED(rpg);
    if ((ui_button = malloc(sizeof(c_ui_button_t))) == NULL) {
        return NULL;
    }
    set_parsing_values(ui_button, data);
    return create_ui_button_comp(ui_button);
}
