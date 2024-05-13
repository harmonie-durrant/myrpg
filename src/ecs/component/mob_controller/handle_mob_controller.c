/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_mob_controller
*/

#include <math.h>
#include "components/tag.h"
#include "components/mob_controller.h"
#include "components/collider.h"
#include "my.h"

void attack_mob_controller(c_mob_controller_t *mob, entity_t *entity,
int damage)
{
    int hp = 0;
    c_collider_t *coll = NULL;

    hp = get_stat(mob->stats, ST_HP);
    hp -= damage;
    if (hp <= 0) {
        if ((coll = get_component(entity->component, C_COLLIDER)) != NULL)
            coll->is_active = 0;
        mob->is_active = 0;
        mob->animator->sprite->is_active = 0;
        return;
    }
    set_stat(mob->stats, ST_HP, hp - damage);
}

void print_mob_controller(void *data)
{
    c_mob_controller_t *mob_controller = (c_mob_controller_t *)data;

    my_fprintf(2, "[MOB CONTROLLER]: %p\n", data);
    if (!data) {
        return;
    }
    my_fprintf(2, "stats: %p\n", mob_controller->stats);
    my_fprintf(2, "transform: %p\n", mob_controller->transform);
    my_fprintf(2, "animator: %p\n", mob_controller->animator);
    my_fprintf(2, "circle: %p\n", mob_controller->circle);
    my_fprintf(2, "is active: %s\n",
    mob_controller->is_active ? "yes" : "no");
    my_fprintf(2, "direction: (%d,%d)\n",
    mob_controller->direction.x, mob_controller->direction.y);
}

void set_mob_controller_animation(c_mob_controller_t *mob)
{
    if (mob->direction.x > 0) {
        set_animation(mob->animator, mob->has_moved ? 3 : 1);
    }
    if (mob->direction.x < 0) {
        set_animation(mob->animator, mob->has_moved ? 2 : 0);
    }
}

static v2i get_v2i_direction(v2f dir)
{
    v2i direction = {0, 0};

    if (dir.x != 0)
        direction.x = dir.x < 0 ? -1 : 1;
    if (dir.y != 0)
        direction.y = dir.y < 0 ? -1 : 1;
    return direction;
}

void move_mob_transform(c_mob_controller_t *mob, float min, float max)
{
    c_transform_t *trans = mob->transform;
    c_transform_t *target_trans = NULL;
    v2f direction = {0, 0};
    float speed = 0;

    mob->has_moved = 0;
    if (!(target_trans = get_component(mob->target->component, C_TRANSFORM)))
        return;
    if (max > 0 && VEC_DIST(trans->pos, target_trans->pos) > max)
        return;
    if (VEC_DIST(trans->pos, target_trans->pos) < min)
        return;
    speed = get_stat(mob->stats, ST_SPD);
    if (speed < 0)
        speed = 1;
    direction = get_direction_from_vec(trans->pos, target_trans->pos);
    mob->has_moved = move_transform(trans, VEC_MULT_F(direction, speed)) == 0;
    mob->direction = get_v2i_direction(direction);
}
