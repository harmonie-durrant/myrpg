/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_transfrom
*/

#include "components/transform.h"
#include "rpg.h"
#include "my.h"
#include "types/s_types.h"

component_t *parse_transform_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    v2f pos = {0, 0};
    v2f scale = SPRITE_SCALE;
    float rotation = 0;
    char *tmp = NULL;
    int follow_cam = 0;

    UNUSED(entity);
    UNUSED(rpg);
    if ((tmp = get_data_arg(data, "position:")) != NULL)
        pos = parse_v2f(tmp);
    if ((tmp = get_data_arg(data, "follow-cam:")) != NULL)
        follow_cam = parse_int(tmp);
    if ((tmp = get_data_arg(data, "scale:")) != NULL)
        scale = parse_v2f(tmp);
    if ((tmp = get_data_arg(data, "rotation:")) != NULL)
        rotation = parse_float(tmp);
    return create_transform_comp(pos, scale, rotation, follow_cam);
}
