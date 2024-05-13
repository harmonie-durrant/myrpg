/*
** EPITECH PROJECT, 2028
** my_rpg
** File description:
** my_rpg
*/

#include <stdlib.h>
#include "ecs.h"
#include "rpg.h"
#include "my.h"
#include "window.h"
#include "scene.h"
#include "banks.h"
#include "types/s_types.h"
#include "components/tiles.h"
#include "scene_parser.h"

void destroy_rpg(rpg_t *rpg)
{
    destroy_window(rpg->win);
    destroy_scene_list(rpg->scenes);
    destroy_sprite_bank(rpg->sprite_bank);
    destroy_box_bank(rpg->box_bank);
    free(rpg);
}

rpg_t *init_rpg(char *scene_folder)
{
    rpg_t *rpg = NULL;

    rpg = malloc(sizeof(rpg_t));
    if (!rpg)
        return NULL;
    rpg->box_bank = NULL;
    if (!(rpg->win = init_window(1920, 1080, "My RPG", 90))) {
        destroy_rpg(rpg);
        return NULL;
    }
    rpg->info_bank = NULL;
    if (init_game_sprite_bank(rpg) == -1) {
        destroy_rpg(rpg);
        return NULL;
    }
    if (!(rpg->scenes = scene_parser(scene_folder, rpg))) {
        destroy_rpg(rpg);
        return NULL;
    }
    return rpg;
}

int my_rpg(char *scene_folder)
{
    rpg_t *rpg = NULL;

    rpg = init_rpg(scene_folder);
    if (!rpg) {
        my_fprintf(2, "Error: Failed to initialize rpg\n");
        return 84;
    }
    start_game(rpg);
    destroy_rpg(rpg);
    return 0;
}
