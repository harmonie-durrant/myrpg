/*
** EPITECH PROJECT, 2022
** is_in
** File description:
** return 1 if c is in str
*/

int my_is_in(const char c, const char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c) {
            return 1;
        }
    return 0;
}
