#include <criterion/criterion.h>
#include "rpg.h"
#include "ecs.h"
#include "map.h"
#include "my.h"

Test(test_entity, create_entity_null)
{
    entity_t *entity = NULL;

    entity = create_entity(0);

    cr_assert_neq(entity, NULL);
    cr_assert_eq(entity->id, 0);
}
