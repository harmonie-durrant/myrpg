/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_stats
*/

#include "components/stats.h"
#include "scene_parser.h"
#include "rpg.h"
#include "my.h"

static void parse_values(c_stat_t *stat, char **data)
{
    char *tmp = NULL;
    struct st_type_parser_s parser[] = {
        {ST_HP, "HP:"}, {ST_MAX_HP, "MAX_HP:"}, {ST_MP, "MP:"},
        {ST_MAX_MP, "MAX_MP:"}, {ST_ATK, "ATK:"}, {ST_DEF, "DEF:"},
        {ST_SPD, "SPD:"}, {0, NULL}
    };

    for (int i = 0; parser[i].name; i++) {
        if ((tmp = get_data_arg(data, parser[i].name)) != NULL) {
            set_stat(stat, parser[i].type, parse_int(tmp));
        }
    }
}

component_t *parse_stat_comp(entity_t *entity, char **data, rpg_t *rpg)
{
    component_t *stat_comp = NULL;
    c_stat_t *stat = NULL;

    UNUSED(entity);
    UNUSED(rpg);
    if ((stat_comp = create_stat_comp()) == NULL) {
        return NULL;
    }
    stat = stat_comp->data;
    parse_values(stat, data);
    return stat_comp;
}
