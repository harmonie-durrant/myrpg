/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_animator
*/

#include "components/animator.h"
#include "my.h"

int append_animation(animation_t **head, animation_t *animation)
{
    if (head == NULL) {
        return -1;
    }
    if (*head != NULL) {
        animation->next = *head;
    }
    *head = animation;
    return 0;
}

int add_animation(c_animator_t *animator, int id, int line, int max_col)
{
    animation_t *animation = NULL;

    if (animator == NULL) {
        return -1;
    }
    if ((animation = create_animation(id, line, max_col)) == NULL) {
        return -1;
    }
    if (animator->curr_animation == NULL) {
        animator->curr_animation = animation;
    }
    append_animation(&(animator->animations), animation);
    return 0;
}

int set_animation(c_animator_t *animator, int index)
{
    animation_t *animation = NULL;
    animation_t *tmp = NULL;

    if (animator == NULL)
        return -1;
    if (animator->curr_animation->id == index)
        return 0;
    animator->sprite->rect.left = 0;
    animator->curr_col = 0;
    animation = animator->animations;
    while (animation && animation->id != index) {
        tmp = animation;
        animation = animation->next;
    }
    if (animation) {
        animator->curr_animation = animation;
        return 0;
    }
    animator->curr_animation = tmp;
    return -1;
}

void play_animation(c_animator_t *animator)
{
    sfClock *clock = NULL;
    animation_t *anim = NULL;

    if (animator == NULL)
        return;
    clock = animator->clock;
    anim = animator->curr_animation;
    set_sprite_line(animator->sprite, animator->curr_animation->line);
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < ANIM_SEC)
        return;
    move_sprite_col(animator->sprite);
    animator->curr_col++;
    if (animator->curr_col > anim->max_col)
        animator->sprite->rect.left = 0;
    if (animator->sprite->rect.left == 0)
        animator->curr_col = 0;
    sfClock_restart(clock);
}

void print_animator(void *data)
{
    c_animator_t *animator = (c_animator_t *)data;

    if (!data) {
        return;
    }
    my_printf("[ANIMATOR]: %p\nanimations:\n", animator);
    for (animation_t *tmp = animator->animations; tmp; tmp = tmp->next) {
        my_printf("- id: %d | line: %d | frames: %d\n", tmp->id,
        tmp->line, tmp->max_col);
    }
    my_printf("\nsprite: %p\nclock: %p\n", animator->sprite, animator->clock);
    my_printf("current animation: line %d - frames %d\n",
    animator->curr_animation->line, animator->curr_animation->max_col);
    my_printf("current frame: %d\n", animator->curr_col);
}
