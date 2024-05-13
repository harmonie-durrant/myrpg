/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_tile
*/

#include <stdlib.h>
#include "components/tiles.h"
#include "types/c_types.h"

c_tile_map_t *create_tile_map(c_sprite_t *sprite)
{
    c_tile_map_t *tile_map = NULL;

    if ((tile_map = malloc(sizeof(c_tile_map_t))) == NULL) {
        return NULL;
    }
    tile_map->sprite = sprite;
    tile_map->tiles = NULL;
    return tile_map;
}

component_t *create_tile_map_comp(c_sprite_t *sprite)
{
    component_t *comp = NULL;
    c_tile_map_t *tile_map = NULL;

    if ((tile_map = create_tile_map(sprite)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_TILE_MAP, tile_map)) == NULL) {
        destroy_tile_map(tile_map);
        return NULL;
    }
    comp->destroy = &destroy_tile_map;
    comp->print = &print_tile_map;
    return comp;
}

tile_t *create_tile(v2f pos, v2i sprite_pos, short is_collidable)
{
    tile_t *tile = NULL;

    if ((tile = malloc(sizeof(tile_t))) == NULL) {
        return NULL;
    }
    tile->pos = pos;
    tile->sprite_pos = sprite_pos;
    tile->is_collidable = is_collidable;
    tile->next = NULL;
    return tile;
}

void destroy_tiles(tile_t *tile)
{
    if (tile == NULL) {
        return;
    }
    destroy_tiles(tile->next);
    free(tile);
}

void destroy_tile_map(void *data)
{
    c_tile_map_t *tile_map = (c_tile_map_t *)data;

    if (tile_map == NULL) {
        return;
    }
    destroy_tiles(tile_map->tiles);
    free(data);
}
