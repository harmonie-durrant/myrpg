/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_collider
*/

#include <stdlib.h>
#include "rpg.h"
#include "components/collider.h"
#include "components/transform.h"
#include "components/ui_button.h"
#include "my.h"

static void parse_data(c_collider_t *coll, char **data)
{
    char *tmp = NULL;

    if ((tmp = get_data_arg(data, "trigger:")) != NULL) {
        if ((tmp = parse_str(tmp)) != NULL) {
            set_collider_trigger(coll, get_callback_from_str(tmp).callback);
            free(tmp);
        }
    }
    if ((tmp = get_data_arg(data, "trigger_val:")) != NULL) {
        coll->trigger_val = parse_int(tmp);
    }
    if ((tmp = get_data_arg(data, "static:")) != NULL) {
        coll->is_static = parse_int(tmp) != 0;
    }
    if ((tmp = get_data_arg(data, "offset:")) != NULL) {
        coll->offset = parse_v2f(tmp);
    }
    if ((tmp = get_data_arg(data, "trigger_vec:")) != NULL) {
        coll->trigger_vec = parse_v2f(tmp);
    }
}

component_t *parse_collider_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    component_t *comp = NULL;
    c_transform_t *trans = NULL;
    c_collider_t *coll = NULL;
    v2f size = {0, 0};
    v2f pos = {0, 0};
    char *tmp = NULL;

    if ((trans = get_component(entity->component, C_TRANSFORM)) == NULL)
        return NULL;
    pos = trans->pos;
    if ((tmp = get_data_arg(data, "size:")) != NULL) {
        size = parse_v2f(tmp);
    }
    if ((comp = create_collider_comp(entity, rpg, size, pos)) == NULL) {
        return NULL;
    }
    coll = comp->data;
    parse_data(coll, data);
    sfRectangleShape_setPosition(coll->box, VEC_ADD(pos, coll->offset));
    return comp;
}
