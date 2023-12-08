/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** search for errors in the map
** error_handling
*/

#include "include/my.h"
#include "include/my_sokoban.h"

void explore_map(game_s *game)
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

static void init_game(game_s *game)
{
    game->nb_player = 0;
    game->nb_boxes = 0;
    game->nb_circles = 0;
}

static void check_valid_number_of_elements_aux(game_s *game)
{
    if (game->nb_player != 1 || game->nb_circles == 0 || game->nb_boxes == 0 ||
    game->nb_circles != game->nb_boxes) {
        destroy_str(game->buff, 0);
        destroy_str_array(game->map, 0);
        destroy_str_array(game->map_ref, 1);
    }
}

void check_valid_number_of_elements(game_s *game)
{
    int x = 0;
    int y = 0;

    init_game(game);
    while (game->map[y][x] != '\0') {
        if (game->map[y][x] == 'X')
            game->nb_boxes++;
        if (game->map[y][x] == 'O')
            game->nb_circles++;
        if (game->map[y][x] == 'P')
            game->nb_player++;
        x++;
        if (game->map[y][x] == '\n') {
            x = 0;
            y++;
        }
    }
    check_valid_number_of_elements_aux(game);
}

void check_buffer_content(game_s *game)
{
    for (int i = 0; i < my_strlen(game->buff); i++) {
        if (game->buff[i] != ' ' && game->buff[i] != '\n' &&
        game->buff[i] != '#' && game->buff[i] != 'X' &&
        game->buff[i] != 'O' && game->buff[i] != 'P') {
            destroy_str(game->buff, 1);
        }
    }
}
