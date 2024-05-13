/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** resize_window
*/

#include "window.h"

int resize_window(window_t *win, int w, int h, char *title)
{
    if (win == NULL)
        return -1;
    if (w <= 0 || h <= 0)
        return -1;
    if (title != NULL)
        sfRenderWindow_setTitle(win->window, title);
    win->mode.width = w;
    win->mode.height = h;
    sfRenderWindow_setSize(win->window, (sfVector2u){w, h});
    sfView_setSize(win->view, (sfVector2f){w, h});
    sfRenderWindow_setView(win->window, win->view);
    return 0;
}
