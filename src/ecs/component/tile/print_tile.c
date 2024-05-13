/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** print_tile
*/

#include "components/tiles.h"
#include "my.h"

static void print_tile_list(tile_t *head)
{
    if (head == NULL) {
        return;
    }
    my_printf("pos: (%d, %d)\t", (int)head->pos.x, (int)head->pos.y);
    my_printf("sprite_pos: (%d, %d)", head->sprite_pos.x, head->sprite_pos.y);
    my_printf("\tis_collidable: %d\n", head->is_collidable);
    print_tile_list(head->next);
}

void print_tile_map(void *data)
{
    c_tile_map_t *tilemap = (c_tile_map_t *)data;

    my_printf("TILEMAP: %p\n", tilemap);
    my_printf("sprite: %p\n", tilemap->sprite);
    print_tile_list(tilemap->tiles);
}
