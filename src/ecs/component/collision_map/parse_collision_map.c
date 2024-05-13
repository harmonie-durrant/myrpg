/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_collision_map
*/

#include "scene_parser.h"
#include "rpg.h"
#include "components/collision_map.h"

component_t *parse_collision_map_comp(entity_t *entity,
char **data, rpg_t *rpg)
{
    component_t *comp = NULL;
    c_collision_map_t *coll_map = NULL;
    char *tmp = NULL;
    char *filepath = NULL;

    if ((tmp = get_data_arg(data, "file:")) != NULL) {
        if ((filepath = parse_str(tmp)) == NULL) {
            return NULL;
        }
    }
    if ((comp = create_collision_map_comp()) == NULL) {
        return NULL;
    }
    coll_map = comp->data;
    if (parse_collision_file(entity, coll_map, filepath, rpg) == -1) {
        destroy_component(comp);
        return NULL;
    }
    return comp;
}
