/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_animator
*/

#include <stdlib.h>
#include "ecs.h"
#include "rpg.h"
#include "components/animator.h"
#include "my.h"

static int parse_anim_id(char *data_line)
{
    char *str = NULL;
    int finish = 0;
    int id = 0;

    if ((finish = my_str_find(data_line, ':', 0)) == -1) {
        return -1;
    }
    str = my_str_extract(data_line, 0, finish);
    id = my_atoi(str);
    free(str);
    return id;
}

static int parse_animations_data(c_animator_t *animator, char **data)
{
    int id = 0;
    v2i anim_data = {0, 0};

    for (int i = 0; data[i]; i++) {
        id = parse_anim_id(data[i]);
        if (id == -1) {
            return -1;
        }
        anim_data = parse_v2i(data[i]);
        if (anim_data.x < 0 || anim_data.y < 0) {
            return -1;
        }
        if (add_animation(animator, id, anim_data.x, anim_data.y) == -1) {
            return -1;
        }
    }
    return 0;
}

component_t *parse_animator_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    component_t *comp = NULL;
    c_sprite_t *sprite = NULL;

    UNUSED(rpg);
    if ((sprite = get_component(entity->component, C_SPRITE)) == NULL) {
        return NULL;
    }
    if ((comp = create_animator_comp(sprite)) == NULL) {
        return NULL;
    }
    if (parse_animations_data(comp->data, data) == -1) {
        destroy_component(comp);
        return NULL;
    }
    return comp;
}
