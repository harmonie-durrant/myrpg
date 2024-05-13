/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_transfrom
*/

#include <stdlib.h>
#include "components/sound.h"
#include "types/s_types.h"
#include "rpg.h"
#include "my.h"

component_t *parse_sound_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    char *tmp = NULL;
    char *filepath = NULL;
    float volume = 0;

    UNUSED(entity);
    UNUSED(rpg);
    if ((tmp = get_data_arg(data, "file:")) != NULL)
        filepath = parse_str(tmp);
    if ((tmp = get_data_arg(data, "volume:")) != NULL)
        volume = parse_float(tmp);
    return create_sound_comp(filepath, volume);
}
