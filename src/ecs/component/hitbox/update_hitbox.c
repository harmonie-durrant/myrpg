/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_hitbox
*/

#include "components/hitbox.h"
#include "components/mob_controller.h"
#include "banks.h"
#include "my.h"

static void handle_hit(entity_t *entity1, entity_t *entity2)
{
    c_mob_controller_t *mob = NULL;
    c_stat_t *stat = NULL;
    int damage = 0;

    if ((stat = get_component(entity1->component, C_STATS)))
        damage = get_stat(stat, ST_ATK);
    if ((mob = get_component(entity2->component, C_MOB_CONTROLLER)) == NULL)
        return;
    damage = damage == -1 ? 0 : 0;
    attack_mob_controller(mob, entity2, damage);
}

void update_hitbox(void *data, entity_t *entity, rpg_t *rpg)
{
    c_hitbox_t *hitbox = (c_hitbox_t *)data;
    c_transform_t *transform = NULL;
    v2f pos = {0, 0};
    window_t *win = rpg->win;

    if (!hitbox || hitbox->is_active == 0)
        return;
    transform = get_component(entity->component, C_TRANSFORM);
    pos = hitbox->offset;
    pos.x = hitbox->flip ? -pos.x / 4 : pos.x * 2;
    pos = VEC_ADD(pos, transform->pos);
    sfRectangleShape_setPosition(hitbox->box, pos);
    if (SHOW_COLLIDER)
        sfRenderWindow_drawRectangleShape(win->window, hitbox->box, NULL);
    for (box_bank_t *curr = rpg->box_bank; curr; curr = curr->next) {
        if (curr->collider->is_active
        && check_rect_collide(hitbox->box, curr->collider->box)) {
            handle_hit(entity, curr->entity);
        }
    }
}
