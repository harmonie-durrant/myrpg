/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** print_inventory
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "components/inventory.h"
#include "ecs.h"

void print_inventory(void* inventory)
{
    c_inventory_t *inv = (c_inventory_t *)inventory;

    my_printf("INVENTORY: %p\nsize: %d\nitems:\n", inv, inv->size);
    print_entity_list(inv->items);
}
