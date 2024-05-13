/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_cam_controller
*/

#include "components/cam_controller.h"
#include "my.h"
#include "rpg.h"

void reset_cam(sfView *view)
{
    v2f size = {0, 0};

    size = sfView_getSize(view);
    sfView_setCenter(view, (v2f){size.x / 2, size.y / 2});
}

void print_cam_controller(void *data)
{
    c_cam_controller_t *cam = (c_cam_controller_t *)data;

    my_printf("[CAMERA CONTROLLER]: %p\n", cam);
    if (!cam) {
        return;
    }
    my_printf("is_active: %d\n", cam->is_active);
    my_printf("mode: %s\n", cam->mode == CM_GO_TO ? "GO_TO" : "FOLLOW");
    my_fprintf(2, "speed: %f\n", cam->speed);
    my_fprintf(1, "target_pos: (%f, %f)\n",
    cam->target_pos.x, cam->target_pos.y);
    my_printf("target_transform: %p\n", cam->target_transform);
    my_printf("view: %p\n", cam->view);
}

int set_cam_target_transform(c_cam_controller_t *cam_controller,
c_transform_t *transform)
{
    if (!cam_controller || !transform) {
        return -1;
    }
    cam_controller->mode = CM_FOLLOW;
    cam_controller->target_transform = transform;
    return 0;
}

int set_cam_target_pos(c_cam_controller_t *cam_controller,
v2f pos)
{
    if (!cam_controller) {
        return -1;
    }
    cam_controller->mode = CM_GO_TO;
    cam_controller->target_pos = pos;
    return 0;
}

void update_cam_controller(void *data, entity_t *entity, rpg_t *rpg)
{
    c_cam_controller_t *cam = (c_cam_controller_t *)data;
    v2f view_pos = {0, 0};
    v2f new = {0, 0};

    UNUSED(entity);
    UNUSED(rpg);
    if (!cam || !cam->is_active)
        return;
    if (cam->mode == CM_FOLLOW && cam->target_transform != NULL) {
        sfView_setCenter(cam->view, cam->target_transform->pos);
    }
    if (cam->mode == CM_GO_TO) {
        view_pos = sfView_getCenter(cam->view);
        new = get_next_interpolation(view_pos, cam->target_pos, cam->speed);
        my_fprintf(1, "new: (%f,%f)\n", new.x, new.y);
        sfView_setCenter(cam->view, new);
    }
}
