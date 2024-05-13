/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handle_stats
*/

#include <stdlib.h>
#include "components/stats.h"
#include "rpg.h"
#include "my.h"

int get_stat(c_stat_t *stat, e_st_type type)
{
    stat_value_t *value = NULL;

    if (!stat) {
        return -1;
    }
    value = stat->stats;
    while (value && value->type != type) {
        value = value->next;
    }
    if (!value) {
        return -1;
    }
    return value->value;
}

static int add_value(c_stat_t *stat, e_st_type type, int value)
{
    stat_value_t *val = NULL;

    val = create_stat_value(type, value);
    if (!val) {
        return -1;
    }
    if (stat->stats) {
        val->next = stat->stats;
    }
    stat->stats = val;
    stat->nb_stats++;
    return 0;
}

int set_stat(c_stat_t *stat, e_st_type type, int value)
{
    stat_value_t *curr = NULL;

    if (!stat) {
        return -1;
    }
    curr = stat->stats;
    while (curr && curr->type != type) {
        curr = curr->next;
    }
    if (curr) {
        curr->value = value;
        return 0;
    }
    add_value(stat, type, value);
    return 0;
}
