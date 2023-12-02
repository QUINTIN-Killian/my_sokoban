/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** auxiliary functions
** my_functions
*/

#include "include/my.h"
#include "include/my_sokoban.h"

char **my_str_array_dup(char **array)
{
    int len = my_strlen_array(array);
    char **ans = malloc(sizeof(char *) * (len + 1));

    for (int i = 0; i < len; i++)
        ans[i] = my_strdup(array[i]);
    ans[len] = NULL;
    return ans;
}
