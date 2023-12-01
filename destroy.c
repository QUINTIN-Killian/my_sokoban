/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** destroy things and exit
** error_handling
*/

#include "include/my.h"
#include "include/my_sokoban.h"

void destroy_buff(game_s *game, int leave)
{
    free(game->buff);
    if (leave)
        exit(84);
}

void destroy_map(game_s *game, int leave)
{
    for (int i = 0; i < my_strlen_array(game->map); i++)
        free(game->map[i]);
    free(game->map);
    if (leave)
        exit(84);
}
