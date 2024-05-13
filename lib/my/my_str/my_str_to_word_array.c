/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

static void set_delimiters(char *str, char separator, int *delim)
{
    int i = 0;

    while (str[i] == separator)
        i++;
    delim[0] = i;
    i = my_strlen(str) - 1;
    while (str[i] == separator)
        i--;
    delim[1] = i + 1;
}

static void free_to(char **arr, int end)
{
    for (int i = 0; i < end; i++)
        free(arr[i]);
}

static char *get_word(char *str, int start, int finish)
{
    char *word = NULL;
    int word_itt = 0;

    word = malloc(sizeof(char) * (finish - start + 1));
    if (!word)
        return NULL;
    for (int i = start; i < finish; i++, word_itt++)
        word[word_itt] = str[i];
    word[word_itt] = '\0';
    return word;
}

static int add_words(char *str, char **arr, char sep, int *delim)
{
    int arr_itt = 0;
    int i = delim[0];
    int end = delim[1];
    int word_start = i;

    for (; i < end; i++) {
        if (str[i] != sep)
            continue;
        arr[arr_itt] = get_word(str, word_start, i);
        if (arr[arr_itt] == NULL) {
            free_to(arr, arr_itt);
            return -1;
        }
        word_start = i + 1;
        arr_itt++;
    }
    arr[arr_itt] = get_word(str, word_start, end);
    arr[arr_itt + 1] = NULL;
    return 0;
}

char **my_str_to_word_array(char *str, char separator)
{
    int delim[2];
    int word_count = 1;
    char **arr = NULL;

    set_delimiters(str, separator, delim);
    for (int i = delim[0]; i < delim[1]; i++)
        if (str[i] == separator)
            word_count++;
    arr = malloc(sizeof(char*) * (word_count + 1));
    if (!arr || add_words(str, arr, separator, delim))
        return NULL;
    return arr;
}
