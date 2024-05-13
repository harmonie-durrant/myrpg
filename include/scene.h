/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** scene
*/

#ifndef SCENE_H_
    #define SCENE_H_
    #include "ecs.h"
    #include "rpg.h"

    typedef struct scene_s {
        int id;
        entity_group_t *entity_groups;
        struct scene_s *next;
    } scene_t;

scene_t *init_scenes(char *filename, rpg_t *rpg);
scene_t *create_scene(int id, entity_group_t *entity_groups);
void add_scene(scene_t *scene, rpg_t *rpg);
void remove_scene(int id, rpg_t *rpg);
scene_t *get_scene(int id, rpg_t *rpg);
void destroy_scene(scene_t *scene);
void destroy_scene_list(scene_t *head);
void print_scene(scene_t *scene);

#endif /* !SCENE_H_ */
