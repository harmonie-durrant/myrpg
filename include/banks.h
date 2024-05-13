/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** banks
*/

#ifndef BANKS_H_
    #define BANKS_H_
    #include "ecs.h"
    #include "rpg.h"
    #include "types/s_types.h"
    #include "components/collider.h"

    typedef struct rpg_s rpg_t;

    typedef enum type_e {
        T_PLAYER,
        T_NPC,
        T_I_CONSUMABLE,
        T_I_WEAPON,
        T_I_ARMOR,
        T_I_MATERIAL,
    } type_t;

    typedef struct sprite_bank_s {
        e_sprite_type type;
        sfSprite *sprite;
        struct sprite_bank_s *next;
    } sprite_bank_t;

    typedef struct info_bank_s {
        int id;
        type_t type;
        char *name;
        char *description;
        struct info_bank_s *next;
    } info_bank_t;

    typedef struct box_bank_s {
        struct c_collider_s *collider;
        entity_t *entity;
        struct box_bank_s *next;
    } box_bank_t;

    typedef struct sprite_bank_parser_s {
        e_sprite_type type;
        char *path;
    } sprite_bank_parser_t;

sprite_bank_t *create_sprite_bank(e_sprite_type type, char *path);
void destroy_sprite_bank(sprite_bank_t *bank);

int init_game_sprite_bank(rpg_t *rpg);
int add_sprite_to_bank(sprite_bank_t **bank, e_sprite_type type, char *path);
sfSprite *get_sprite_from_bank(sprite_bank_t *banks, e_sprite_type type);
int init_game_sprite_bank(rpg_t *rpg);

// Box bank

int add_box_bank(rpg_t *rpg, entity_t *entity, c_collider_t *coll);
void destroy_box_bank(box_bank_t *box_bank);

#endif /* !BANKS_H_ */
