/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** init_window
*/

#include <stdlib.h>
#include "window.h"

void init_view(window_t *win, float width, float height)
{
    sfView_setSize(win->view, (sfVector2f){width, height});
    sfView_setCenter(win->view, (sfVector2f){width / 2, height / 2});
}

window_t *init_window(int w, int h, char *title, int rate)
{
    window_t *win = NULL;
    float wf = w;
    float hf = h;

    if (w <= 0 || h <= 0 || rate <= 0 || title == NULL)
        return NULL;
    win = (window_t *)malloc(sizeof(window_t));
    if (win == NULL)
        return NULL;
    win->mode.width = w;
    win->mode.height = h;
    win->mode.bitsPerPixel = 32;
    win->window = create_window(win->mode, title, sfClose | sfResize, NULL);
    if (win->window == NULL)
        return NULL;
    win->view = sfView_create();
    init_view(win, wf, hf);
    sfRenderWindow_setFramerateLimit(win->window, rate);
    return win;
}
