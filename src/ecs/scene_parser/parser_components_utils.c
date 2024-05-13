/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parser_components_utils
*/

#include <stdlib.h>
#include "scene.h"
#include "my.h"
#include "ecs.h"
#include "components/sprite.h"
#include "scene_parser.h"

static component_t *parse_component_loop(struct parser_data_s *parser_data,
char **file_data_2d, int i)
{
    parser_t *parser = parser_data->parser;
    entity_t *entity = parser_data->entity;
    rpg_t *rpg = parser_data->rpg;
    component_t *comp = NULL;
    char *type = NULL;
    char **data_str_2d = NULL;

    type = get_title_from_line(file_data_2d[i]);
    for (int j = 0; parser[j].parse != NULL; j++) {
        if (STR_EQ(parser[j].type_str, type)) {
            data_str_2d = get_data_from_lines(file_data_2d, i);
            comp = parser[j].parse(entity, data_str_2d, rpg);
            break;
        }
    }
    free(type);
    free_2d_array(data_str_2d);
    return comp;
}

component_t *parse_component(entity_t *entity, char **file_data_2d, int i,
rpg_t *rpg)
{
    parser_t parser[] = {
        {"tilemap", &parse_tilemap_comp}, {"uibutton", &parse_ui_button_comp},
        {"sprite", &parse_sprite_comp}, {"transform", &parse_transform_comp},
        {"controller", &parse_controller_comp}, {"magic", &parse_magic_comp},
        {"inventory", &parse_inventory_comp}, {"sound", &parse_sound_comp},
        {"dialogue", &parse_dialogue_comp}, {"active", &parse_is_active_comp},
        {"uibutton", &parse_ui_button_comp}, {"tag", &parse_tag_comp},
        {"controller", &parse_controller_comp},
        {"animator", &parse_animator_comp}, {"stats", &parse_stat_comp},
        {"cam-controller", &parse_cam_controller_comp},
        {"collider", &parse_collider_comp}, {"hitbox", &parse_hitbox_comp},
        {"collision-map", &parse_collision_map_comp},
        {"mob-controller", &parse_mob_controller_comp},
        {NULL, NULL}
    };
    struct parser_data_s parser_data = {entity, rpg, parser};

    return parse_component_loop(&parser_data, file_data_2d, i);
}

int create_components_in_entities(entity_group_t *groups, char **file_data_2d,
rpg_t *rpg)
{
    entity_group_t *c_group = NULL;
    entity_t *c_entity = NULL;
    component_t *c_component = NULL;
    int c = 0;

    c_group = groups;
    for (size_t i = 0; file_data_2d[i] != NULL; i++) {
        if (count_tabs(file_data_2d[i]) == 0) {
            c_group = (i == 0) ? groups : c_group->next; c = 0;
        }
        if (count_tabs(file_data_2d[i]) == 1) {
            c_entity = (c++ == 0) ? c_group->entity : c_entity->next;
        }
        if (count_tabs(file_data_2d[i]) == 2) {
            c_component = parse_component(c_entity, file_data_2d, i, rpg);
            append_component(&c_entity->component, c_component);
        }
    }
    return 0;
}
