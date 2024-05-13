/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** c_inventory
*/

#include "ecs.h"

#ifndef C_INVENTORY_H_
    #define C_INVENTORY_H_

    typedef struct c_inventory_s {
        int size;
        entity_t *items;
    } c_inventory_t;

c_inventory_t *create_inventory(int size);
component_t *create_inventory_comp(int size);
void destroy_inventory(void *data);
void print_inventory(void* data);

entity_t *get_inventory_item(c_inventory_t *inventory, int id);
int add_inventory_item(c_inventory_t *inventory, entity_t *item);

#endif /* !C_INVENTORY_H_ */
