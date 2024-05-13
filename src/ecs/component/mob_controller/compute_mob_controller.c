/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** compute_mob_controller
*/

#include <math.h>
#include "components/mob_controller.h"
#include "components/collider.h"
#include "components/controller.h"
#include "components/tag.h"
#include "banks.h"
#include "my.h"

void compute_attack(entity_t *entity,
c_mob_controller_t *mob, rpg_t *rpg)
{
    float radius = 0;
    float dist = 0;
    c_transform_t *target = NULL;
    c_controller_t *target_controller = NULL;
    int damage = 0;

    UNUSED(entity);
    UNUSED(rpg);
    if ((damage = get_stat(mob->stats, ST_ATK)) == -1)
        damage = 1;
    target_controller = get_component(mob->target->component, C_CONTROLLER);
    if ((target = get_component(mob->target->component, C_TRANSFORM)) == NULL)
        return;
    dist = VEC_DIST(mob->transform->pos, target_controller->transform->pos);
    radius = sfCircleShape_getRadius(mob->circle);
    if (ABS(dist) < 100 && target_controller)
        attack_controller(target_controller, damage, rpg);
    move_mob_transform(mob, radius / 3, radius);
}

void compute_follow(entity_t *entity,
c_mob_controller_t *mob, rpg_t *rpg)
{
    float radius = 0;

    UNUSED(entity);
    UNUSED(rpg);
    radius = sfCircleShape_getRadius(mob->circle);
    move_mob_transform(mob, radius / 3, -1);
}

void compute_stand_attack(entity_t *entity,
c_mob_controller_t *mob_controller, rpg_t *rpg)
{
    compute_stand(entity, mob_controller, rpg, "attack");
}

void compute_stand_follow(entity_t *entity,
c_mob_controller_t *mob_controller, rpg_t *rpg)
{
    compute_stand(entity, mob_controller, rpg, "follow");
}

void compute_stand(entity_t *entity,c_mob_controller_t *mob_controller,
rpg_t *rpg, const char *str)
{
    sfCircleShape *circle = mob_controller->circle;
    v2f rect_pos = {0, 0};
    float radius = 0;
    c_collider_t *collider = NULL;
    v2f pos = {0};

    pos = sfCircleShape_getPosition(circle);
    radius = sfCircleShape_getRadius(circle);
    collider = get_component(entity->component, C_COLLIDER);
    for (box_bank_t *curr = rpg->box_bank; curr; curr = curr->next) {
        if (collider && curr->collider == collider)
            continue;
        rect_pos = sfRectangleShape_getPosition(curr->collider->box);
        if (VEC_DIST(rect_pos, pos) > radius
        && entity_has_tag(curr->entity, "Player")) {
            set_mob_controller_ai(mob_controller, str);
            mob_controller->target = curr->entity;
        }
    }
}
