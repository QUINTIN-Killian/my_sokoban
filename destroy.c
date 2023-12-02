/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** destroy things and exit
** error_handling
*/

#include "include/my.h"
#include "include/my_sokoban.h"

void destroy_str(char *str, int leave)
{
    free(str);
    if (leave)
        exit(84);
}

void destroy_str_array(char **array, int leave)
{
    for (int i = 0; i < my_strlen_array(array); i++)
        free(array[i]);
    free(array);
    if (leave)
        exit(84);
}
