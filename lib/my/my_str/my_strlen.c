/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Write a function
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
