/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** st_type
*/

#ifndef ST_TYPE_H_
    #define ST_TYPE_H_
    #define DEFAULT_SPEED 10

    typedef enum st_type {
        ST_HP,
        ST_MAX_HP,
        ST_MP,
        ST_MAX_MP,
        ST_ATK,
        ST_DEF,
        ST_SPD
    } e_st_type;

    typedef struct st_printer_s {
        e_st_type type;
        char *name;
    } st_printer_t;

#endif /* !ST_TYPE_H_ */
