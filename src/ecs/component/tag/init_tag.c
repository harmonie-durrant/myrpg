/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_transform
*/

#include <stdlib.h>
#include "components/tag.h"
#include "ecs.h"

c_tag_t *create_tag(char *tag)
{
    c_tag_t *c_tag = NULL;

    c_tag = malloc(sizeof(c_tag_t));
    if (!c_tag) {
        return NULL;
    }
    c_tag->tag = tag;
    return c_tag;
}

component_t *create_tag_comp(char *tag)
{
    c_tag_t *c_tag = NULL;
    component_t *comp = NULL;

    if ((c_tag = create_tag(tag)) == NULL) {
        return NULL;
    }
    if ((comp = create_component(C_TAG, c_tag)) == NULL) {
        destroy_tag(tag);
        return NULL;
    }
    comp->destroy = &destroy_tag;
    comp->print = &print_tag;
    return comp;
}

void destroy_tag(void *data)
{
    c_tag_t *tag = (c_tag_t*)data;

    free(tag->tag);
    free(data);
}
