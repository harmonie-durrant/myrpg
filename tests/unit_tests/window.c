#include <criterion/criterion.h>
#include "rpg.h"
#include "ecs.h"
#include "map.h"
#include "my.h"

Test(init_window, window_null)
{
    window_t *window = NULL;

    window = init_window(1920, 1080, NULL, 60);
    cr_assert_eq(window, NULL);
}

Test(init_window, window_empty)
{
    window_t *window = NULL;

    window = init_window(19200, 1080, "", 60);
    cr_assert_neq(window, NULL);
}

Test(init_window, window_test)
{
    window_t *window = NULL;

    window = init_window(19200, 1080, "test", 60);
    cr_assert_neq(window, NULL);
}

Test(init_window, window_zero_fps)
{
    window_t *window = NULL;

    window = init_window(1920, 1080, "test", 0);
    cr_assert_eq(window, NULL);
}

Test(init_window, window_zero_res)
{
    window_t *window = NULL;

    window = init_window(0, 0, "test", 60);
    cr_assert_eq(window, NULL);
}

Test(init_window, window_negative_res)
{
    window_t *window = NULL;

    window = init_window(-1920, -1080, "test", 60);
    cr_assert_eq(window, NULL);
}

Test(init_window, window_negative_fps)
{
    window_t *window = NULL;

    window = init_window(1920, 1080, "test", -60);
    cr_assert_eq(window, NULL);
}
