#include <criterion/criterion.h>
#include "rpg.h"
#include "ecs.h"
#include "map.h"
#include "my.h"

Test(init_rpg, valid_map)
{
    char *filepath = "tests/maps/good_map.txt";

    cr_assert_neq(init_rpg(filepath), NULL);
}

Test(init_rpg, invalid_map)
{
    char *filepath = "tests/maps/no_map.txt";

    cr_assert_eq(init_rpg(filepath), NULL);
}

Test(init_rpg, null_map)
{
    char *filepath = NULL;

    cr_assert_eq(init_rpg(filepath), NULL);
}

// my_rpg

Test(my_rpg, valid_map)
{
    char *filepath = "tests/maps/good_map.txt";

    cr_assert_eq(my_rpg(filepath), 0);
}

Test(my_rpg, invalid_map)
{
    char *filepath = "tests/maps/no_map.txt";

    cr_assert_eq(my_rpg(filepath), 84);
}

Test(my_rpg, null_map)
{
    char *filepath = NULL;

    cr_assert_eq(my_rpg(filepath), 84);
}
