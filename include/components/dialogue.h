/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** dialogue
*/

#ifndef DIALOGUE_H_
    #define DIALOGUE_H_
    #include "ecs.h"
    #include "rpg.h"
    #include "types/s_types.h"

    typedef struct c_dialogue_s {
        char **player_dialogue;
        char **npc_dialogue;
        e_sprite_type type;
    } c_dialogue_t;

c_dialogue_t *create_dialogue(char **player_dialogue, char **npc_dialogue,
e_sprite_type type);
component_t *create_dialogue_comp(char **player_dialogue, char **npc_dialogue,
e_sprite_type type);
void destroy_dialogue(void *data);
void print_dialogue(void *data);

#endif /* !DIALOGUE_H_ */
