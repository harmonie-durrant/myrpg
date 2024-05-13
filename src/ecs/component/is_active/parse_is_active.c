/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parse_ui_button
*/

#include "components/is_active.h"
#include "scene.h"
#include "rpg.h"
#include "my.h"

component_t *parse_is_active_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    int val = 1;
    char *tmp = NULL;

    UNUSED(entity);
    UNUSED(rpg);
    if ((tmp = get_data_arg(data, "value:")) != NULL) {
        val = parse_int(tmp);
    }
    return create_is_active_comp(val);
}
