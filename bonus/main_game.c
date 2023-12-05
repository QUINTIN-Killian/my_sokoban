/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game
** main_game
*/

#include "include/my.h"
#include "include/my_sokoban.h"

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
        return end_screen(0);
    }
    if (is_victory(game)) {
        return end_screen(1);
    }
    return -1;
}

static void print_map(game_s *game)
{
    char *instruction = "press 'space' to reinitialize the current map";
    char *leave = "press 'enter' to go back to the main menu";

    for (int i = 0; i < my_strlen_array(game->map); i++) {
        mvprintw(LINES / 2 - game->nb_lines / 2 + i,
        COLS / 2 - game->longest_col / 2, "%s", game->map[i]);
    }
    mvprintw(LINES - 2, 0, "%s", instruction);
    mvprintw(LINES - 1, 0, "%s", leave);
}

static void main_game_loop_content(game_s *game, int key)
{
    terminal_size_error(game);
    clear();
    reinit_map(key, game);
    move_player(key, game);
    print_map(game);
}

int main_game(game_s *game)
{
    int key;
    int end = -1;

    if (!starting_screen()) {
        endwin();
        return 0;
    }
    clear();
    terminal_size_error(game);
    print_map(game);
    key = getch();
    while (key != 10) {
        main_game_loop_content(game, key);
        end = end_condition(game);
        if (end != -1)
            return end;
        key = getch();
    }
    return 1;
}
