/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_controller
*/

#include "components/controller.h"
#include "components/collider.h"
#include "components/cam_controller.h"
#include "my.h"
#include "components/ui_button.h"

void attack_controller(c_controller_t *controller, int damage, rpg_t *rpg)
{
    int hp = 0;

    if (controller->is_invincible) {
        return;
    }
    hp = get_stat(controller->stats, ST_HP);
    hp -= damage;
    if (hp <= 0) {
        reset_cam(rpg->win->view);
        change_scene(NULL, rpg, 0);
    }
    set_stat(controller->stats, ST_HP, hp - damage);
    sfClock_restart(controller->i_clock);
    controller->is_invincible = 1;
}

void print_controller(void *data)
{
    c_controller_t *controller = (c_controller_t *)data;

    my_printf("[CONTROLLER]: %p\n", controller);
    if (controller) {
        my_printf("is_active: %p\n", controller->is_active);
        my_printf("transform: %p\n", controller->transform);
        my_printf("animator: %p\n", controller->animator);
        my_printf("stats: %p\n", controller->stats);
    }
}

void set_dir_animation(c_controller_t *controller, c_animator_t *anim,
int has_moved, v2i *direction)
{
    if (controller->is_attacking) {
        set_animation(anim, direction->x < 0 ? 4 : 5);
        return;
    }
    if (direction->x > 0) {
        set_animation(anim, has_moved ? 3 : 1);
        return;
    } else {
        set_animation(anim, has_moved ? 2 : 0);
    }
}

void handle_attack(c_controller_t *controller, e_input input)
{
    float atk_s = 0;

    if (input & I_ATK) {
        controller->is_active = 0;
        controller->hitbox->is_active = 1;
        controller->is_attacking = 1;
        sfClock_restart(controller->a_clock);
    }
    if (controller->is_attacking == 0)
        return;
    atk_s = sfTime_asSeconds(sfClock_getElapsedTime(controller->a_clock));
    if (atk_s < ATK_S)
        return;
    controller->is_active = 1;
    controller->hitbox->is_active = 0;
    controller->is_attacking = 0;
}

int handle_movement(c_controller_t *controller, c_transform_t *trans,
int speed, e_input input)
{
    int has_moved = 0;
    if (input & I_LEFT) {
        has_moved += move_transform(trans, (v2f){speed * -1, 0}) == 0;
        controller->direction.x += -1;
    }
    if (input & I_RIGHT) {
        has_moved += move_transform(trans, (v2f){speed, 0}) == 0;
        controller->direction.x += 1;
    }
    if (input & I_UP) {
        has_moved += move_transform(trans, (v2f){0, speed * -1}) == 0;
        controller->direction.y += 1;
    }
    if (input & I_DOWN) {
        has_moved += move_transform(trans, (v2f){0, speed}) == 0;
        controller->direction.y += -1;
    }
    controller->direction.x = CAP(controller->direction.x, -1, 1);
    controller->direction.y = CAP(controller->direction.y, -1, 1);
    return has_moved != 0;
}
