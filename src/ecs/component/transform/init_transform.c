/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_transform
*/

#include <stdlib.h>
#include "components/transform.h"
#include "ecs.h"

c_transform_t *create_transform(v2f pos, v2f scale, float rotation,
int follow_cam)
{
    c_transform_t *transform = NULL;

    transform = malloc(sizeof(c_transform_t));
    if (!transform) {
        return NULL;
    }
    transform->follow_cam = follow_cam;
    transform->pos = pos;
    transform->scale = scale;
    transform->rot = rotation;
    return transform;
}

component_t *create_transform_comp(v2f pos, v2f scale, float rotation,
int follow_cam)
{
    c_transform_t *trans = NULL;
    component_t *comp = NULL;

    if ((trans = create_transform(pos, scale, rotation, follow_cam)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_TRANSFORM, trans)) == NULL) {
        destroy_transform(trans);
        return NULL;
    }
    comp->destroy = &destroy_transform;
    comp->print = &print_transform;
    return comp;
}

void destroy_transform(void *data)
{
    free(data);
}
