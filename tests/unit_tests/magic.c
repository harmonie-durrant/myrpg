/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** magic_test
*/

#include <criterion/criterion.h>
#include "components/magic.h"

Test(magic, create_magic)
{
    c_magic_t *magic = NULL;

    magic = create_magic();
    cr_assert_not_null(magic);
}
