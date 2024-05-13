/*
** EPITECH PROJECT, 2023
** template_project
** File description:
** my_str_lowcase
*/

int my_str_lowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 64 && str[i] < 91) {
            str[i] += 32;
        }
    }
    return 0;
}

int my_str_upcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 96 && str[i] < 123) {
            str[i] -= 32;
        }
    }
    return 0;
}
