/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** cam_controller
*/

#ifndef CAM_CONTROLLER_H_
    #define CAM_CONTROLLER_H_

    #include "ecs.h"
    #include "components/transform.h"

    typedef enum cam_mode_e {
        CM_FOLLOW,
        CM_GO_TO
    } e_cam_mode;

    typedef struct c_cam_controller_s {
        short is_active;
        sfView *view;
        e_cam_mode mode;
        v2f target_pos;
        c_transform_t *target_transform;
        float speed;
    } c_cam_controller_t;

c_cam_controller_t *create_cam_controller(sfView *view);
component_t *create_cam_controller_comp(sfView *view);
void destroy_cam_controller(void *data);
void print_cam_controller(void *data);
void update_cam_controller(void *data, entity_t *entity, rpg_t *rpg);

int set_cam_target_transform(c_cam_controller_t *cam_controller,
c_transform_t *transform);
int set_cam_target_pos(c_cam_controller_t *cam_controller,
v2f pos);
void reset_cam(sfView *view);

#endif /* !CAM_CONTROLLER_H_ */
