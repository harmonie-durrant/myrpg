/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** handle_inventory
*/
#include <unistd.h>
#include <stdlib.h>
#include "components/inventory.h"
#include "ecs.h"

entity_t *get_inventory_item(c_inventory_t *inventory, int id)
{
    entity_t *item = NULL;
    if (!inventory) {
        return NULL;
    }
    item = inventory->items;
    while (item && item->id != id) {
        item = item->next;
    }
    return item;
}

int add_inventory_item(c_inventory_t *inventory, entity_t *item)
{
    if (!inventory || !item) {
        return -1;
    }
    if (inventory->items != NULL) {
        item->next = inventory->items;
    }
    inventory->items = item;
    return 0;
}
