/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** collision_map
*/

#ifndef COLLISION_MAP_H_
    #define COLLISION_MAP_H_

    #include "ecs.h"
    #include "components/collider.h"

    typedef struct map_collider_s {
        c_collider_t *collider;
        struct map_collider_s *next;
    } map_collider_t;

    typedef struct c_collision_map_s {
        map_collider_t *colliders;
    } c_collision_map_t;

c_collision_map_t *create_collision_map(void);
component_t *create_collision_map_comp(void);
map_collider_t *create_map_collider(c_collider_t *collider);
void destroy_collision_map(void *data);
void destroy_map_colliders(map_collider_t *colliders);
void print_collision_map(void *data);
void print_map_colliders(map_collider_t *colliders);
void update_collision_map(void *data, entity_t *entity, rpg_t *rpg);

int add_collider_to_map(c_collision_map_t *map, c_collider_t *colliders);
int parse_collision_file(entity_t *map_entity, c_collision_map_t *coll_map,
const char *filepath, rpg_t *rpg);

#endif /* !COLLISION_MAP_H_ */
