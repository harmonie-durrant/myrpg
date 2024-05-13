/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** ui_button
*/

#ifndef UI_BUTTON_H_
    #define UI_BUTTON_H_
    #include "ecs.h"
    #include "rpg.h"
    #include "types/s_types.h"

    typedef struct callback_parser_s {
        char *callback_name;
        void *(*callback)(entity_t *, rpg_t *, int);
    } callback_parser_t;

    typedef struct c_ui_button_s {
        v2i default_pos;
        v2i hover_pos;
        v2i pressed_pos;
        int val;
        int active;
        callback_parser_t callback;
    } c_ui_button_t;

component_t *create_ui_button_comp(c_ui_button_t *ui_button);
void destroy_ui_button(void *data);
void print_ui_button(void *data);

callback_parser_t get_callback_from_str(char *callback_str);

// CALLBACKS
void *print_callback_test(entity_t *entity, rpg_t *rpg, int i);
void *change_scene(entity_t *entity, rpg_t *rpg, int val);
void *toggle_pause_callback(entity_t *entity, rpg_t *rpg, int val);
void *toggle_settings(entity_t *entity, rpg_t *rpg, int val);
void *quit_game(entity_t *entity, rpg_t *rpg, int val);

#endif /* !UI_BUTTON_H_ */
