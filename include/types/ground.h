/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** ground
*/

#ifndef GROUND_H_
    #define GROUND_H_

    #include "window.h"

    //GROUND
    #define G_UP            ((v2i){3, 9})
    #define G_DOWN          ((v2i){3, 7})
    #define G_LEFT          ((v2i){4, 8})
    #define G_RIGHT         ((v2i){2, 8})
    #define G_UP_LEFT       ((v2i){0, 7})
    #define G_UP_RIGHT      ((v2i){1, 7})
    #define G_DOWN_LEFT     ((v2i){0, 8})
    #define G_DOWN_RIGHT    ((v2i){1, 8})
    #define GC_DOWN_RIGHT   ((v2i){2, 7})
    #define GC_DOWN_LEFT    ((v2i){4, 7})
    #define GC_UP_RIGHT     ((v2i){2, 9})
    #define GC_UP_LEFT      ((v2i){4, 9})
    #define G_MID           ((v2i){3, 1})

    #define P_UP            ((v2i){7, 11})
    #define P_DOWN          ((v2i){7, 13})
    #define P_LEFT          ((v2i){6, 12})
    #define P_RIGHT         ((v2i){8, 12})
    #define P_UP_LEFT       ((v2i){6, 11})
    #define P_UP_RIGHT      ((v2i){8, 11})
    #define P_DOWN_LEFT     ((v2i){6, 13})
    #define P_DOWN_RIGHT    ((v2i){8, 13})
    #define P_MID           ((v2i){7, 12})
    #define W_MID           ((v2i){3, 3})

    #define FLOOR           ((v2i){9, 2})

    //BRIDGE
    #define BRIDGE_LEFT     ((v2i){3, 16})

    //DETAILS
    #define WATER_LILY      ((v2i){8, 10})

    //WALL
    #define SKIRT_LEFT      ((v2i){9, 0})
    #define SKIRT_RIGHT     ((v2i){10, 0})
    #define CORNER_LEFT     ((v2i){9, 1})
    #define CORNER_RIGHT    ((v2i){10, 1})
    #define WALL_LEFT       ((v2i){11, 1})
    #define WALL_RIGHT      ((v2i){14, 1})
    #define WALL_FLAT       ((v2i){12, 2})
    #define WALL_TOP_LEFT   ((v2i){9, 7})
    #define WALL_TOP_CENTER ((v2i){10, 7})
    #define WALL_TOP_RIGHT  ((v2i){11, 7})
    #define B_WALL_LEFT     ((v2i){9, 6})
    #define B_WALL_CENTER   ((v2i){10, 6})
    #define B_WALL_RIGHT    ((v2i){11, 6})
    #define T_WALL_LEFT     ((v2i){9, 8})
    #define T_WALL_CENTER   ((v2i){10, 8})
    #define T_WALL_RIGHT    ((v2i){11, 8})

    //corner
    #define SK_C_DOWN_RIGHT ((v2i){12, 0})
    #define SK_C_DOWN_LEFT  ((v2i){13, 0})
    #define C_D_DOWN_LEFT   ((v2i){11, 4})
    #define C_D_DOWN_RIGHT  ((v2i){14, 4})

#endif /* !GROUND_H_ */
