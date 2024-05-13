/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_transform
*/

#include <stdlib.h>
#include "components/ui_button.h"
#include "ecs.h"

component_t *create_ui_button_comp(c_ui_button_t *ui_button)
{
    component_t *comp = NULL;

    if ((comp = create_component(C_UI_BUTTON, ui_button)) == NULL) {
        destroy_ui_button(ui_button);
        return NULL;
    }
    comp->destroy = &destroy_ui_button;
    comp->print = &print_ui_button;
    return comp;
}

void destroy_ui_button(void *data)
{
    free(data);
}
