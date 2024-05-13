/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** entity_parser
*/

#ifndef ENTITY_PARSER_H_
    #define ENTITY_PARSER_H_

    #include "ecs.h"
    #include "rpg.h"
    #include "types/s_types.h"

    typedef struct parser_s {
        char *type_str;
        component_t *(*parse)(entity_t *, char **, rpg_t *);
    } parser_t;

    struct parser_data_s {
        entity_t *entity;
        rpg_t *rpg;
        parser_t *parser;
    };

// UTILS
int count_tabs(char *str);
int get_sid_from_filepath(char *filepath);
char *get_title_from_line(char *line);
char **get_data_from_lines(char **file_data_2d, int i);
char *get_data_from_line(char *line);
comp_type_t get_comp_type_str_from_line(char *str);
char **parse_str_2d(char *tmp, char sep);
e_sprite_type get_sprite_type(char *type_str);
sfColor parse_color(const char *str);

// PARSER
scene_t *scene_parser(char *filepath, rpg_t *rpg);
entity_group_t *create_entity_groups(char **file_data_2d);
int create_entities_in_groups(entity_group_t *groups, char **file_data_2d);
int create_components_in_entities(entity_group_t *groups, char **file_data_2d,
rpg_t *rpg);

// COMPONENTS

component_t *parse_component(entity_t *entity, char **file_data_2d, int i,
rpg_t *rpg);

// COMPONENTS PARSERS

component_t *parse_tile_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_animator_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_sound_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_transform_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_stat_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_sprite_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_tilemap_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_magic_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_inventory_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_ui_button_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_dialogue_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_controller_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_is_active_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_tag_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_collider_comp(entity_t *entity, char **data, rpg_t *rpg);
component_t *parse_cam_controller_comp(entity_t *entity,
char **data, rpg_t *rpg);
component_t *parse_collision_map_comp(entity_t *entity,
char **data, rpg_t *rpg);
component_t *parse_mob_controller_comp(entity_t *entity,
char **data, rpg_t *rpg);
component_t *parse_hitbox_comp(entity_t *entity, char **data, rpg_t *rpg);

#endif /* !ENTITY_PARSER_H_ */
