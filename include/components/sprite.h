/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** sprite
*/

#ifndef SPRITE_H_
    #define SPRITE_H_
    #include "window.h"
    #include "types/s_types.h"
    #include "components/transform.h"
    #include "ecs.h"
    #include "rpg.h"

    typedef struct sprite_parser_s {
        char *name;
        e_sprite_type type;
    } sprite_parser_t;

    typedef struct c_sprite_s {
        short is_active;
        sfSprite *sf_sprite;
        sfIntRect rect;
        v2i offset;
        v2i max_size;
    } c_sprite_t;

c_sprite_t *create_sprite(sprite_bank_t *sprite_bank, e_sprite_type type,
v2i offset, v2i max_size);
component_t *create_sprite_comp(sprite_bank_t *sprite_bank, e_sprite_type type,
v2i offset, v2i max_size);
void destroy_sprite(void *data);
void print_sprite(void *data);

void move_sprite_col(c_sprite_t *sprite);
int set_sprite_line(c_sprite_t *sprite, int line);
int set_sprite_pos(c_sprite_t *sprite, v2i pos);
void set_sprite_pos_state(c_sprite_t *sprite, v2i pos);
void draw_sprite(c_sprite_t *sprite, c_transform_t *transform, rpg_t *rpg,
entity_t *entity);
int is_hovered(c_transform_t *trans, rpg_t *rpg, c_sprite_t *sprite);
int is_clicked(c_transform_t *trans, rpg_t *rpg, c_sprite_t *sprite);

#endif /* !SPRITE_H_ */
