/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_tile
*/

#include "window.h"
#include "components/tiles.h"

int append_tile(tile_t **head, tile_t *tile)
{
    if (head == NULL) {
        return -1;
    }
    if (*head != NULL) {
        tile->next = *head;
    }
    *head = tile;
    return 0;
}

int add_tile(c_tile_map_t *tile_map, v2f pos, v2i sprite_pos,
short is_collidable)
{
    tile_t *tile = NULL;

    if ((tile = create_tile(pos, sprite_pos, is_collidable)) == NULL) {
        return -1;
    }
    if (append_tile(&tile_map->tiles, tile) == -1) {
        destroy_tiles(tile);
        return -1;
    }
    return 0;
}

tile_t *get_tile(c_tile_map_t *tilemap, v2f pos)
{
    tile_t *tile = NULL;

    if (tilemap == NULL || tilemap->tiles == NULL) {
        return NULL;
    }
    tile = tilemap->tiles;
    while (tile != NULL) {
        if (tile->pos.x == pos.x && tile->pos.y == pos.y) {
            return tile;
        }
        tile = tile->next;
    }
    return NULL;
}

void draw_tile_map(c_tile_map_t *tile_map, rpg_t *rpg)
{
    tile_t *tile = NULL;
    c_transform_t transform = {0, {0, 0}, SPRITE_SCALE, 0};

    if (tile_map == NULL || tile_map->tiles == NULL) {
        return;
    }
    tile = tile_map->tiles;
    while (tile != NULL) {
        transform.pos = tile->pos;
        set_sprite_pos(tile_map->sprite, tile->sprite_pos);
        draw_sprite(tile_map->sprite, &transform, rpg, NULL);
        tile = tile->next;
    }
}
