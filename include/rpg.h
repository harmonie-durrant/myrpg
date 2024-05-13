/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg.h
*/

#ifndef RPG_H_
    #define RPG_H_

    #include "window.h"
    #include "ecs.h"
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include "input.h"

    typedef struct info_bank_s info_bank_t;
    typedef struct sprite_bank_s sprite_bank_t;
    typedef struct scene_s scene_t;
    typedef struct box_bank_s box_bank_t;

    typedef struct rpg_s {
        window_t *win;
        scene_t *scenes;
        scene_t *current_scene;
        info_bank_t *info_bank;
        sprite_bank_t *sprite_bank;
        box_bank_t *box_bank;
        e_input input;
    } rpg_t;

int my_rpg(char *fileneme);
void print_debug_delim(int side);
rpg_t *init_rpg(char *filename);
void destroy_rpg(rpg_t *rpg);
void show_fps(window_t *win);

int start_game(rpg_t *rpg);

// utils

void free_2d_array(char **arr);
int count_2d_array(char **arr);
char *get_clean_str(const char *str);
int parse_int(const char *str);
float parse_float(const char *str);
v2i parse_v2i(const char *str);
v2f parse_v2f(const char *str);
char *parse_str(const char *str);
char *get_data_arg(char **data, char *arg_name);
v2f get_next_interpolation(v2f a, v2f b, float speed);
short check_pos_in_screen(window_t *win, v2f pos);
float get_distance_from_circle(sfCircleShape *circle, v2f pos);
v2f normalize_vector(v2f vec);
v2f get_direction_from_vec(v2f vec1, v2f vec2);
int check_rect_collide(sfRectangleShape *shape1, sfRectangleShape *shape2);
float get_vector_abs_dist(v2f vec1, v2f vec2);

#endif /* !RPG_H_ */
