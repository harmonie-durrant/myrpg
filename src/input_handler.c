/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** input_handler
*/

#include "ecs.h"
#include "input.h"
#include "my.h"

e_input get_input(void)
{
    e_input input = I_NONE;
    input_detector_t detector[] = {
        {I_UP, sfKeyW}, {I_UP, sfKeyZ},{I_DOWN, sfKeyS},
        {I_LEFT, sfKeyA}, {I_LEFT, sfKeyQ}, {I_RIGHT, sfKeyD},
        {I_INV, sfKeyTab}, {I_INT, sfKeyE}, {I_ESC, sfKeyEscape},
        {I_MAG, sfKeyM}, {I_ATK, sfKeySpace}, {0, sfKeyUnknown}
    };

    for (int i = 0; detector[i].type != 0; i++) {
        if (key_pressed(detector[i].code)) {
            input |= detector[i].type;
        }
    }
    return input;
}

void print_input(e_input input)
{
    input_printer_t printer[] = {
        {I_UP, "UP"}, {I_UP, "UP"},{I_DOWN, "DOWN"},
        {I_LEFT, "LEFT"}, {I_LEFT, "LEFT"}, {I_RIGHT, "RIGHT"},
        {I_INV, "INVENTORY"}, {I_INT, "INTERACT"}, {I_ESC, "PAUSE"},
        {I_MAG, "MAGIC"}, {I_ATK, "ATTACK"}, {0, NULL}
    };
    for (int i = 0; printer[i].type != 0; i++) {
        if (printer[i].type & input) {
            my_fprintf(2, "%s\n", printer[i].name);
        }
    }
    my_fputchar(2, '\n');
}
