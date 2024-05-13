/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** vector_interpolation
*/

#include "window.h"
#include "my.h"

v2f get_next_interpolation(v2f a, v2f b, float speed)
{
    float x1 = a.x;
    float y1 = a.y;
    float x2 = b.x;
    float y2 = b.y;
    float distance = 0;
    v2f unit_vector = {0, 0};

    distance = my_compute_power_rec(x2 - x1, 2);
    distance += my_compute_power_rec(y2 - y1, 2);
    distance = my_compute_square_root(distance);
    if (distance < speed)
        return b;
    unit_vector = (v2f){(x2 - x1) / distance, (y2 - y1) / distance};
    return (v2f){x1 + speed * unit_vector.x, y1 + speed * unit_vector.y};
}
