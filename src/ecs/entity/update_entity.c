/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** compute_entity
*/

#include <stdlib.h>
#include "ecs.h"
#include "my.h"
#include "window.h"
#include "components/animator.h"
#include "components/sprite.h"
#include "components/tiles.h"
#include "components/controller.h"
#include "components/cam_controller.h"
#include "components/is_active.h"
#include "components/collider.h"
#include "components/collision_map.h"

static void draw_entity(entity_t *entity, rpg_t *rpg)
{
    c_tile_map_t *tile_map = NULL;
    c_sprite_t *sprite = NULL;
    c_animator_t *animator = NULL;
    c_transform_t *transform = NULL;

    if (!entity || !rpg)
        return;
    if (!is_active(entity))
        return;
    if ((tile_map = get_component(entity->component, C_TILE_MAP)) != NULL) {
        draw_tile_map(tile_map, rpg);
        return;
    }
    if ((animator = get_component(entity->component, C_ANIMATOR)) != NULL)
        play_animation(animator);
    sprite = get_component(entity->component, C_SPRITE);
    transform = get_component(entity->component, C_TRANSFORM);
    if (sprite && is_active(entity) == 1)
        draw_sprite(sprite, transform, rpg, entity);
}

void update_entity(entity_t *entity, rpg_t *rpg)
{
    component_t *curr = NULL;

    if (!entity) {
        return;
    }
    for (curr = entity->component; curr; curr = curr->next) {
        if (curr->update) {
            curr->update(curr->data, entity, rpg);
        }
    }
    draw_entity(entity, rpg);
}

void update_entity_list(entity_t *head, rpg_t *rpg)
{
    if (!head)
        return;
    update_entity(head, rpg);
    update_entity_list(head->next, rpg);
}

void update_entity_group_list(entity_group_t *head, rpg_t *rpg)
{
    if (!head) {
        return;
    }
    update_entity_list(head->entity, rpg);
    update_entity_group_list(head->next, rpg);
}
