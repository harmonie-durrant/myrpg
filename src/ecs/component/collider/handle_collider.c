/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_collider
*/

#include "components/collider.h"
#include "components/transform.h"
#include "banks.h"
#include "my.h"

int set_collider_trigger(c_collider_t *collider,
void *(*trigger)(entity_t *, rpg_t *, int))
{
    if (!collider || !trigger) {
        return -1;
    }
    collider->trigger = trigger;
    collider->is_static = 1;
    return 0;
}

static void scan_collision(entity_t *entity, c_collider_t *coll1, rpg_t *rpg)
{
    int status = 0;

    if (!coll1 || !rpg->box_bank) {
        return;
    }
    for (box_bank_t *curr = rpg->box_bank; curr; curr = curr->next) {
        if (curr->collider->box == coll1->box) {
            continue;
        }
        if (check_rect_collide(coll1->box, curr->collider->box)) {
            status = handle_collision(entity, coll1, curr->collider, rpg);
        }
    }
    if (status == 0)
        sfRectangleShape_setFillColor(coll1->box, DEBUG_GREEN);
}

void update_collider(void *data, entity_t *entity, rpg_t *rpg)
{
    c_collider_t *collider = (c_collider_t *)data;
    sfView *view = rpg->win->view;
    c_transform_t *tmp = NULL;
    v2f new_pos = {0};

    if (collider->is_active == 0)
        return;
    if ((tmp = get_component(entity->component, C_TRANSFORM)) != NULL) {
        new_pos = VEC_ADD(tmp->pos, collider->offset);
        if (collider->is_static == 0)
            sfRectangleShape_setPosition(collider->box, new_pos);
    }
    if (box_is_in_screen(collider->box, view) == sfFalse) {
        return;
    }
    if (SHOW_COLLIDER) {
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        collider->box, NULL);
    }
    scan_collision(entity, collider, rpg);
}
