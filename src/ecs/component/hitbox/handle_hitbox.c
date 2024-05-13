/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_hitbox
*/

#include "my.h"
#include "components/hitbox.h"

void print_hitbox(void *data)
{
    c_hitbox_t *hitbox = (c_hitbox_t *)data;

    my_fprintf(2, "[HITBOX]: %p\n", data);
    if (hitbox) {
        my_fprintf(2, "is_active: %d\n", hitbox->is_active);
        my_fprintf(2, "box: %p\n", hitbox->box);
    }
}
