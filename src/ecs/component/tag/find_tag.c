/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** find_tag
*/

#include <stdlib.h>
#include "components/tag.h"
#include "my.h"

int entity_has_tag(entity_t *entity, const char *str)
{
    c_tag_t *tag = NULL;

    if ((tag = get_component(entity->component, C_TAG)) == NULL) {
        return 0;
    }
    if (STR_EQ(str, tag->tag)) {
        return 1;
    }
    return 0;
}
