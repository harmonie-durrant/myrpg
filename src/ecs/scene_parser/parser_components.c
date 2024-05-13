/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parser_components
*/

#include <stdlib.h>
#include "my.h"
#include "ecs.h"
#include "components/sprite.h"
#include "types/s_types.h"
#include "scene_parser.h"
#include "banks.h"

e_sprite_type get_sprite_type_from_string(char *str)
{
    if (STR_EQ(str, "S_CHAR"))
        return S_CHAR;
    if (STR_EQ(str, "S_MAIN_MENU"))
        return S_MAIN_MENU;
    return S_CHAR;
}

c_sprite_t *create_sprite_component_from_data(char **data, rpg_t *rpg)
{
    c_sprite_t *sprite = NULL;
    e_sprite_type type = 0;
    v2i offset = {0, 0};
    v2i max_size = {0, 0};
    char **coord = NULL;

    sprite = malloc(sizeof(c_sprite_t));
    if (!sprite) {
        return NULL;
    }
    type = get_sprite_type_from_string(data[0]);
    sprite->sf_sprite = get_sprite_from_bank(rpg->sprite_bank, type);
    coord = my_str_to_word_array(data[1], ',');
    offset = (v2i){my_atoi(coord[0]), my_atoi(coord[1])};
    coord = my_str_to_word_array(data[2], ',');
    max_size = (v2i){my_atoi(coord[0]), my_atoi(coord[1])};
    create_sprite_comp(rpg->sprite_bank, type, offset, max_size);
    return sprite;
}
