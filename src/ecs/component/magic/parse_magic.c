/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_magic
*/

#include <stdlib.h>
#include "components/magic.h"
#include "rpg.h"
#include "scene_parser.h"
#include "my.h"

static e_spell parse_spell(char *str)
{
    if (STR_EQ(str, "HEAL")) {
        return SP_HEAL;
    }
    if (STR_EQ(str, "FIRE_BALL")) {
        return SP_FIRE_BALL;
    }
    if (STR_EQ(str, "SHIELD")) {
        return SP_SHIELD;
    }
    return SP_NONE;
}

component_t *parse_magic_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    char *tmp = NULL;
    e_spell spell = SP_NONE;
    char *spell_str = NULL;

    UNUSED(entity);
    UNUSED(rpg);
    if ((tmp = get_data_arg(data, "spell:")) != NULL) {
        if ((spell_str = parse_str(tmp)) != NULL) {
            spell = parse_spell(spell_str);
            free(spell_str);
        }
    }
    return create_magic_comp(spell);
}
