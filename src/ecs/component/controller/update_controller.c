/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_controller
*/

#include "components/controller.h"
#include "components/collider.h"
#include "my.h"

static void update_invincibility(c_controller_t *controller)
{
    float i_sec = 0;
    float f_sec = 0;
    int sprite_status = controller->animator->sprite->is_active;

    if (controller->is_invincible == 0) {
        return;
    }
    f_sec = sfTime_asSeconds(sfClock_getElapsedTime(controller->f_clock));
    i_sec = sfTime_asSeconds(sfClock_getElapsedTime(controller->i_clock));
    if (f_sec > FLASH_S) {
        controller->animator->sprite->is_active = sprite_status == 1 ? 0 : 1;
        sfClock_restart(controller->f_clock);
    }
    if (i_sec < INVINCIBILITY_S) {
        return;
    }
    sfClock_restart(controller->i_clock);
    controller->animator->sprite->is_active = 1;
    controller->is_invincible = 0;
}

void update_controller(void *data, entity_t *entity, rpg_t *rpg)
{
    c_controller_t *controller = (c_controller_t *)data;
    e_input input = rpg->input;
    c_transform_t *transform = controller->transform;
    c_animator_t *animator = controller->animator;
    int speed = 0;
    int moved = 0;

    UNUSED(entity);
    if ((speed = get_stat(controller->stats, ST_SPD)) == -1)
        speed = DEFAULT_SPEED;
    if (controller->is_active)
        moved = handle_movement(controller, transform, speed, input);
    if (controller->hitbox)
        handle_attack(controller, input);
    set_dir_animation(controller, animator, moved, &controller->direction);
    update_invincibility(controller);
    controller->hitbox->flip = controller->direction.x < 0 ? 1 : 0;
}
