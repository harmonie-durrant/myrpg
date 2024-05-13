/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_cam_controller
*/

#include "scene_parser.h"
#include "components/cam_controller.h"
#include "rpg.h"

static int parse_data(c_cam_controller_t *cam, char **data, entity_t *entity)
{
    char *tmp = NULL;
    c_transform_t *transform = NULL;

    if ((tmp = get_data_arg(data, "speed:")))
        cam->speed = parse_float(tmp);
    if ((tmp = get_data_arg(data, "is_active:")))
        cam->is_active = parse_int(tmp) != 0;
    if ((tmp = get_data_arg(data, "target_pos:"))) {
        cam->mode = CM_GO_TO;
        cam->target_pos = parse_v2f(tmp);
    } else if ((transform = get_component(entity->component, C_TRANSFORM))) {
        cam->mode = CM_FOLLOW;
        cam->target_transform = transform;
    } else {
        return -1;
    }
    return 0;
}

component_t *parse_cam_controller_comp(entity_t *entity,
char **data, rpg_t *rpg)
{
    component_t *comp = NULL;

    if ((comp = create_cam_controller_comp(rpg->win->view)) == NULL) {
        return NULL;
    }
    if (parse_data(comp->data, data, entity) == -1) {
        destroy_component(comp);
        return NULL;
    }
    return comp;
}
