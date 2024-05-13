/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** s_types
*/

#ifndef S_TYPES_H_
    #define S_TYPES_H_

    #include "window.h"
    #include "ground.h"
    #include "feature.h"

    #define SHEET_SIZE      ((v2i){144, 320})
    #define SPRITE_SIZE     ((v2f){16, 16})
    #define SPRITE_SCALE    ((v2f){6, 6})
    #define SS_SIZE          (VEC_MULT(SPRITE_SIZE, SPRITE_SCALE))

    typedef struct sprite_char_s {
        char c;
        v2i pos;
        v2i size;
    } sprite_char_t;

    typedef enum sprite_type {
        S_ERROR,
        S_FARM_TILEMAP,
        S_CHAR,
        S_MAIN_MENU,
        S_LOGO,
        S_MENU_BUTTON,
        S_FARM_FEATURE,
        S_MAYOR,
        S_CHAT_BOX,
        S_SETTINGS_BACK,
        S_SPLASH,
        S_PAUSE_BG
    } e_sprite_type;

#endif /* !S_TYPES_H_ */
