/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** init_scenes
*/

#include <stdlib.h>
#include "scene.h"
#include "my.h"
#include "ecs.h"

scene_t *create_scene(int id, entity_group_t *entity_groups)
{
    scene_t *scene = NULL;

    if (id < 0)
        return NULL;
    scene = malloc(sizeof(scene_t));
    if (scene == NULL)
        return (NULL);
    scene->id = id;
    scene->entity_groups = entity_groups;
    scene->next = NULL;
    return scene;
}

scene_t *init_scenes(char *filename, rpg_t *rpg)
{
    scene_t *scene = NULL;

    UNUSED(filename);
    rpg->scenes = NULL;
    scene = create_scene(0, NULL);
    if (scene == NULL)
        return NULL;
    add_scene(scene, rpg);
    return scene;
}

void destroy_scene(scene_t *scene)
{
    if (scene == NULL)
        return;
    destroy_entity_group_list(scene->entity_groups);
    free(scene);
}

void destroy_scene_list(scene_t *head)
{
    if (head == NULL) {
        return;
    }
    destroy_scene_list(head->next);
    destroy_scene(head);
}
