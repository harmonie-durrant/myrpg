/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** sort an int array using bubble sort
*/

static int sort_int_array_check(int *arr, int size)
{
    int tmp = 0;
    int sort_flag = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            tmp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = tmp;
            sort_flag = 1;
        }
    }
    return sort_flag;
}

void my_sort_int_array(int *arr, int size)
{
    int sort_flag = 1;

    if (!size)
        return;

    while (sort_flag) {
        sort_flag = sort_int_array_check(arr, size);
    }
}
