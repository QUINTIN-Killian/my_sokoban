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

void init_player_pos(game_s *game)
{
    int x = 0;
    int y = 0;

    while (game->map[y][x] != '\0') {
        if (game->map[y][x] == 'P') {
            game->p_pos.x = x;
            game->p_pos.y = y;
        }
        if (game->map[y][x] == '\n') {
            x = -1;
            y++;
        }
        x++;
    }
}
