/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** main
*/

#include "rpg.h"
#include "my.h"

int print_help(void)
{
    my_printf("MY RPG\n");
    my_printf("USAGE\n");
    my_printf("\t./my_rpg {scenes directory}\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && STR_EQ(av[1], "-h")) {
        return print_help();
    }
    if (ac == 2)
        return my_rpg(av[1]);
    return 84;
}
