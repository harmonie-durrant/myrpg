/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** controller
*/

#ifndef CONTROLLER_H_
    #define CONTROLLER_H_
    #include "ecs.h"
    #include "components/transform.h"
    #include "components/animator.h"
    #include "components/stats.h"
    #include "components/hitbox.h"
    #define INVINCIBILITY_S 4
    #define FLASH_S 0.3
    #define ATK_S 0.05

    typedef struct c_controller_s {
        short is_active;
        c_transform_t *transform;
        c_animator_t *animator;
        c_stat_t *stats;
        v2i direction;
        short is_invincible;
        short is_attacking;
        sfClock *i_clock;
        sfClock *f_clock;
        sfClock *a_clock;
        c_hitbox_t *hitbox;
    } c_controller_t;

c_controller_t *create_controller(c_transform_t *transform,
c_animator_t *animator, c_stat_t *stats, int is_active);
component_t *create_controller_comp(c_transform_t *transform,
c_animator_t *animator, c_stat_t *stats, int is_active);
void destroy_controller(void *data);
void print_controller(void *data);
void update_controller(void *data, entity_t *entity, rpg_t *rpg);

void attack_controller(c_controller_t *controller, int damage, rpg_t *rpg);
void set_dir_animation(c_controller_t *controller, c_animator_t *anim,
int has_moved, v2i *direction);
int handle_movement(c_controller_t *controller, c_transform_t *trans,
int speed, e_input input);
void handle_attack(c_controller_t *controller, e_input input);

#endif /* !CONTROLLER_H_ */
