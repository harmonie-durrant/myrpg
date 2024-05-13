/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** handle_magic
*/

#include "components/magic.h"
#include "my.h"

static void print_spell(c_magic_t *magic)
{
    switch (magic->spell) {
    case SP_HEAL:
        my_fprintf(2, "HEAL");
        break;
    case SP_FIRE_BALL:
        my_fprintf(2, "FIRE_BALL");
        break;
    case SP_SHIELD:
        my_fprintf(2, "SHIELD");
        break;
    case SP_NONE:
        my_fprintf(2, "NO SPELL");
        break;
    }
}

void print_magic(void *data)
{
    c_magic_t *magic = (c_magic_t*)data;

    my_fprintf(2, "MAGIC: %p\n", data);
    my_fprintf(2, "spell: ");
    print_spell(magic);
    my_fprintf(2, "\n");
}
