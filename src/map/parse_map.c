/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_map
*/

#include <stdlib.h>
#include "map_parser.h"
#include "my.h"

static int init_parsing(char **str, component_t **tilemap_comp,
char *filename, c_sprite_t *sprite)
{
    if ((*str = my_readfile(filename)) == NULL) {
        return -1;
    }
    if ((*tilemap_comp = create_tile_map_comp(sprite)) == NULL) {
        free(str);
        return -1;
    }
    return 0;
}

static int add_sprite_char(c_tile_map_t *tilemap, v2f pos, sprite_char_t sc)
{
    v2f curr_pos = pos;
    v2i curr_s_pos = sc.pos;
    int status = 0;
    v2i offset = tilemap->sprite->offset;
    v2f scale = SPRITE_SCALE;

    for (int y = 0; y < sc.size.y; y++) {
        for (int x = 0; x < sc.size.x; x++) {
            curr_s_pos.x = sc.pos.x + x;
            curr_s_pos.y = sc.pos.y + y;
            curr_pos.x = pos.x + ((offset.x * x) * scale.x);
            curr_pos.y = pos.y + ((offset.y * y) * scale.y);
            status += add_tile(tilemap, curr_pos, curr_s_pos, 0);
        }
    }
    return status != 0 ? -1 : 0;
}

static int scan_char(c_tile_map_t *tilemap, char c,
sprite_char_t *sprite_chars, v2f current_pos)
{
    for (int i = 0; sprite_chars[i].c != '\0'; i++) {
        if (sprite_chars[i].c == c) {
            return add_sprite_char(tilemap, current_pos, sprite_chars[i]);
        }
    }
    return -1;
}

int parse_tiles(c_tile_map_t *tilemap, char *str,
sprite_char_t *sprite_chars)
{
    v2f current_pos = {0, 0};
    int status = 0;
    v2i sprite_size = tilemap->sprite->offset;
    v2f scale = SPRITE_SCALE;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            status += scan_char(tilemap, str[i], sprite_chars, current_pos);
        }
        if (str[i] == '\n') {
            current_pos.y += sprite_size.y * scale.y;
            current_pos.x = 0;
            continue;
        }
        current_pos.x += sprite_size.x * scale.x;
    }
    return status == 0 ? 0 : -1;
}

component_t *parse_map(c_sprite_t *sprite, char *filename, int layer)
{
    char *str = NULL;
    component_t *tilemap_comp = NULL;
    int parsing_status = 0;

    if (init_parsing(&str, &tilemap_comp, filename, sprite) == -1) {
        return NULL;
    }
    parsing_status = handle_layer_parsing(tilemap_comp->data, str, layer);
    free(str);
    if (parsing_status == -1) {
        return NULL;
    }
    return tilemap_comp;
}
