/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** Write a function
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0') {
        i = i + 1;
    }
    for (int j = 0 ; j < n && j <= i; j++){
        dest[j] = src[j];
    }
    dest[i + 1] = '\0';
    return (dest);
}
