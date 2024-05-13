/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_collision_map
*/

#include "components/collision_map.h"
#include "my.h"

void print_collision_map(void *data)
{
    c_collision_map_t *map = (c_collision_map_t *)data;
    map_collider_t *colliders = NULL;

    my_fprintf(2, "[COLLISION MAP]: %p\n", map);
    if (map) {
        colliders = map->colliders;
        my_fprintf(2, "colliders: %s", colliders ? "\n" : "no colliders\n");
        print_map_colliders(colliders);
    }
}

void print_map_colliders(map_collider_t *colliders)
{
    if (!colliders) {
        return;
    }
    print_collider(colliders->collider);
    print_map_colliders(colliders->next);
}

int add_collider_to_map(c_collision_map_t *map, c_collider_t *collider)
{
    map_collider_t *map_coll = NULL;

    if (!map || !collider) {
        return -1;
    }
    if ((map_coll = create_map_collider(collider)) == NULL) {
        return -1;
    }
    if (map->colliders != NULL) {
        map_coll->next = map->colliders;
    }
    map->colliders = map_coll;
    return 0;
}

void update_collision_map(void *data, entity_t *entity, rpg_t *rpg)
{
    c_collision_map_t *coll_map = (c_collision_map_t *)data;
    map_collider_t *curr = NULL;
    if (!coll_map) {
        return;
    }
    for (curr = coll_map->colliders; curr; curr = curr->next) {
        update_collider(curr->collider, entity, rpg);
    }
}
