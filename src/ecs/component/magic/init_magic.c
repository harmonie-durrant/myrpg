/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_magic
*/

#include <stdlib.h>
#include "components/magic.h"

c_magic_t *create_magic(e_spell spell)
{
    c_magic_t *magic = NULL;

    magic = malloc(sizeof(c_magic_t));
    if (!magic) {
        return NULL;
    }
    magic->spell = spell;
    return magic;
}

component_t *create_magic_comp(e_spell spell)
{
    c_magic_t *magic = NULL;
    component_t *comp = NULL;

    if ((magic = create_magic(spell)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_MAGIC, magic)) == NULL) {
        destroy_magic(magic);
    }
    comp->destroy = &destroy_magic;
    comp->print = &print_magic;

    return comp;
}

void destroy_magic(void *data)
{
    free(data);
}
