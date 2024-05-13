#include <criterion/criterion.h>
#include "components/inventory.h"
#include "types/c_types.h"
#include "rpg.h"
#include "ecs.h"
#include "map.h"
#include "my.h"

Test(test_component, create_component_null)
{
    component_t *component = NULL;

    component = create_component(C_INVENTORY, NULL);
    cr_assert_neq(component, NULL);
    cr_assert_eq(component->type, C_INVENTORY);
    cr_assert_eq(component->data, NULL);
    cr_assert_eq(component->next, NULL);
}
