/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** tiles
*/

#ifndef TILES_H_
    #define TILES_H_
    #include "ecs.h"
    #include "types/s_types.h"
    #include "components/sprite.h"
    #include "window.h"

    typedef struct tile_s {
        v2f pos;
        v2i sprite_pos;
        short is_collidable;
        struct tile_s *next;
    } tile_t;

    typedef struct c_tile_map_s {
        c_sprite_t *sprite;
        tile_t *tiles;
    } c_tile_map_t;

// tiles

c_tile_map_t *create_tile_map(c_sprite_t *sprite);
component_t *create_tile_map_comp(c_sprite_t *sprite);
tile_t *create_tile(v2f pos, v2i sprite_pos, short is_collidable);
void destroy_tile_map(void *data);
void destroy_tiles(tile_t *head);
void print_tile_map(void *data);

int append_tile(tile_t **head, tile_t *tile);
int add_tile(c_tile_map_t *tile_map, v2f pos, v2i sprite_pos,
short is_collidable);
tile_t *get_tile(c_tile_map_t *tilemap, v2f pos);
void draw_tile_map(c_tile_map_t *tile_map, rpg_t *rpg);

#endif /* !TILES_H_ */
