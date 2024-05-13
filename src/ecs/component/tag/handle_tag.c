/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** get_transform
*/

#include <unistd.h>
#include <stdlib.h>
#include "components/tag.h"
#include "components/is_active.h"
#include "scene.h"
#include "ecs.h"
#include "rpg.h"
#include "my.h"

static entity_t *find_entity_eith_tag_st(char *tag, entity_group_t *group)
{
    c_tag_t *tag_comp = NULL;
    entity_t *entity = NULL;

    entity = group->entity;
    while (entity) {
        tag_comp = get_component(entity->component, C_TAG);
        if (tag_comp && tag_comp->tag && STR_EQ(tag_comp->tag, tag)) {
            return entity;
        }
        entity = entity->next;
    }
    return NULL;
}

entity_t *find_entity_with_tag(char *tag, scene_t *scene)
{
    entity_group_t *group = NULL;
    entity_t *entity = NULL;

    group = scene->entity_groups;
    while (group) {
        entity = find_entity_eith_tag_st(tag, group);
        if (entity != NULL) {
            return entity;
        }
        group = group->next;
    }
    return NULL;
}

void hide_entity_with_tag(char *tag, scene_t *scene)
{
    entity_t *entity = NULL;
    c_is_active_t *is_active;

    if ((entity = find_entity_with_tag(tag, scene)) == NULL) {
        return;
    }
    if ((is_active = get_component(entity->component, C_IS_ACTIVE)) == NULL) {
        return;
    }
    is_active->val = 0;
}

void show_entity_with_tag(char *tag, scene_t *scene)
{
    entity_t *entity = NULL;
    c_is_active_t *is_active;

    if ((entity = find_entity_with_tag(tag, scene)) == NULL) {
        return;
    }
    if ((is_active = get_component(entity->component, C_IS_ACTIVE)) == NULL) {
        return;
    }
    is_active->val = 1;
}

void print_tag(void *data)
{
    c_tag_t *tag = (c_tag_t*)data;

    my_fprintf(2, "[TAG]: %p\n", data);
    if (!data) {
        my_fprintf(2, "TAG DATA is NULL\n");
        return;
    }
    if (!tag->tag) {
        my_fprintf(2, "tag: NULL\n");
        return;
    }
    my_fprintf(2, "tag: %s\n", tag->tag);
}
