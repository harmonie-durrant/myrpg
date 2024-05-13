/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** callback
*/

#ifndef CALLBACK_H_
    #define CALLBACK_H_

    #include "rpg.h"


void mouse_released(rpg_t *rpg, entity_t *npc_ent, int *show_dialogue);
void key_released(rpg_t *rpg, sfEvent evt);

#endif /* !CALLBACK_H_ */
