/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** input
*/

#ifndef INPUT_H_
    #define INPUT_H_
    #define key_pressed sfKeyboard_isKeyPressed
    #include "window.h"

    typedef enum e_input {
        I_NONE = 0,
        I_UP = 1,
        I_DOWN = 1 << 1,
        I_LEFT = 1 << 2,
        I_RIGHT = 1 << 3,
        I_ATK = 1 << 4,
        I_INT = 1 << 5,
        I_MAG = 1 << 6,
        I_INV = 1 << 7,
        I_ESC = 1 << 8,
        I_INTERACT = 1 << 9
    } e_input;

    typedef struct input_detector_s {
        e_input type;
        sfKeyCode code;
    } input_detector_t;

    typedef struct input_printer_s {
        e_input type;
        char *name;
    } input_printer_t;

e_input get_input(void);
void print_input(e_input input);

#endif /* !INPUT_H_ */
