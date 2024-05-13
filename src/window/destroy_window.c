/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** destroy_window
*/

#include <stdlib.h>
#include "window.h"

void destroy_window(window_t *win)
{
    if (!win)
        return;
    sfRenderWindow_destroy(win->window);
    sfView_destroy(win->view);
    free(win);
}
