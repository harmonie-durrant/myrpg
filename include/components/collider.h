/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** box_collider
*/

#ifndef BOX_COLLIDER_H_
    #define BOX_COLLIDER_H_
    #define SHOW_COLLIDER 0

    #include "rpg.h"

    typedef struct c_collider_s {
        short is_active;
        sfRectangleShape *box;
        v2f offset;
        void *(*trigger)(entity_t *, rpg_t *, int);
        v2f trigger_vec;
        int trigger_val;
        int is_colliding;
        int is_static;
    } c_collider_t;

c_collider_t *create_collider(entity_t *entity, rpg_t *rpg,
v2f size, v2f pos);
component_t *create_collider_comp(entity_t *entity, rpg_t *rpg,
v2f scale, v2f pos);
void destroy_collider(void *data);
void print_collider(void *data);
void update_collider(void *data, entity_t *entity, rpg_t *rpg);

void print_collision(entity_t *entity1, entity_t *entity2);
int set_collider_trigger(c_collider_t *collider,
void *(*trigger)(entity_t *, rpg_t *, int));
int handle_collision(entity_t *entity, c_collider_t *coll1,
c_collider_t *coll2, rpg_t *rpg);
c_collider_t *get_collision(sfRectangleShape *box,
box_bank_t *box_bank, sfView *view);
sfBool box_is_in_screen(sfRectangleShape *box, sfView *view);

#endif /* !BOX_COLLIDER_H_ */
