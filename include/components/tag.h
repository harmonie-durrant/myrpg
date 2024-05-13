/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** tag
*/

#ifndef TAG_H_
    #define TAG_H_
    #include "ecs.h"
    #include "rpg.h"

    typedef struct c_tag_s {
        char *tag;
    } c_tag_t;

component_t *create_tag_comp(char *tag);
void destroy_tag(void *data);
void print_tag(void *data);

// TAG FUNCTIONS
entity_t *find_entity_with_tag(char *tag, scene_t *scene);
void hide_entity_with_tag(char *tag, scene_t *scene);
void show_entity_with_tag(char *tag, scene_t *scene);
int entity_has_tag(entity_t *entity, const char *str);

#endif /* !TAG_H_ */
