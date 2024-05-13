/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** stats
*/

#ifndef STATS_H_
    #define STATS_H_
    #include "types/st_types.h"
    #include "ecs.h"

    typedef struct stat_value_s stat_value_t;

    typedef struct stat_value_s {
        e_st_type type;
        int value;
        stat_value_t *next;
    }stat_value_t;

    typedef struct c_stat_s {
        int nb_stats;
        stat_value_t *stats;
    }c_stat_t;

    struct st_type_parser_s {
        e_st_type type;
        char *name;
    };

c_stat_t *create_stat(void);
component_t *create_stat_comp(void);
stat_value_t *create_stat_value(e_st_type type, int value);
void destroy_stat(void *data);
void print_stats(void *data);

int set_stat(c_stat_t *stat, e_st_type type, int value);
int get_stat(c_stat_t *stat, e_st_type type);

#endif /* !STATS_H_ */
