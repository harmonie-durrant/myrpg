/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_inventoty
*/

#include "components/inventory.h"
#include "rpg.h"
#include "scene_parser.h"
#include "my.h"

component_t *parse_inventory_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    int size = 1;
    char *tmp = NULL;

    UNUSED(rpg);
    UNUSED(entity);
    if ((tmp = get_data_arg(data, "size:")) != NULL) {
        size = parse_int(tmp);
    }
    return create_inventory_comp(size);
}
