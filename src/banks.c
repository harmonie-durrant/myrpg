/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** banks
*/

#include <stdlib.h>
#include "banks.h"
#include "my.h"

sprite_bank_t *create_sprite_bank(e_sprite_type type, char *path)
{
    sprite_bank_t *new = NULL;
    sfTexture *texture = NULL;

    texture = sfTexture_createFromFile(path, NULL);
    if (!texture)
        return NULL;
    new = malloc(sizeof(sprite_bank_t));
    if (!new)
        return NULL;
    new->type = type;
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, texture, sfTrue);
    sfSprite_setScale(new->sprite, (sfVector2f){4, 4});
    new->next = NULL;
    return new;
}

void destroy_sprite_bank(sprite_bank_t *bank)
{
    sprite_bank_t *tmp = NULL;
    sprite_bank_t *curr = NULL;

    if ((curr = bank) == NULL) {
        return;
    }
    while (curr) {
        tmp = curr;
        curr = curr->next;
        sfSprite_destroy(tmp->sprite);
        free(tmp);
    }
}
