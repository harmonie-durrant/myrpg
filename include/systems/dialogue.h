/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** dialogue
*/

#ifndef SYS_DIALOGUE_H_
    #define SYS_DIALOGUE_H_

    #include "my.h"
    #include "ecs.h"
    #include "scene.h"
    #include "components/dialogue.h"

entity_t *is_player_close_to_npcs(scene_t *scene);
void toggle_dialogue_box(entity_t *npc_ent, int *show_box);
void draw_dialogue_box(c_dialogue_t *dialogue, rpg_t *rpg);

#endif /* !SYS_DIALOGUE_H_ */
