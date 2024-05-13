/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_controller
*/

#include <stdlib.h>
#include "components/controller.h"

static int init_clocks(c_controller_t *controller)
{
    if ((controller->i_clock = sfClock_create()) == NULL) {
        return -1;
    }
    if ((controller->f_clock = sfClock_create()) == NULL) {
        sfClock_destroy(controller->i_clock);
        return -1;
    }
    if ((controller->a_clock = sfClock_create()) == NULL) {
        sfClock_destroy(controller->i_clock);
        sfClock_destroy(controller->f_clock);
        return -1;
    }
    return 0;
}

c_controller_t *create_controller(c_transform_t *transform,
c_animator_t *animator, c_stat_t *stats, int is_active)
{
    c_controller_t *controller = NULL;

    if (!transform || !animator || !stats) {
        return NULL;
    }
    if ((controller = malloc(sizeof(c_controller_t))) == NULL) {
        return NULL;
    }
    if (init_clocks(controller) == -1) {
        free(controller);
        return NULL;
    }
    controller->is_active = is_active;
    controller->animator = animator;
    controller->stats = stats;
    controller->transform = transform;
    controller->direction = (v2i){0, 0};
    controller->is_invincible = 0;
    controller->hitbox = NULL;
    return controller;
}

component_t *create_controller_comp(c_transform_t *transform,
c_animator_t *animator, c_stat_t *stat, int is_active)
{
    c_controller_t *controller = NULL;
    component_t *component = NULL;

    controller = create_controller(transform, animator, stat, is_active);
    if (controller == NULL) {
        return NULL;
    }
    if ((component = create_component(C_CONTROLLER, controller)) == NULL) {
        destroy_controller(controller);
        return NULL;
    }
    component->destroy = &destroy_controller;
    component->print = &print_controller;
    component->update = &update_controller;
    return component;
}

void destroy_controller(void *data)
{
    c_controller_t *controller = (c_controller_t *)data;

    if (!controller)
        return;
    sfClock_destroy(controller->a_clock);
    sfClock_destroy(controller->f_clock);
    sfClock_destroy(controller->i_clock);
    free(data);
}
