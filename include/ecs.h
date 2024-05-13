/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** ecs
*/

#ifndef ECS_H_
    #define ECS_H_
    #include "types/c_types.h"
    #include "window.h"

    typedef struct component_s component_t;
    typedef struct entity_s entity_t;
    typedef struct entity_group_s entity_group_t;
    typedef struct rpg_s rpg_t;

    #define DEBUG_GREEN ((sfColor){0,255,0,125})
    #define DEBUG_RED ((sfColor){255,0,0,125})
    #define DEBUG_BLUE ((sfColor){0,0,255,125})
    #define DEBUG_YELLOW ((sfColor){0,255,255,125})
    #define WATER_COLOR ((sfColor){136, 236, 204, 1})

    typedef enum group_type_e {
        G_T_ERROR,
        G_T_OTHER,
        G_T_MAP,
        G_T_PLAYER,
        G_T_MUSIC,
        G_T_NPC,
        G_T_UI,
        G_T_ITEM,
    } e_group_type;

    struct group_type_printer_s {
        e_group_type type;
        char *name;
    };

    typedef struct entity_group_s {
        e_group_type type;
        entity_t *entity;
        entity_group_t *next;
    } entity_group_t;

    typedef struct entity_s {
        int id;
        component_t *component;
        entity_t *next;
    } entity_t;

    typedef struct component_s {
        comp_type_t type;
        void *data;
        void (*destroy)(void *);
        void (*print)(void *);
        void (*update)(void *, entity_t *, rpg_t *);
        component_t *next;
    } component_t;

//? Entity Group
entity_group_t *create_entity_group(e_group_type type, entity_t *entity);
void destroy_entity_group_list(entity_group_t *group);

void add_entity_group(entity_group_t *group, entity_group_t **groups);
entity_t *get_entity_from_group(entity_group_t *groups, e_group_type type);
void draw_entity_group_list(entity_group_t *head, window_t *win);
void print_entity_group(entity_group_t *group);
void print_entity_group_list(entity_group_t *head);

//? Entity

entity_t *create_entity(int id);
void destroy_entity(entity_t *entity);
void destroy_entity_list(entity_t *head);
void print_entity(entity_t *entity);
void print_entity_list(entity_t *head);

int append_entity(entity_t **head, entity_t *entity);
entity_t *get_entity(entity_t *head, int id);

//? Component

component_t *create_component(comp_type_t type, void *data);
void destroy_component(component_t *component);
void destroy_component_list(component_t *head);

void print_component_list(component_t *head);
int append_component(component_t **head, component_t *component);
void *get_component(component_t *head, comp_type_t type);
int remove_component(component_t **head, comp_type_t type);

#endif /* !ECS_H_ */
