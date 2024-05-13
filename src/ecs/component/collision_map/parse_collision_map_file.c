/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_collision_map_file
*/

#include <stdlib.h>
#include "components/collision_map.h"
#include "my.h"
#include "types/s_types.h"

static int add_new_collider(entity_t *map_entity, c_collision_map_t *coll_map,
rpg_t *rpg, v2f **opt)
{
    c_collider_t *coll = NULL;
    v2f pos = *(opt[0]);
    v2f size = *(opt[1]);

    if ((coll = create_collider(map_entity, rpg, size, pos)) == NULL) {
        return -1;
    }
    coll->is_static = 1;
    if (add_collider_to_map(coll_map, coll) == -1) {
        destroy_collider(coll);
        return -1;
    }
    return 0;
}

static int check_map(char *str)
{
    if (!str) {
        my_fprintf(2, "ERROR: invalid collision map (null)\n");
        return -1;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i + 1] == '\0' && str[i] != '\n') {
            my_fprintf(2, "ERROR: invalid collision map (\\n)\n");
            free(str);
            return -1;
        }
        if (C_IN_STR(str[i], " #\n") == 0) {
            my_fprintf(2, "ERROR: invalid collision map (wrong char)\n");
            free(str);
            return -1;
        }
    }
    return 0;
}

static int handle_parsing(char curr, char prev, v2f *pos, v2f *size)
{
    if (curr == '#' && prev == ' ')
        *size = SPRITE_SIZE;
    if (curr == '#' && prev == '#')
        size->x += SPRITE_SIZE.x;
    if ((curr == ' ' || curr == '\n') && (prev == ' ' || prev == '\n'))
        pos->x += SPRITE_SIZE.x;
    if ((curr == ' ' || curr == '\n') && prev == '#')
        return 1;
    return 0;
}

static void handle_status(short status, char curr, v2f *pos, v2f *size)
{
    if (status) {
        pos->x += (size->x + SPRITE_SIZE.x) * SPRITE_SCALE.x;
        size->x = SPRITE_SIZE.x;
    }
    if (curr == '\n') {
        pos->y += SPRITE_SIZE.y * SPRITE_SCALE.y;
        pos->x = 0;
        *size = SPRITE_SIZE;
    }
}

int parse_collision_file(entity_t *map_entity, c_collision_map_t *coll_map,
const char *filepath, rpg_t *rpg)
{
    char *str = NULL;
    v2f pos = {0, 0};
    v2f size = SPRITE_SIZE;
    v2f *opt[2] = {&pos, &size};
    char prev = ' ';
    short status = 0;

    if ((str = my_readfile(filepath)) == NULL)
        return -1;
    if (check_map(str) == -1)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {
        status = handle_parsing(str[i], prev, &pos, &size);
        if (status && add_new_collider(map_entity, coll_map, rpg, opt) == -1)
            return -1;
        handle_status(status, str[i], &pos, &size);
        prev = str[i];
    }
    free(str);
    return 0;
}
