/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_mob_controller
*/

#include <stdlib.h>
#include "components/mob_controller.h"

c_mob_controller_t *create_mob_controller(c_transform_t *transform,
c_animator_t *animator, c_stat_t *stats)
{
    c_mob_controller_t *mob_controller = NULL;

    if (!transform || !animator || !stats)
        return NULL;
    if ((mob_controller = malloc(sizeof(c_mob_controller_t))) == NULL)
        return NULL;
    if ((mob_controller->circle = sfCircleShape_create()) == NULL)
        free(mob_controller);
    sfCircleShape_setFillColor(mob_controller->circle, DEBUG_BLUE);
    mob_controller->animator = animator;
    mob_controller->stats = stats;
    mob_controller->transform = transform;
    mob_controller->direction = (v2i){0, 0};
    mob_controller->offset = (v2f){0, 0};
    mob_controller->compute = NULL;
    mob_controller->target = NULL;
    mob_controller->is_active = 1;
    mob_controller->has_moved = 0;
    return mob_controller;
}

component_t *create_mob_controller_comp(c_transform_t *transform,
c_animator_t *animator, c_stat_t *stats)
{
    component_t *comp = NULL;
    c_mob_controller_t *mob_controller = NULL;

    mob_controller = create_mob_controller(transform, animator, stats);
    if (mob_controller == NULL) {
        return NULL;
    }
    comp = create_component(C_MOB_CONTROLLER, mob_controller);
    if (comp == NULL) {
        destroy_mob_controller(mob_controller);
        return NULL;
    }
    comp->destroy = &destroy_mob_controller;
    comp->print = &print_mob_controller;
    comp->update = &update_mob_controller;
    return comp;
}

void destroy_mob_controller(void *data)
{
    c_mob_controller_t *mob_controller = (c_mob_controller_t *)data;

    if (!data) {
        return;
    }
    sfCircleShape_destroy(mob_controller->circle);
    free(mob_controller);
}
