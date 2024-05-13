/*
** EPITECH PROJECT, 2023
** my_str_countchar
** File description:
** returns number of occurence of a char in a string
*/

int my_str_countchar(char *str, char c)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count++;

    return count;
}
