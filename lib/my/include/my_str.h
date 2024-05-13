/*
** EPITECH PROJECT, 2022
** my string
** File description:
** functions of my linked char list lib
*/

#ifndef MY_STR
    #define MY_STR

    typedef struct my_str {
        char c;
        struct my_str *next;
    }my_str;

my_str *str_add(my_str *str, char c, int pos);
my_str *str_free(my_str *str, int pos);
char str_getc(my_str *str, int pos);
int str_setc(my_str *str, int pos, char c);
int str_len(my_str *str);
char *str_get_string(my_str *str);
my_str *str_freestr(my_str *str);
int str_print(my_str *str);
struct my_str *str_add_string(struct my_str *str, char *string);

#endif /* !MY_STR */
