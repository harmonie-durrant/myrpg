/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** get_transform
*/

#include <unistd.h>
#include <stdlib.h>
#include "components/ui_button.h"
#include "ecs.h"
#include "rpg.h"
#include "my.h"

void print_ui_button(void *data)
{
    c_ui_button_t *btn = (c_ui_button_t*)data;

    my_fprintf(2, "[UI_BUTTON]: %p\n", data);
    if (!data) {
        my_fprintf(2, "UI button is NULL\n");
        return;
    }
    my_fprintf(2, "def: (%d, %d)\n", btn->default_pos.x, btn->default_pos.y);
    my_fprintf(2, "hover: (%d, %d)\n", btn->hover_pos.x, btn->hover_pos.y);
    my_fprintf(2, "click: (%d, %d)\n", btn->pressed_pos.x, btn->pressed_pos.y);
    my_fprintf(2, "value: %d\n", btn->val);
    my_fprintf(2, "isActive: %d\n", btn->active);
    if (!btn->callback.callback) {
        my_fprintf(2, "name: NULL\n");
        my_fprintf(2, "callback: NULL\n");
        return;
    }
    my_fprintf(2, "name: %s\n", btn->callback.callback_name);
    my_fprintf(2, "callback: %p\n", btn->callback.callback);
}

void *quit_game(entity_t *entity, rpg_t *rpg, int val)
{
    UNUSED(entity);
    if (val) {
        sfRenderWindow_close(rpg->win->window);
    }
    return NULL;
}
