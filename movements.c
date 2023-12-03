/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** get the arrow input
** get_arrow
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static void respawn_circle(game_s *game)
{
    int x = 0;
    int y = 0;

    while (game->map_ref[y][x] != '\0') {
        if (game->map_ref[y][x] == 'O' && game->map[y][x] == ' ')
            game->map[y][x] = 'O';
        if (game->map_ref[y][x] == '\n') {
            x = -1;
            y++;
        }
        x++;
    }
}

static int move_box(game_s *game, int x, int y)
{
    if (game->map[y][x] != 'X')
        return 1;
    if (game->map[y][x] == 'X' &&
    (game->map[y + (y - game->p_pos.y)][x + (x - game->p_pos.x)] == 'O' ||
    game->map[y + (y - game->p_pos.y)][x + (x - game->p_pos.x)] == ' ')) {
        game->map[y + (y - game->p_pos.y)][x + (x - game->p_pos.x)] = 'X';
        return 1;
    }
    return 0;
}

void is_up_arrow(game_s *game)
{
    if (game->map[game->p_pos.y - 1][game->p_pos.x] != '#' &&
    move_box(game, game->p_pos.x, game->p_pos.y - 1)) {
        game->map[game->p_pos.y][game->p_pos.x] = ' ';
        game->p_pos.y -= 1;
        game->map[game->p_pos.y][game->p_pos.x] = 'P';
        respawn_circle(game);
        reinit_buff(game);
    }
}

void is_down_arrow(game_s *game)
{
    if (game->map[game->p_pos.y + 1][game->p_pos.x] != '#' &&
    move_box(game, game->p_pos.x, game->p_pos.y + 1)) {
        game->map[game->p_pos.y][game->p_pos.x] = ' ';
        game->p_pos.y += 1;
        game->map[game->p_pos.y][game->p_pos.x] = 'P';
        respawn_circle(game);
        reinit_buff(game);
    }
}

void is_right_arrow(game_s *game)
{
    if (game->map[game->p_pos.y][game->p_pos.x + 1] != '#' &&
    move_box(game, game->p_pos.x + 1, game->p_pos.y)) {
        game->map[game->p_pos.y][game->p_pos.x] = ' ';
        game->p_pos.x += 1;
        game->map[game->p_pos.y][game->p_pos.x] = 'P';
        respawn_circle(game);
        reinit_buff(game);
    }
}

void is_left_arrow(game_s *game)
{
    if (game->map[game->p_pos.y][game->p_pos.x - 1] != '#' &&
    move_box(game, game->p_pos.x - 1, game->p_pos.y)) {
        game->map[game->p_pos.y][game->p_pos.x] = ' ';
        game->p_pos.x -= 1;
        game->map[game->p_pos.y][game->p_pos.x] = 'P';
        respawn_circle(game);
        reinit_buff(game);
    }
}
