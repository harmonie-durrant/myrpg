/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** box_bank
*/

#include <stdlib.h>
#include "banks.h"
#include "components/collider.h"

int add_box_bank(rpg_t *rpg, entity_t *entity, c_collider_t *coll)
{
    box_bank_t *new = NULL;

    if ((new = malloc(sizeof(box_bank_t))) == NULL) {
        return -1;
    }
    new->collider = coll;
    new->entity = entity;
    new->next = NULL;
    if (rpg->box_bank == NULL) {
        rpg->box_bank = new;
        return 0;
    }
    for (box_bank_t *curr = rpg->box_bank; curr; curr = curr->next) {
        if (curr->next == NULL) {
            curr->next = new;
            return 0;
        }
    }
    return -1;
}

void destroy_box_bank(box_bank_t *box_bank)
{
    if (!box_bank) {
        return;
    }
    destroy_box_bank(box_bank->next);
    free(box_bank);
}
