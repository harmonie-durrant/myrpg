/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** banks
*/

#include <stdlib.h>
#include "banks.h"
#include "my.h"

static int add_sprites_to_bank(sprite_bank_parser_t parser[], rpg_t *rpg)
{
    int ret = 0;

    rpg->sprite_bank = NULL;
    for (int j = 0; parser[j].path != NULL; j++) {
        ret = add_sprite_to_bank(&rpg->sprite_bank, parser[j].type,
        parser[j].path);
    }
    if (!rpg->sprite_bank || ret != 0)
        return -1;
    return 0;
}

int init_game_sprite_bank(rpg_t *rpg)
{
    sprite_bank_parser_t parser[] = {
        {S_FARM_TILEMAP, "Assets/farm_tilemap.png"},
        {S_MAIN_MENU, "Assets/MainMenu_UI/Menu.png"},
        {S_LOGO, "Assets/MainMenu_UI/Logo.png"},
        {S_MENU_BUTTON, "Assets/MainMenu_UI/Buttons.png"},
        {S_FARM_FEATURE, "Assets/features.png"},
        {S_SPLASH, "Assets/Splash.png"}, {S_PAUSE_BG, "Assets/PauseBack.png"},
        {S_SETTINGS_BACK, "Assets/MainMenu_UI/SettingsMenu.png"},
        {S_MAYOR, "Assets/mayor.png"}, {S_CHAR, "Assets/characters.png"},
        {S_CHAT_BOX, "Assets/chat_box.png"}, {0, NULL}
    };
    return add_sprites_to_bank(parser, rpg);
}

int add_sprite_to_bank(sprite_bank_t **bank, e_sprite_type type, char *path)
{
    sprite_bank_t *new = NULL;
    sprite_bank_t *tmp = *bank;

    new = create_sprite_bank(type, path);
    if (!new)
        return -1;
    if (*bank == NULL) {
        *bank = new;
        return 0;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    return 0;
}

sfSprite *get_sprite_from_bank(sprite_bank_t *banks, e_sprite_type type)
{
    sprite_bank_t *tmp = banks;

    while (tmp != NULL) {
        if (tmp->type == type)
            return tmp->sprite;
        tmp = tmp->next;
    }
    return NULL;
}
