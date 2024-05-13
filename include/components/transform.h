/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** transform
*/

#ifndef C_TRANSFORM_H_
    #define C_TRANSFORM_H_
    #include "window.h"
    #include "ecs.h"
    #include "rpg.h"

    typedef struct c_transform_s {
        int follow_cam;
        sfVector2f pos;
        sfVector2f scale;
        float rot;
    } c_transform_t;

c_transform_t *create_transform(v2f pos, v2f scale, float rotation,
int follow_cam);
component_t *create_transform_comp(v2f pos, v2f scale, float rotation,
int follow_cam);
void destroy_transform(void *data);
void print_transform(void *data);

v2f getfollow_pos(c_transform_t *trans, rpg_t *rpg);

int move_transform(c_transform_t *transform, sfVector2f move);
int rotate_transform(c_transform_t *transform, float angle);

#endif /* !C_TRANSFORM_H_ */
