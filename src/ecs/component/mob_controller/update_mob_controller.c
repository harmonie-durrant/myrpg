/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_mob_controller
*/

#include "components/mob_controller.h"
#include "components/collider.h"
#include "my.h"

void set_mob_controller_ai(c_mob_controller_t *mob_controller,
const char *str)
{
    ai_parser_t parser[] = {
        {"stand-attack", &compute_stand_attack},
        {"attack", &compute_attack},
        {"stand-follow", &compute_stand_follow},
        {"follow", &compute_follow},
        {NULL, NULL}
    };

    for (int i = 0; parser[i].name != NULL; i++) {
        if (STR_EQ(parser[i].name, str)) {
            mob_controller->compute = parser[i].compute;
            my_fprintf(2, "AI IS NOW %s\n", parser->name);
            return;
        }
    }
}

void update_mob_controller(void *data, entity_t *entity, rpg_t *rpg)
{
    c_mob_controller_t *mob = (c_mob_controller_t *)data;
    v2f pos = mob->transform->pos;

    if (mob->is_active == 0)
        return;
    set_mob_controller_animation(mob);
    sfCircleShape_setPosition(mob->circle, VEC_ADD(pos, mob->offset));
    if (SHOW_COLLIDER) {
        sfRenderWindow_drawCircleShape(rpg->win->window, mob->circle, NULL);
    }
    if (mob->compute == NULL)
        return;
    mob->compute(entity, mob, rpg);
}
