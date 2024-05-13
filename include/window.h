/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** window.h
*/

#ifndef WINDOW_H_
    #define WINDOW_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #define v2f sfVector2f
    #define v2i sfVector2i
    #define create_window sfRenderWindow_create

    typedef struct window_s {
        sfRenderWindow *window;
        sfVideoMode mode;
        sfEvent event;
        sfView *view;
    } window_t;

window_t *init_window(int w, int h, char *title, int rate);
void destroy_window(window_t *win);
int resize_window(window_t *win, int w, int h, char *title);
void init_view(window_t *win, float width, float height);

#endif /* !WINDOW_H_ */
