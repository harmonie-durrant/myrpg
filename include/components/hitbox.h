/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** hitbox
*/

#ifndef HITBOX_H_
    #define HITBOX_H_

    #include "ecs.h"

    typedef struct c_hitbox_s {
        short is_active;
        sfRectangleShape *box;
        int flip;
        v2f offset;
    } c_hitbox_t;

c_hitbox_t *create_hitbox(v2f offset, v2f size);
component_t *create_hitbox_comp(v2f offset, v2f size);
void destroy_hitbox(void *data);
void print_hitbox(void *data);
void update_hitbox(void *data, entity_t *entity, rpg_t *rpg);

#endif /* !HITBOX_H_ */
