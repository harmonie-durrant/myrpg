/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** debug_tools
*/

#include <stdlib.h>
#include "my.h"
#include "window.h"

char *my_itoa(int n)
{
    int i = 0;
    int nb = n;
    char *str = NULL;

    if (n == 0) {
        return my_strdup("0");
    }
    for (; nb > 0; i++) {
        nb /= 10;
    }
    if ((str = malloc(sizeof(char) * (i + 1))) == NULL) {
        return NULL;
    }
    str[i] = '\0';
    for (i--; i >= 0; i--) {
        str[i] = n % 10 + '0';
        n /= 10;
    }
    return str;
}

static void set_new_title(window_t *win, int fps)
{
    char *new_title = NULL;
    char *fps_str = NULL;

    if ((fps_str = my_itoa(fps)) == NULL) {
        return;
    }
    new_title = my_strcat_new("FPS: ", fps_str, "");
    free(fps_str);
    if (new_title == NULL) {
        return;
    }
    sfRenderWindow_setTitle(win->window, new_title);
    free(new_title);

}

void show_fps(window_t *win)
{
    static sfClock *clock = NULL;
    static int fps = 0;

    if (clock == NULL)
        clock = sfClock_create();
    if (sfClock_getElapsedTime(clock).microseconds > 1000000) {
        sfClock_restart(clock);
        set_new_title(win, fps);
        fps = 0;
    }
    fps++;
}

void print_debug_delim(int side)
{
    if (side) {
        my_fprintf(2, ">>>>>>>>>>\n");
    } else {
        my_fprintf(2, "<<<<<<<<<<\n");
    }
}
