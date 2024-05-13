/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_controller
*/

#include "components/controller.h"
#include "scene_parser.h"
#include "rpg.h"
#include "my.h"

static int parse_data(component_t *comp, entity_t *entity, char **data)
{
    char *tmp = NULL;
    c_controller_t *controller = comp->data;
    c_hitbox_t *hitbox = NULL;

    if ((tmp = get_data_arg(data, "is_active:")) != NULL)
        controller->is_active = parse_int(tmp) != 0;
    if ((hitbox = get_component(entity->component, C_HITBOX)) == NULL) {
        destroy_component(comp);
        return -1;
    }
    controller->hitbox = hitbox;
    return 0;
}

component_t *parse_controller_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    c_animator_t *animator = NULL;
    c_transform_t *transform = NULL;
    component_t *comp = NULL;
    c_stat_t *stat = NULL;

    UNUSED(rpg);
    UNUSED(entity);

    if ((stat = get_component(entity->component, C_STATS)) == NULL)
        return NULL;
    if ((animator = get_component(entity->component, C_ANIMATOR)) == NULL)
        return NULL;
    if ((transform = get_component(entity->component, C_TRANSFORM)) == NULL)
        return NULL;
    comp = create_controller_comp(transform, animator, stat, 1);
    if (!comp || parse_data(comp, entity, data) == -1)
        return NULL;
    return comp;
}
