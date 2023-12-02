/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** manage the end of the game
** end_game
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static int is_blocked_aux(game_s *game, int x, int y)
{
    int nb_wall_y = 0;
    int nb_wall_x = 0;

    if (y > 0)
        if (game->map[y - 1][x] == '#')
            nb_wall_y++;
    if (y < my_strlen_array(game->map) - 1)
        if (game->map[y + 1][x] == '#')
            nb_wall_y++;
    if (x > 0)
        if (game->map[y][x - 1] == '#')
            nb_wall_x++;
    if (x < my_strlen(game->map[y]) - 1)
        if (game->map[y][x + 1] == '#')
            nb_wall_x++;
    if (nb_wall_y > 0 && nb_wall_x > 0)
        return 1;
    return 0;
}

int is_blocked(game_s *game)
{
    int x = 0;
    int y = 0;
    int ans = 0;

    while (game->map[y][x] != '\0') {
        if (game->map[y][x] == 'X')
            ans = is_blocked_aux(game, x, y);
        if (ans != 0)
            return ans;
        if (game->map[y][x] == '\n') {
            x = -1;
            y++;
        }
        x++;
    }
    return ans;
}

int is_victory(game_s *game)
{
    int x = 0;
    int y = 0;

    while (game->map_ref[y][x] != '\0') {
        if (game->map_ref[y][x] == 'O' && game->map[y][x] != 'X')
            return 0;
        if (game->map_ref[y][x] == '\n') {
            x = -1;
            y++;
        }
        x++;
    }
    return 1;
}
