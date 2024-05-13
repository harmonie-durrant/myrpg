/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** print_stats
*/

#include "components/stats.h"
#include "my.h"
#include "rpg.h"

static void print_stat_type(e_st_type type)
{
    st_printer_t printer[] = {
        {ST_HP, "HP"}, {ST_MAX_HP, "MAX_HP"}, {ST_MP, "MP"}, {ST_ATK, "ATK"},
        {ST_MAX_MP, "MAX_MP"}, {ST_DEF, "DEF"}, {0, NULL}
    };

    for (int i = 0; printer[i].name; i++) {
        if (printer[i].type == type) {
            my_fprintf(2, printer[i].name);
            return;
        }
    }
    my_fprintf(2, "UNKNOWN");
}

static void print_stat_values(stat_value_t *val)
{
    if (!val) {
        return;
    }
    print_stat_type(val->type);
    my_fprintf(2, ": %d\n", val->value);
    print_stat_values(val->next);
}

void print_stats(void *data)
{
    c_stat_t *stats = (c_stat_t*)data;

    my_fprintf(2, "[STATS]: %p\n", data);
    if (!data) {
        my_fprintf(2, "stats is NULL\n");
    } else {
        my_fprintf(2, "nb_values: %d\n", stats->nb_stats);
        print_stat_values(stats->stats);
    }
}
