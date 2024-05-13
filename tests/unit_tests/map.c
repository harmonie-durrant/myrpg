/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** map_test
*/

#include <criterion/criterion.h>
#include "rpg.h"
#include "ecs.h"
#include "map.h"
#include "my.h"

Test(init_map, no_map)
{
    char *filepath = "tests/maps/no_map.txt";

    cr_assert_eq(init_map(filepath), NULL);
}

Test(init_map, empty_map)
{
    char *filepath = "tests/maps/empty_map.txt";

    cr_assert_eq(init_map(filepath), NULL);
}

Test(init_map, unequal_map)
{
    char *filepath = "tests/maps/unequal_map.txt";

    cr_assert_eq(init_map(filepath), NULL);
}

Test(init_map, unequal_map_2)
{
    char *filepath = "tests/maps/unequal_map_2.txt";

    cr_assert_eq(init_map(filepath), NULL);
}

Test(init_map, good_map)
{
    char *filepath = "tests/maps/good_map.txt";

    cr_assert_neq(init_map(filepath), NULL);
}
