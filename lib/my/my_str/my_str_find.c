/*
** EPITECH PROJECT, 2023
** template_project
** File description:
** my_str_find
*/

int my_strlen(const char *str);

static int find_from_end(char* str, char c, int start)
{
    int i = start;

    while (str[i] != c) {
        if (i < 0)
            return -1;
        i--;
    }
    return i;
}

static int find_from_start(char* str, char c, int start)
{
    int i = start;

    while (str[i] != c) {
        if (str[i] == '\0')
            return -1;
        i++;
    }
    return i;
}

int my_str_find(char *str, char c, int start)
{
    int size = 0;

    size = my_strlen(str);
    if ((start < 0 && start * -1 >= size) || (start >= 0 && start >= size))
        return -1;
    if (start >= 0)
        return find_from_start(str, c, start);
    return find_from_end(str, c, size + start);
}
