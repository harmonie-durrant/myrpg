/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update
*/

#ifndef UPDATE_H_
    #define UPDATE_H_
    #include "rpg.h"

void update_entity(entity_t *entity, rpg_t *rpg);
void update_entity_list(entity_t *head, rpg_t *rpg);
void update_entity_group_list(entity_group_t *head, rpg_t *rpg);

#endif /* !UPDATE_H_ */
