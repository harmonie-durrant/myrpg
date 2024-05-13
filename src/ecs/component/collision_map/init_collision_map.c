/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_collision_map
*/

#include <stdlib.h>
#include "components/collision_map.h"

c_collision_map_t *create_collision_map(void)
{
    c_collision_map_t *map = NULL;

    if ((map = malloc(sizeof(c_collision_map_t))) == NULL) {
        return NULL;
    }
    map->colliders = NULL;
    return map;
}

component_t *create_collision_map_comp(void)
{
    component_t *comp = NULL;
    c_collision_map_t *map = NULL;

    if ((map = create_collision_map()) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_COLLISION_MAP, map)) == NULL) {
        destroy_collision_map(map);
        return NULL;
    }
    comp->destroy = &destroy_collision_map;
    comp->print = &print_collision_map;
    comp->update = &update_collision_map;
    return comp;
}

map_collider_t *create_map_collider(c_collider_t *collider)
{
    map_collider_t *map_collider = NULL;

    if ((map_collider = malloc(sizeof(map_collider_t))) == NULL) {
        return NULL;
    }
    map_collider->collider = collider;
    map_collider->next = NULL;
    return map_collider;
}

void destroy_map_colliders(map_collider_t *colliders)
{
    if (!colliders) {
        return;
    }
    destroy_map_colliders(colliders->next);
    destroy_collider(colliders->collider);
    free(colliders);
}

void destroy_collision_map(void *data)
{
    c_collision_map_t *map = (c_collision_map_t *)data;

    if (!data) {
        return;
    }
    destroy_map_colliders(map->colliders);
    free(map);
}
