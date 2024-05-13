/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parse_dialogue
*/

#include <stdlib.h>
#include "components/sound.h"
#include "components/dialogue.h"
#include "scene.h"
#include "scene_parser.h"
#include "rpg.h"
#include "my.h"

component_t *parse_dialogue_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    char **player_dialogue = NULL;
    char **npc_dialogue = NULL;
    char *type_str = NULL;
    char *tmp = NULL;
    e_sprite_type type = 0;

    UNUSED(entity);
    UNUSED(rpg);
    if ((tmp = get_data_arg(data, "npc-dialogue:")) != NULL) {
        npc_dialogue = parse_str_2d(tmp, ';');
    }
    if ((tmp = get_data_arg(data, "player-dialogue:")) != NULL) {
        player_dialogue = parse_str_2d(tmp, ';');
    }
    if ((tmp = get_data_arg(data, "type:")) != NULL) {
        type_str = parse_str(tmp);
        type = get_sprite_type(type_str);
    }
    return create_dialogue_comp(player_dialogue, npc_dialogue, type);
}
