/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** init_inventory
*/
#include <unistd.h>
#include <stdlib.h>
#include "components/inventory.h"
#include "ecs.h"

c_inventory_t *create_inventory(int size)
{
    c_inventory_t *inventory = malloc(sizeof(c_inventory_t));

    if (!inventory)
        return NULL;
    inventory->size = size;
    inventory->items = NULL;
    return inventory;
}

component_t *create_inventory_comp(int size)
{
    component_t *comp = NULL;
    c_inventory_t *inventory = NULL;

    if ((inventory = create_inventory(size)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_INVENTORY, inventory)) == NULL) {
        destroy_inventory(inventory);
        return NULL;
    }
    comp->print = &print_inventory;
    comp->destroy = &destroy_inventory;
    return comp;
}

void destroy_inventory(void *inventory)
{
    c_inventory_t *inv = (c_inventory_t *)inventory;

    destroy_entity_list(inv->items);
    free(inv);
}
