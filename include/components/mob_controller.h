/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mob_controller
*/

#ifndef mob_CONTROLLER_H_
    #define mob_CONTROLLER_H_
    #include "ecs.h"
    #include "components/transform.h"
    #include "components/animator.h"
    #include "components/stats.h"

    typedef struct c_mob_controller_s {
        short is_active;
        short has_moved;
        c_transform_t *transform;
        c_animator_t *animator;
        c_stat_t *stats;
        sfCircleShape *circle;
        entity_t *target;
        void (*compute)(entity_t *, struct c_mob_controller_s *, rpg_t *);
        v2f offset;
        v2i direction;
    } c_mob_controller_t;

    typedef struct ai_parser_s {
        char *name;
        void (*compute)(entity_t *, struct c_mob_controller_s *, rpg_t *);
    } ai_parser_t;

c_mob_controller_t *create_mob_controller(c_transform_t *transform,
c_animator_t *animator, c_stat_t *stats);
component_t *create_mob_controller_comp(c_transform_t *transform,
c_animator_t *animator, c_stat_t *stats);
void destroy_mob_controller(void *data);
void print_mob_controller(void *data);
void update_mob_controller(void *data, entity_t *entity, rpg_t *rpg);

void set_mob_controller_ai(c_mob_controller_t *mob_controller,
const char *str);
void compute_stand(entity_t *entity,c_mob_controller_t *mob_controller,
rpg_t *rpg, const char *str);
void move_mob_transform(c_mob_controller_t *mob, float min, float max);
void set_mob_controller_animation(c_mob_controller_t *mob);
void attack_mob_controller(c_mob_controller_t *mob, entity_t *entity,
int damage);

// ai
void compute_stand_attack(entity_t *entity,
c_mob_controller_t *mob_controller, rpg_t *rpg);
void compute_stand_follow(entity_t *entity,
c_mob_controller_t *mob_controller, rpg_t *rpg);
void compute_attack(entity_t *entity,
c_mob_controller_t *mob_controller, rpg_t *rpg);
void compute_follow(entity_t *entity,
c_mob_controller_t *mob, rpg_t *rpg);

#endif /* !mob_CONTROLLER_H_ */
