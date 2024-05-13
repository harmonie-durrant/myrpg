/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** is_active
*/

#ifndef IS_ACTIVE_H_
    #define IS_ACTIVE_H_
    #include "ecs.h"
    #include "rpg.h"

    typedef struct c_is_active_s {
        int val;
    } c_is_active_t;

component_t *create_is_active_comp(int val);
void destroy_is_active(void *data);
void print_is_active(void *data);

void set_active(int active, entity_t *entity);
int is_active(entity_t *entity);

#endif /* !IS_ACTIVE_H_ */
