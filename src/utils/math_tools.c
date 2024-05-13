/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** math_tools
*/

#include <math.h>
#include "window.h"
#include "my.h"

float get_vector_abs_dist(v2f vec1, v2f vec2)
{
    v2f abs1 = {ABS(vec1.x), ABS(vec1.y)};
    v2f abs2 = {ABS(vec2.x), ABS(vec2.y)};

    return VEC_DIST(abs1, abs2);
}

v2f normalize_vector(v2f vec)
{
    float magnitude = 0;

    magnitude = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    return (v2f){vec.x / magnitude, vec.y / magnitude};
}

v2f get_direction_from_vec(v2f vec1, v2f vec2)
{
    return normalize_vector((v2f){vec2.x - vec1.x, vec2.y - vec1.y});
}

float get_distance_from_circle(sfCircleShape *circle, v2f pos)
{
    v2f circle_pos = {0, 0};
    float radius = 0;
    v2f center = {0, 0};
    float distance = 0;

    if (!circle) {
        return 0;
    }
    circle_pos = sfCircleShape_getPosition(circle);
    radius = sfCircleShape_getRadius(circle);
    center = (v2f){circle_pos.x + radius, circle_pos.y + radius};
    distance = VEC_DIST(pos, center);
    return distance;
}

int check_rect_collide(sfRectangleShape *shape1, sfRectangleShape *shape2)
{
    sfFloatRect rect1 = {0};
    sfFloatRect rect2 = {0};

    rect1 = sfRectangleShape_getGlobalBounds(shape1);
    rect2 = sfRectangleShape_getGlobalBounds(shape2);

    return sfFloatRect_intersects(&rect1, &rect2, NULL);
}
