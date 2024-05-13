/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_dialogue
*/

#include <stdlib.h>
#include "components/dialogue.h"
#include "ecs.h"

c_dialogue_t *create_dialogue(char **player_dialogue, char **npc_dialogue,
e_sprite_type type)
{
    c_dialogue_t *dialogue = NULL;

    dialogue = malloc(sizeof(c_dialogue_t));
    if (!dialogue) {
        return NULL;
    }
    dialogue->type = type;
    dialogue->player_dialogue = player_dialogue;
    dialogue->npc_dialogue = npc_dialogue;
    return dialogue;
}

component_t *create_dialogue_comp(char **player_dialogue, char **npc_dialogue,
e_sprite_type type)
{
    c_dialogue_t *dialogue = NULL;
    component_t *comp = NULL;

    if ((dialogue =
        create_dialogue(player_dialogue, npc_dialogue, type)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_DIALOGUE, dialogue)) == NULL) {
        destroy_dialogue(dialogue);
        return NULL;
    }
    comp->destroy = &destroy_dialogue;
    comp->print = &print_dialogue;
    return comp;
}

void destroy_dialogue(void *data)
{
    c_dialogue_t *dialogue = NULL;

    dialogue = (c_dialogue_t *)data;
    free_2d_array(dialogue->player_dialogue);
    free_2d_array(dialogue->npc_dialogue);
    free(dialogue);
}
