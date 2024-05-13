/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** print_entity_group
*/

#include "my.h"
#include "ecs.h"

static void print_group_type(e_group_type type)
{
    struct group_type_printer_s printer[] = {
        {G_T_PLAYER, "PLAYER"}, {G_T_MAP, "MAP"}, {G_T_ITEM, "ITEM"},
        {G_T_MUSIC, "MUSIC"}, {G_T_NPC, "NPC"}, {G_T_UI, "UI"},
        {G_T_OTHER, "OTHER"}, {G_T_ERROR, "ERROR"}
    };

    for (int i = 0; printer[i].type != G_T_ERROR; i++) {
        if (printer[i].type == type) {
            my_printf("%s\n", printer[i].name);
            return;
        }
    }
}

void print_entity_group(entity_group_t *group)
{
    if (group == NULL)
        return;
    my_printf("entity_group: ");
    print_group_type(group->type);
    print_entity_list(group->entity);
}

void print_entity_group_list(entity_group_t *head)
{
    if (head == NULL)
        return;
    print_entity_group(head);
    print_entity_group_list(head->next);
}
