/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_stats
*/

#include <stdlib.h>
#include "components/stats.h"

stat_value_t *create_stat_value(e_st_type type, int value)
{
    stat_value_t *stat_value = NULL;

    stat_value = malloc(sizeof(stat_value_t));
    if (!stat_value) {
        return NULL;
    }
    stat_value->type = type;
    stat_value->value = value;
    stat_value->next = NULL;
    return stat_value;
}

c_stat_t *create_stat(void)
{
    c_stat_t *stat = NULL;

    stat = malloc(sizeof(c_stat_t));
    if (!stat) {
        return NULL;
    }
    stat->nb_stats = 0;
    stat->stats = NULL;
    return stat;
}

component_t *create_stat_comp(void)
{
    c_stat_t *stat = NULL;
    component_t *comp = NULL;

    if ((stat = create_stat()) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_STATS, stat)) == NULL) {
        destroy_stat(stat);
        return NULL;
    }
    comp->destroy = &destroy_stat;
    comp->print = &print_stats;
    return comp;
}

static void destroy_stat_values(stat_value_t *value)
{
    if (!value) {
        return;
    }
    destroy_stat_values(value->next);
    free(value);
}

void destroy_stat(void *data)
{
    c_stat_t *stat = (c_stat_t *)data;

    if (!stat) {
        return;
    }
    destroy_stat_values(stat->stats);
    free(stat);
}
