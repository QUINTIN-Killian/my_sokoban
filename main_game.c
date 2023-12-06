/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game
** main_game
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static void print_map(game_s *game)
{
    for (int i = 0; i < my_strlen_array(game->map); i++) {
        mvprintw(LINES / 2 - game->nb_lines / 2 + i,
        COLS / 2 - game->longest_col / 2, "%s", game->map[i]);
    }
    refresh();
}

void move_player(int key, game_s *game)
{
    if (key == 65) {
        is_up_arrow(game);
        return;
    }
    if (key == 66) {
        is_down_arrow(game);
        return;
    }
    if (key == 67) {
        is_right_arrow(game);
        return;
    }
    if (key == 68) {
        is_left_arrow(game);
        return;
    }
}

static void reinit_map(int key, game_s *game)
{
    if (key == 32) {
        destroy_str_array(game->map, 0);
        game->map = my_str_array_dup(game->map_ref);
        init_player_pos(game);
    }
}

static int end_condition(game_s *game)
{
    if (is_blocked(game)) {
        return 1;
    }
    if (is_victory(game)) {
        return 0;
    }
    return -1;
}

int main_game(game_s *game)
{
    int key;
    int end = -1;

    while (end == -1 && key != 10) {
        terminal_size_error(game);
        clear();
        print_map(game);
        key = getch();
        reinit_map(key, game);
        move_player(key, game);
        end = end_condition(game);
        if (end != -1) {
            print_map(game);
            endwin();
            return end;
        }
    }
    endwin();
    return 1;
}
