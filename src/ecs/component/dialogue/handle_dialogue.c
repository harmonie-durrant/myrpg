/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** handle dialogue
*/

#include <unistd.h>
#include <stdlib.h>
#include "components/dialogue.h"
#include "ecs.h"
#include "rpg.h"
#include "my.h"

void print_dialogue(void *data)
{
    c_dialogue_t *dialogue = (c_dialogue_t*)data;

    my_fprintf(2, "[DIALOGUE]: %p\n", data);
    if (!data) {
        my_fprintf(2, "dialogue is NULL\n");
        return;
    }
    my_fprintf(2, "TYPE: [%d]\n", dialogue->type);
    for (int i = 0; dialogue->npc_dialogue[i] != NULL; i++) {
        my_fprintf(2, "NPC: %s\n", dialogue->npc_dialogue[i]);
    }
    for (int i = 0; dialogue->player_dialogue[i] != NULL; i++) {
        my_fprintf(2, "PLAYER: %s\n", dialogue->player_dialogue[i]);
    }
}
