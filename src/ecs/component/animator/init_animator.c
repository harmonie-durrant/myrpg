/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_animator
*/

#include <stdlib.h>
#include "types/c_types.h"
#include "components/animator.h"
#include "window.h"

c_animator_t *create_animator(c_sprite_t *sprite)
{
    c_animator_t *animator = NULL;

    if ((animator = malloc(sizeof(c_animator_t))) == NULL) {
        return NULL;
    }
    animator->clock = sfClock_create();
    animator->sprite = sprite;
    animator->curr_animation = NULL;
    animator->animations = NULL;
    animator->curr_col = 0;
    return animator;
}

component_t *create_animator_comp(c_sprite_t *sprite)
{
    component_t *comp = NULL;
    c_animator_t *animator = NULL;

    if ((animator = create_animator(sprite)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_ANIMATOR, animator)) == NULL) {
        destroy_animator(animator);
        return NULL;
    }
    comp->print = &print_animator;
    comp->destroy = &destroy_animator;
    return comp;
}

animation_t *create_animation(int id, int line, int max_col)
{
    animation_t *animation = NULL;
    static int default_id = 0;

    if ((animation = malloc(sizeof(animation_t))) == NULL) {
        return NULL;
    }
    animation->id = id < 0 ? default_id++ : id;
    animation->line = line;
    animation->max_col = max_col;
    animation->next = NULL;
    return animation;
}

static void destroy_animations(animation_t *animation)
{
    if (animation == NULL) {
        return;
    }
    destroy_animations(animation->next);
    free(animation);
}

void destroy_animator(void *data)
{
    c_animator_t *animator = (c_animator_t*)data;

    sfClock_destroy(animator->clock);
    destroy_animations(animator->animations);
    free(animator);
}
