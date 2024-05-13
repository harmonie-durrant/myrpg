/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** init_splash
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdbool.h>
#include "components/ui_button.h"
#include "splash.h"
#include "window.h"
#include "my.h"
#include "banks.h"
#include "rpg.h"
#include "banks.h"

sfBool show_splash_screen(splash_t * splash, rpg_t *rpg)
{
    if (!splash)
        return sfFalse;
    if (splash->splash_cond == 1) {
        sfRenderWindow_drawSprite(splash->window.window,
        splash->splashsprite, NULL);
        if (sfTime_asSeconds(sfClock_getElapsedTime(splash->clock))
        >= sfTime_asSeconds(splash->splashtime)) {
            splash->splash_cond = 0;
            toggle_settings(NULL, rpg, 0);
        }
    }
    return sfTrue;
}

int init_splash_screen(rpg_t *rpg, splash_t **splash)
{
    *splash = malloc(sizeof(splash_t));
    if (!*splash)
        return 84;
    (*splash)->splashsprite = get_sprite_from_bank(rpg->sprite_bank, S_SPLASH);
    if (!(*splash)->splashsprite) {
        printf("Error loading splash image.\n");
        return 84;
    }
    (*splash)->window = *rpg->win;
    (*splash)->clock = sfClock_create();
    (*splash)->splashtime = sfSeconds(3);
    sfSprite_setScale((*splash)->splashsprite, (sfVector2f){1.02, 1.02});
    (*splash)->splash_cond = 1;
    return 0;
}
