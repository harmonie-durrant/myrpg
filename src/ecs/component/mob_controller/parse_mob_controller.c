/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_mob_controller
*/

#include <stdlib.h>
#include "scene_parser.h"
#include "components/mob_controller.h"
#include "my.h"

static void parse_data(c_mob_controller_t *mob_controller, char **data)
{
    char *tmp = NULL;
    char *ai_str = NULL;

    if ((tmp = get_data_arg(data, "ai:")) != NULL) {
        if ((ai_str = parse_str(tmp)) != NULL) {
            set_mob_controller_ai(mob_controller, ai_str);
            free(ai_str);
        }
    }
    if ((tmp = get_data_arg(data, "radius:")) != NULL)
        sfCircleShape_setRadius(mob_controller->circle, parse_float(tmp));
    if ((tmp = get_data_arg(data, "offset:")) != NULL)
        mob_controller->offset = parse_v2f(tmp);
}

component_t *parse_mob_controller_comp(entity_t *entity,
char **data, rpg_t *rpg)
{
    component_t *comp = NULL;
    c_animator_t *anim = NULL;
    c_transform_t *trans = NULL;
    c_stat_t *stats = NULL;

    UNUSED(rpg);
    if ((stats = get_component(entity->component, C_STATS)) == NULL)
        return NULL;
    if ((anim = get_component(entity->component, C_ANIMATOR)) == NULL)
        return NULL;
    if ((trans = get_component(entity->component, C_TRANSFORM)) == NULL)
        return NULL;
    if ((comp = create_mob_controller_comp(trans, anim, stats)) == NULL)
        return NULL;
    parse_data(comp->data, data);
    return comp;
}
