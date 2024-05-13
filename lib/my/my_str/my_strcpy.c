/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** Write a function
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        i = i + 1;
    }

    for (int j = 0 ; j <= i ; j++){
        dest[j] = src[j];
    }
    return (dest);
}
