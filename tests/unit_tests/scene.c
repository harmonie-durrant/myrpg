#include <criterion/criterion.h>
#include "rpg.h"
#include "scene.h"
#include "ecs.h"
#include "map.h"
#include "my.h"

Test(init_scene, scene_null)
{
    scene_t *scene = NULL;

    scene = init_scene(0, NULL, NULL);
    cr_assert_neq(scene, NULL);
}

Test(init_scene, scene_negative)
{
    scene_t *scene = NULL;

    scene = init_scene(-1, NULL, NULL);
    cr_assert_eq(scene, NULL);
}

Test(add_scene, add_scene_null)
{
    rpg_t *rpg = NULL;

    rpg = malloc(sizeof(rpg_t));
    rpg->scenes = NULL;
    add_scene(NULL, rpg);
    cr_assert_eq(rpg->scenes, NULL);
}

Test(add_scene, add_scene_test)
{
    rpg_t *rpg = NULL;
    scene_t *scene = NULL;

    rpg = malloc(sizeof(rpg_t));
    rpg->scenes = NULL;
    scene = init_scene(0, NULL, NULL);
    add_scene(scene, rpg);
    cr_assert_neq(rpg->scenes, NULL);
}
