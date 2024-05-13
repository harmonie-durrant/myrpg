/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** magic
*/

#include "ecs.h"

#ifndef C_MAGIC_H_
    #define C_MAGIC_H_

    typedef enum spell {
        SP_HEAL,
        SP_FIRE_BALL,
        SP_SHIELD,
        SP_NONE,
    }e_spell;

    typedef struct c_magic_s {
        e_spell spell;
    } c_magic_t;

c_magic_t *create_magic(e_spell spell);
component_t *create_magic_comp(e_spell spell);
void destroy_magic(void *data);
void print_magic(void* data);

#endif /* !C_MAGIC_H_ */
