/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** add_scene
*/

#include "scene.h"
#include "rpg.h"
#include "my.h"
#include "components/sound.h"
#include "components/ui_button.h"

void add_scene(scene_t *scene, rpg_t *rpg)
{
    scene_t *tmp = rpg->scenes;

    if (rpg->scenes == NULL) {
        rpg->scenes = scene;
        return;
    }
    if (tmp == NULL)
        return;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = scene;
}

void remove_scene(int id, rpg_t *rpg)
{
    scene_t *tmp = rpg->scenes;
    scene_t *prev = NULL;

    if (tmp == NULL)
        return;
    while (tmp->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (prev == NULL)
        rpg->scenes = tmp->next;
    else
        prev->next = tmp->next;
    destroy_scene(tmp);
}

scene_t *get_scene(int id, rpg_t *rpg)
{
    scene_t *tmp = NULL;

    tmp = rpg->scenes;
    if (tmp == NULL)
        return NULL;
    while (tmp != NULL) {
        if (tmp->id == id)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void print_scene(scene_t *scene)
{
    my_printf("SCENE: %p\n", scene);
    print_entity_group_list(scene->entity_groups);
}

void *change_scene(entity_t *entity, rpg_t *rpg, int val)
{
    scene_t *scene = NULL;

    UNUSED(entity);
    play_scene_sound(rpg->current_scene, 0);
    scene = get_scene(val, rpg);
    if (scene != NULL) {
        if (rpg->current_scene->id != 0)
            toggle_pause_callback(NULL, rpg, 0);
        my_fprintf(2, "Scene %d loading...\n", val);
        rpg->current_scene = scene;
    } else {
        my_fprintf(2, "Scene %d does not exist.\n", val);
    }
    play_scene_sound(rpg->current_scene, 1);
    print_scene(rpg->current_scene);
    return NULL;
}
