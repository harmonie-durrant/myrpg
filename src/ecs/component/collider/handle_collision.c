/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_collision
*/

#include "components/collider.h"
#include "components/transform.h"
#include "components/tag.h"
#include "my.h"
#include "banks.h"

static void compute_resolution(entity_t *entity,
sfFloatRect rect1, sfFloatRect rect2)
{
    c_transform_t *transform = NULL;
    v2f offset = {0, 0};
    float overlapX = 0;
    float overlapY = 0;

    overlapX = MIN(rect1.left + rect1.width - rect2.left,
    rect2.left + rect2.width - rect1.left);
    overlapY = MIN(rect1.top + rect1.height - rect2.top,
    rect2.top + rect2.height - rect1.top);
    if (overlapX < overlapY) {
        offset.x = rect1.left < rect2.left ? -overlapX : overlapX;
    } else {
        offset.y = rect1.top < rect2.top ? -overlapY : overlapY;
    }
    if ((transform = get_component(entity->component, C_TRANSFORM)) != NULL) {
        move_transform(transform, offset);
    }
}

sfBool box_is_in_screen(sfRectangleShape *box, sfView *view)
{
    sfFloatRect screen_rect = {0};
    sfFloatRect box_rect = {0};
    v2f screen_pos = {0};
    v2f size = {0};

    screen_pos = sfView_getCenter(view);
    size = sfView_getSize(view);
    screen_rect.left = screen_pos.x - size.x / 2;
    screen_rect.top = screen_pos.y - size.y / 2;
    screen_rect.width = size.x;
    screen_rect.height = size.y;
    box_rect = sfRectangleShape_getGlobalBounds(box);
    return sfFloatRect_intersects(&screen_rect, &box_rect, NULL);
}

static void resolve_collision(entity_t *entity,
c_collider_t *coll1, c_collider_t *coll2)
{
    sfFloatRect rect1 = {0};
    sfFloatRect rect2 = {0};

    rect1 = sfRectangleShape_getGlobalBounds(coll1->box);
    rect2 = sfRectangleShape_getGlobalBounds(coll2->box);
    compute_resolution(entity, rect1, rect2);
}

static void tp_player(c_collider_t *coll, rpg_t *rpg)
{
    c_transform_t *trans = NULL;
    entity_t *entity = NULL;

    entity = find_entity_with_tag("Player", rpg->current_scene);
    if (entity == NULL) {
        my_fprintf(2, "ERROR: No entity with tag Player\n");
    }
    if ((trans = get_component(entity->component, C_TRANSFORM)) == NULL) {
        return;
    }
    if (coll->trigger_vec.x == -1 && coll->trigger_vec.y == -1) {
        return;
    }
    trans->pos = coll->trigger_vec;
}

int handle_collision(entity_t *entity, c_collider_t *coll1,
c_collider_t *coll2, rpg_t *rpg)
{
    if (coll2) {
        if (coll2->trigger) {
            coll2->trigger(entity, rpg, coll2->trigger_val);
            tp_player(coll2, rpg);
        }
        if (coll1->is_static && coll2->is_static)
            return 0;
        if (!coll1->is_static)
            resolve_collision(entity, coll1, coll2);
        sfRectangleShape_setFillColor(coll1->box, DEBUG_RED);
        coll1->is_colliding = 1;
        return 1;
    }
    coll1->is_colliding = 0;
    return 0;
}
