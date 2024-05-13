/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_transfrom
*/

#include <stdlib.h>
#include "components/sprite.h"
#include "types/s_types.h"
#include "rpg.h"
#include "my.h"

e_sprite_type get_sprite_type(char *type_str)
{
    sprite_parser_t sprite_parser[] = {
        {"S_MAIN_MENU", S_MAIN_MENU}, {"S_LOGO", S_LOGO},
        {"S_MENU_BUTTON", S_MENU_BUTTON}, {"S_MAYOR", S_MAYOR},
        {"S_FARM_TILEMAP", S_FARM_TILEMAP}, {"S_CHAR", S_CHAR},
        {"S_SETTINGS_BACK", S_SETTINGS_BACK}, {"S_PAUSE_BG", S_PAUSE_BG},
        {"S_FARM_FEATURE", S_FARM_FEATURE}, {"S_CHAT_BOX", S_CHAT_BOX},
        {NULL, S_ERROR}
    };

    for (int j = 0; sprite_parser[j].name != NULL; j++) {
        if (my_strcmp(sprite_parser[j].name, type_str) == 0)
            return sprite_parser[j].type;
    }
    return S_ERROR;
}

static void parse_data(char **data, v2i *offset,
v2i *max_size, e_sprite_type *type)
{
    char *tmp = NULL;
    char *type_str = NULL;

    if ((tmp = get_data_arg(data, "size:")) != NULL)
        *max_size = parse_v2i(tmp);
    if ((tmp = get_data_arg(data, "type:")) != NULL)
        type_str = parse_str(tmp);
    *type = get_sprite_type(type_str);
    if ((tmp = get_data_arg(data, "offset:")) != NULL)
        *offset = parse_v2i(tmp);
    else
        *offset = *max_size;
    free(type_str);
}

component_t *parse_sprite_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    v2i offset = {0, 0};
    v2i max_size = {16, 16};
    e_sprite_type type = S_ERROR;

    UNUSED(entity);
    parse_data(data, &offset, &max_size, &type);
    return create_sprite_comp(rpg->sprite_bank, type, offset, max_size);
}
