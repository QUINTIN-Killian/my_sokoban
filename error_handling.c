/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** search for errors in the map
** error_handling
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static void check_valid_box(game_s *game, int x, int y)
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
    if (nb_wall_y > 0 && nb_wall_x > 0) {
        destroy_str(game->buff, 0);
        destroy_str_array(game->map, 1);
    }
}

void explore_map(game_s *game)
{
    int x = 0;
    int y = 0;

    while (game->map[y][x] != '\0') {
        if (game->map[y][x] == 'X')
            check_valid_box(game, x, y);
        if (game->map[y][x] == 'P') {
            game->p_pos.x = x;
            game->p_pos.y = y;
        }
        x++;
        if (game->map[y][x] == '\n') {
            x = 0;
            y++;
        }
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

static void search_elements(game_s *game, int x, int y, info_temp_s *info_temp)
{
    if (game->map[y][x] == 'X')
        info_temp->nb_boxes++;
    if (game->map[y][x] == 'O')
        info_temp->nb_circles++;
    if (game->map[y][x] != '#' && game->map[y][x] != '1') {
        game->map[y][x] = '1';
        search_elements(game, x - 1, y, info_temp);
        search_elements(game, x + 1, y, info_temp);
        search_elements(game, x, y - 1, info_temp);
        search_elements(game, x, y + 1, info_temp);
    }
}

void check_elements_accessible(game_s *game)
{
    info_temp_s info_temp;

    info_temp.nb_player = 0;
    info_temp.nb_boxes = 0;
    info_temp.nb_circles = 0;
    search_elements(game, game->p_pos.x, game->p_pos.y, &info_temp);
    if (info_temp.nb_boxes != game->nb_boxes ||
    info_temp.nb_circles != game->nb_circles) {
        free_game(game);
        exit(84);
    } else {
        destroy_str_array(game->map, 0);
        game->map = my_str_array_dup(game->map_ref);
    }
}
