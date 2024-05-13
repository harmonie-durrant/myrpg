/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-reuban.bryenton
** File description:
** handle_layer_parsing
*/

#include "map_parser.h"

int handle_layer_parsing_helper(c_tile_map_t *tilemap,char *str)
{
    parse_feature_layer(tilemap, str);
    parse_feature_farm(tilemap, str);
    return 0;
}

int handle_layer_parsing(c_tile_map_t *tilemap,char *str, int layer)
{
    int status = 0;

    switch (layer) {
    case 1:
        status += parse_ground_layer(tilemap, str);
        break;
    case 2:
        handle_layer_parsing_helper(tilemap, str);
        break;
    case 3:
        status += parse_interior_layer(tilemap, str);
        break;
    case 4:
        status += parse_interior_feature_layer(tilemap, str);
        break;
    default:
        status = -1;
        break;
    }
    return status != 0 ? -1 : 0;
}
