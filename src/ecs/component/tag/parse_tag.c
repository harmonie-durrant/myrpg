/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parse_tag
*/

#include "components/sound.h"
#include "components/tag.h"
#include "scene.h"
#include "rpg.h"
#include "my.h"

component_t *parse_tag_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    char *tag_str = NULL;
    char *tmp = NULL;

    UNUSED(entity);
    UNUSED(rpg);
    if ((tmp = get_data_arg(data, "name:")) != NULL) {
        tag_str = parse_str(tmp);
    }
    return create_tag_comp(tag_str);
}
