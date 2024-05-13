/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** write a function
*/

char *my_strupcase(char *str)
{
    for (int c = 0; str[c] != '\0'; c++) {
        if (str[c] >= 'a' && str[c] <= 'z')
            str[c] -= 32;
    }

    return (str);
}
