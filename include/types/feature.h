/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** feature
*/

#ifndef FEATURE_H_
    #define FEATURE_H_

    #include "window.h"

    //BUILDING
    #define HOUSE           ((v2i){0, 7})
    #define KENNEL          ((v2i){6, 5})
    #define WELL            ((v2i){9, 5})
    #define DOOR_C          ((v2i){6, 8})
    #define DOOR_O          ((v2i){6, 10})
    #define SIGN            ((v2i){3, 6})
    #define BARN            ((v2i){13, 6})

    //TREE
    #define TREE_A          ((v2i){6, 0})
    #define TREE_B          ((v2i){3, 0})
    #define TREE_C          ((v2i){6, 4})

    //NATURE
    #define WHEAT           ((v2i){9, 3})
    #define WHEAT_F         ((v2i){9, 0})
    #define W_FLOWER        ((v2i){3, 4})
    #define R_FLOWER        ((v2i){4, 4})
    #define S_FLOWER        ((v2i){5, 4})
    #define G_ROCK          ((v2i){8, 8})
    #define LEAF_FIRST      ((v2i){10, 19})
    #define LEAF_SECOND     ((v2i){11, 19})
    #define LEAF_THIRD      ((v2i){12, 19})
    #define F_PUMPKIN       ((v2i){10, 14})
    #define S_PUMPKIN       ((v2i){11, 14})
    #define T_PUMPKIN       ((v2i){12, 14})
    #define PUMPKIN         ((v2i){13, 14})
    #define CORN            ((v2i){17, 14})
    #define POTATO          ((v2i){13, 17})

    //SEEDS
    #define SEED_A          ((v2i){9, 14})
    #define SEED_B          ((v2i){9, 15})
    #define SEED_C          ((v2i){9, 16})
    #define SEED_D          ((v2i){9, 17})
    #define SEED_E          ((v2i){9, 18})
    #define SEED_F          ((v2i){9, 19})
    #define SEED_G          ((v2i){9, 20})
    #define SEED_H          ((v2i){9, 21})
    #define SEED_I          ((v2i){9, 22})

    //Baril
    #define BARIL           ((v2i){11, 0})
    #define BARIL_WATER     ((v2i){11, 2})
    #define BARIL_FLOWER    ((v2i){11, 4})
    #define BARIL_APPLE     ((v2i){11, 6})

    //FENCE
    #define F_UP_LEFT       ((v2i){0, 0})
    #define F_UP_RIGHT      ((v2i){2, 0})
    #define F_DOOR_F_RIGHT  ((v2i){1, 0})
    #define F_DOOR_F_LEFT   ((v2i){1, 1})
    #define F_MID_LEFT      ((v2i){0, 1})
    #define F_MID_RIGHT     ((v2i){2, 1})
    #define F_DOWN_LEFT     ((v2i){2, 2})
    #define F_DOWN_RIGHT    ((v2i){0, 2})
    #define F_DOWN_MID      ((v2i){1, 2})
    #define F_DBL_DOOR      ((v2i){0, 4})
    #define F_SGL_DOOR      ((v2i){0, 5})

    //SPOT OF DIRT
    #define DIRT_A          ((v2i){5, 22})
    #define DIRT_B          ((v2i){6, 22})
    #define DIRT_C          ((v2i){7, 22})

    //HOUSE FEATURES
    #define LARGE_BED       ((v2i){0, 26})
    #define TABLE           ((v2i){10, 24})
    #define WINDOW          ((v2i){4, 24})
    #define LAMP            ((v2i){2, 26})
    #define NIGHTSTAND      ((v2i){8, 26})
    #define FRAME_A         ((v2i){4, 25})
    #define FRAME_B         ((v2i){5, 25})
    #define APPLE_BASKET    ((v2i){5, 26})
    #define CARPET          ((v2i){2, 28})
    #define LIBRARY_A       ((v2i){8, 28})
    #define LIBRARY_B       ((v2i){9, 28})
    #define LIBRARY_C       ((v2i){10, 28})
    #define SETUP           ((v2i){16, 23})
    #define TV              ((v2i){12, 26})
    #define SOFA            ((v2i){13, 24})
    #define TOILLET         ((v2i){8, 24})

    //PATH BLOCK
    #define WAY_UP_LEFT     ((v2i){5, 14})
    #define WAY_UP_MID      ((v2i){6, 14})
    #define WAY_UP_RIGHT    ((v2i){7, 14})
    #define WAY_MID_LEFT    ((v2i){5, 15})
    #define WAY_MID_MID     ((v2i){6, 15})
    #define WAY_MID_RIGHT   ((v2i){7, 15})
    #define WAY_DOWN_LEFT   ((v2i){5, 16})
    #define WAY_DOWN_MID    ((v2i){6, 16})
    #define WAY_DOWN_RIGHT  ((v2i){7, 16})

    //PATH HORIZONTAL
    #define WAY_H_LEFT     ((v2i){0, 14})
    #define WAY_H_MID      ((v2i){1, 14})
    #define WAY_H_RIGHT    ((v2i){2, 14})

    //PATH VERTICAL
    #define WAY_V_UP       ((v2i){4, 14})
    #define WAY_V_MID      ((v2i){4, 15})
    #define WAY_V_DOWN     ((v2i){4, 16})

    //SPOT OF DIRT
    #define DIRT_A          ((v2i){5, 22})
    #define DIRT_B          ((v2i){6, 22})
    #define DIRT_C          ((v2i){7, 22})

    //HOUSE FEATURES
    #define LARGE_BED       ((v2i){0, 26})
    #define TABLE           ((v2i){10, 24})
    #define WINDOW          ((v2i){4, 24})
    #define LAMP            ((v2i){2, 26})
    #define NIGHTSTAND      ((v2i){8, 26})
    #define FRAME_A         ((v2i){4, 25})
    #define FRAME_B         ((v2i){5, 25})
    #define APPLE_BASKET    ((v2i){5, 26})
    #define CARPET          ((v2i){2, 28})
    #define LIBRARY_A       ((v2i){8, 28})
    #define LIBRARY_B       ((v2i){9, 28})
    #define LIBRARY_C       ((v2i){10, 28})
    #define SETUP           ((v2i){16, 23})
    #define TV              ((v2i){12, 26})
    #define SOFA            ((v2i){13, 24})
    #define TOILLET         ((v2i){8, 24})

#endif /* !FEATURE_H_ */
