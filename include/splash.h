/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** splash
*/

#ifndef SPLASH_H_
    #define SPLASH_H_

    #include "rpg.h"
    #include "window.h"

    typedef struct splash_s {
        window_t window;
        sfSprite *splashsprite;
        sfClock *clock;
        sfTime splashtime;
        int splash_cond;
    } splash_t;

sfBool show_splash_screen(splash_t * splash, rpg_t *rpg);
int init_splash_screen(rpg_t *rpg, splash_t **splash);

#endif /* !SPLASH_H_ */
