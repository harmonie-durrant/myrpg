/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** dialogue_range_check
*/

//TODO:
// - Check if player is close enough to npc to interact
// - If yes, show icon next to npc
// - If yes and space is clicked, launch dialogue box and text
// - If no, hide icon next to npc if exists

#include <stdlib.h>
#include <math.h>
#include "systems/dialogue.h"
#include "components/transform.h"
#include "ecs.h"
#include "rpg.h"
#include "scene.h"
#include "window.h"
#include "my.h"

v2f get_player_pos(scene_t *scene)
{
    entity_t *player_ent = NULL;
    c_transform_t *player_transform = NULL;
    v2f player_pos = {0, 0};

    player_ent = get_entity_from_group(scene->entity_groups, G_T_PLAYER);
    if (!player_ent) {
        return (player_pos);
    }
    player_transform = get_component(player_ent->component, C_TRANSFORM);
    if (!player_transform) {
        return (player_pos);
    }
    player_pos = player_transform->pos;
    return (player_pos);
}

float get_distance(v2f pos1, v2f pos2)
{
    float distance = 0;

    distance = sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
    return (distance);
}

int is_player_close_to_npc(v2f player_pos, entity_t *npc_ent)
{
    c_transform_t *npc_transform = NULL;
    v2f npc_pos = {0, 0};
    float distance = 0;

    npc_transform = get_component(npc_ent->component, C_TRANSFORM);
    if (!npc_transform) {
        return (0);
    }
    npc_pos = npc_transform->pos;
    distance = get_distance(player_pos, npc_pos);
    if (distance <= 150)
        return 1;
    return 0;
}

entity_t *is_player_close_to_npcs(scene_t *scene)
{
    entity_t *npc_ent = NULL;
    v2f player_pos = {0,0};
    int is_close = 0;

    player_pos = get_player_pos(scene);
    npc_ent = get_entity_from_group(scene->entity_groups, G_T_NPC);
    if (!npc_ent) {
        return (0);
    }
    for (; npc_ent != NULL; npc_ent = npc_ent->next) {
        is_close = is_player_close_to_npc(player_pos, npc_ent);
        if (is_close == 1)
            return npc_ent;
    }
    return NULL;
}
