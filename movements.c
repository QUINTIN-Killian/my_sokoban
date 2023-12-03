/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** get the arrow input
** get_arrow
*/

#include "include/my.h"
#include "include/my_sokoban.h"

void is_up_arrow(game_s *game)
{
    if (game->map[game->p_pos.y - 1][game->p_pos.x] != '#') {
        if (game->map_ref[game->p_pos.y][game->p_pos.x] == 'O') {
            game->map[game->p_pos.y][game->p_pos.x] = 'O';
        } else {
            game->map[game->p_pos.y][game->p_pos.x] = ' ';
        }
        game->p_pos.y -= 1;
        game->map[game->p_pos.y][game->p_pos.x] = 'P';
        reinit_buff(game);
    }
}

void is_down_arrow(game_s *game)
{
    if (game->map[game->p_pos.y + 1][game->p_pos.x] != '#') {
        if (game->map_ref[game->p_pos.y][game->p_pos.x] == 'O') {
            game->map[game->p_pos.y][game->p_pos.x] = 'O';
        } else {
            game->map[game->p_pos.y][game->p_pos.x] = ' ';
        }
        game->p_pos.y += 1;
        game->map[game->p_pos.y][game->p_pos.x] = 'P';
        reinit_buff(game);
    }
}

void is_right_arrow(game_s *game)
{
    if (game->map[game->p_pos.y][game->p_pos.x + 1] != '#') {
        if (game->map_ref[game->p_pos.y][game->p_pos.x] == 'O') {
            game->map[game->p_pos.y][game->p_pos.x] = 'O';
        } else {
            game->map[game->p_pos.y][game->p_pos.x] = ' ';
        }
        game->p_pos.x += 1;
        game->map[game->p_pos.y][game->p_pos.x] = 'P';
        reinit_buff(game);
    }
}

void is_left_arrow(game_s *game)
{
    if (game->map[game->p_pos.y][game->p_pos.x - 1] != '#') {
        if (game->map_ref[game->p_pos.y][game->p_pos.x] == 'O') {
            game->map[game->p_pos.y][game->p_pos.x] = 'O';
        } else {
            game->map[game->p_pos.y][game->p_pos.x] = ' ';
        }
        game->p_pos.x -= 1;
        game->map[game->p_pos.y][game->p_pos.x] = 'P';
        reinit_buff(game);
    }
}
