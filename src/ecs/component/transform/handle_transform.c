/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** get_transform
*/

#include <unistd.h>
#include <stdlib.h>
#include "components/transform.h"
#include "ecs.h"
#include "rpg.h"
#include "my.h"

int move_transform(c_transform_t *transform, v2f move)
{
    if (move.x == 0 && move.y == 0)
        return -1;
    transform->pos.x += move.x;
    transform->pos.y += move.y;
    return 0;
}

int rotate_transform(c_transform_t *transform, float angle)
{
    transform->rot += angle;
    return 0;
}

void print_transform(void *data)
{
    c_transform_t *trans = (c_transform_t*)data;

    my_fprintf(2, "[TRANSFORM]: %p\n", data);
    if (!data) {
        my_fprintf(2, "Transform is NULL\n");
    } else {
        my_fprintf(2, "position: (%f,%f)\n", trans->pos.x, trans->pos.y);
        my_fprintf(2, "scale: (%f,%f)\n", trans->scale.x, trans->scale.y);
        my_fprintf(2, "rotation: %f\n", trans->rot);
    }
}
