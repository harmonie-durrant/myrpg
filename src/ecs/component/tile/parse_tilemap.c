/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parse_component
*/

#include <stdlib.h>
#include "components/tiles.h"
#include "my.h"
#include "map_parser.h"

component_t *parse_tilemap_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    component_t *comp = NULL;
    c_sprite_t *sprite = NULL;
    char *tmp = NULL;
    char *filename = NULL;
    int layer = 1;

    UNUSED(rpg);
    if ((sprite = get_component(entity->component, C_SPRITE)) == NULL)
        return NULL;
    if ((tmp = get_data_arg(data, "layer:")) != NULL) {
        layer = parse_int(tmp);
    }
    if ((tmp = get_data_arg(data, "file:")) != NULL) {
        if ((filename = parse_str(tmp)) == NULL) {
            return NULL;
        }
    }
    comp = parse_map(sprite, filename, layer);
    free(filename);
    return comp;
}
