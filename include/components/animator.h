/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** animator
*/

#ifndef ANIMATOR_H_
    #define ANIMATOR_H_

    #include "components/sprite.h"
    #include "window.h"
    #include "ecs.h"

    #define ANIM_SEC 0.2

    typedef struct animation_s {
        int id;
        int line;
        int max_col;
        struct animation_s *next;
    } animation_t;

    typedef struct c_animator_s {
        sfClock *clock;
        c_sprite_t *sprite;
        animation_t *curr_animation;
        animation_t *animations;
        int curr_col;
    } c_animator_t;

c_animator_t *create_animator(c_sprite_t *sprite);
component_t *create_animator_comp(c_sprite_t *sprite);
animation_t *create_animation(int id, int line, int max_col);
void print_animator(void *data);
void destroy_animator(void *data);

int append_animation(animation_t **head, animation_t *animation);
int add_animation(c_animator_t *animator, int id, int line, int max_col);
int set_animation(c_animator_t *animator, int index);
void play_animation(c_animator_t *animator);

#endif /* !ANIMATOR_H_ */
