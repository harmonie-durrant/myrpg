/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_cam_controller
*/

#include <stdlib.h>
#include "components/cam_controller.h"

c_cam_controller_t *create_cam_controller(sfView *view)
{
    c_cam_controller_t *cam = NULL;

    if ((cam = malloc(sizeof(c_cam_controller_t))) == NULL) {
        return NULL;
    }
    cam->is_active = 1;
    cam->mode = CM_GO_TO;
    cam->speed = 1;
    cam->target_pos = (v2f){0, 0};
    cam->target_transform = NULL;
    cam->view = view;
    return cam;
}

component_t *create_cam_controller_comp(sfView *view)
{
    c_cam_controller_t *cam = NULL;
    component_t *comp = NULL;

    if ((cam = create_cam_controller(view)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_CAM_CONTROLLER, cam)) == NULL) {
        destroy_cam_controller(cam);
        return NULL;
    }
    comp->destroy = &destroy_cam_controller;
    comp->print = &print_cam_controller;
    comp->update = &update_cam_controller;
    return comp;
}

void destroy_cam_controller(void *data)
{
    free(data);
}
