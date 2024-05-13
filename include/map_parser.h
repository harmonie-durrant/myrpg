/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** map
*/


#ifndef MAP_H_
    #define MAP_H_
    #include "ecs.h"
    #include "components/tiles.h"

// Parser

component_t *parse_map(c_sprite_t *sprite, char *filename, int layer);
int parse_tiles(c_tile_map_t *tilemap, char *str,
sprite_char_t *sprite_chars);

// Layers
int parse_interior_feature_layer(c_tile_map_t *tilemap, char *str);
int parse_interior_layer(c_tile_map_t *tilemap, char *str);
int parse_feature_layer(c_tile_map_t *tilemap, char *str);
int parse_feature_farm(c_tile_map_t *tilemap, char *str);
int parse_ground_layer(c_tile_map_t *tilemap, char *str);
int handle_layer_parsing(c_tile_map_t *tilemap, char *str, int layer);

#endif /* !MAP_H_ */
