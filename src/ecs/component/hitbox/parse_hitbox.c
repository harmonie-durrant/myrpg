/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_hitbox
*/

#include "components/hitbox.h"
#include "scene_parser.h"
#include "rpg.h"
#include "my.h"

component_t *parse_hitbox_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    v2f offset = {0, 0};
    v2f size = {1, 1};
    char *tmp = NULL;

    UNUSED(data);
    UNUSED(rpg);
    UNUSED(entity);
    if ((tmp = get_data_arg(data, "offset:")) != NULL) {
        offset = parse_v2f(tmp);
    }
    if ((tmp = get_data_arg(data, "size:")) != NULL) {
        size = parse_v2f(tmp);
    }
    return create_hitbox_comp(offset, size);
}
