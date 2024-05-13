/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** entity_parser
*/

#include <stdlib.h>
#include "scene.h"
#include "my.h"
#include "ecs.h"
#include "scene_parser.h"

static int check_yml(char **data)
{
    for (size_t i = 0; data[i] != NULL; i++) {
        if (count_tabs(data[i]) == 0 && (my_strlen(data[i]) < 2 ||
            data[i][my_strlen(data[i]) - 1] != ':')) {
            return -1;
        }
        if (count_tabs(data[i]) == 1 && (my_strlen(data[i]) < 3 ||
            data[i][my_strlen(data[i]) - 1] != ':')) {
            return -1;
        }
        if (count_tabs(data[i]) == 2 && (my_strlen(data[i]) < 4 ||
            data[i][my_strlen(data[i]) - 1] != ':')) {
            return -1;
        }
        if (count_tabs(data[i]) == 3 && (my_strlen(data[i]) < 6 ||
            data[i][3] != '-' || data[i][4] != ' ')) {
            return -1;
        }
    }
    return 0;
}

static int fill_scene(char *file_data, scene_t *scene, rpg_t *rpg)
{
    char **data = NULL;

    if ((data = my_str_to_word_array(file_data, '\n')) == NULL) {
        return -1;
    }
    if (check_yml(data) == -1) {
        return -1;
    }
    if ((scene->entity_groups = create_entity_groups(data)) == NULL) {
        return -1;
    }
    if (create_entities_in_groups(scene->entity_groups, data) != 0) {
        return -1;
    }
    if (create_components_in_entities(scene->entity_groups, data, rpg) != 0) {
        return -1;
    }
    return 0;
}

scene_t *parse_scene(char *filepath, rpg_t *rpg)
{
    scene_t *scene = NULL;
    char *file_data = NULL;

    if ((file_data = my_readfile(filepath)) == NULL) {
        return NULL;
    }
    if ((scene = malloc(sizeof(scene_t))) == NULL) {
        return NULL;
    }
    if ((scene->id = get_sid_from_filepath(filepath)) == -1) {
        return NULL;
    }
    if (fill_scene(file_data, scene, rpg) != 0) {
        return NULL;
    }
    scene->next = NULL;
    return scene;
}

static void parse_valid_file(scene_t **scene, scene_t **tmp,
char *filepath, rpg_t *rpg)
{
    if (*scene == NULL) {
        *scene = parse_scene(filepath, rpg);
        *tmp = *scene;
    } else {
        (*tmp)->next = parse_scene(filepath, rpg);
        (*tmp) = (*tmp)->next;
    }
}

scene_t *scene_parser(char *folder, rpg_t *rpg)
{
    scene_t *scene = NULL;
    scene_t *tmp = NULL;
    char *filepath = NULL;
    char *name = NULL;
    char *folder_str = NULL;

    folder_str = (folder[my_strlen(folder) - 1] != '/') ?
    my_strcat_new(folder, "", "/") : my_strdup(folder);
    for (size_t i = 0; i < 10; i++) {
        name = my_itoa(i);
        filepath = my_strcat_new(folder_str, ".yml", name);
        if (my_readfile(filepath) == NULL)
            continue;
        parse_valid_file(&scene, &tmp, filepath, rpg);
    }
    free(filepath);
    free(folder_str);
    free(name);
    return scene;
}
