/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** test_main
*/

#include <stdlib.h>
#include "ecs.h"
#include "components/transform.h"
#include "my.h"
#include "player.h"

int main(void)
{
    int size = 10000;
    entity_t *player = NULL;
    entity_t *tmp = NULL;

    for (int i = 0; i < size; i++) {
        tmp = init_player();
        print_entity(tmp);
        append_entity(&player, tmp);
        my_printf("%d\n", i);
    }
    destroy_entity(player);
    return 0;
}