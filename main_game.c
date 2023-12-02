/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game
** main_game
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static void mvprintw_map(game_s *game)
{
    for (int i = 0; i < my_strlen_array(game->map); i++)
        mvprintw(LINES / 2 - game->nb_lines / 2,
        COLS / 2 - game->longest_col / 2, game->map[i]);
}

void reinit_buff(game_s *game)
{
    int len_map = 0;
    int ind = 0;
    int x = 0;
    int y = 0;

    free(game->buff);
    for (int i = 0; i < my_strlen_array(game->map); i++)
        len_map += my_strlen(game->map[i]);
    game->buff = malloc(sizeof(char) * (len_map + 1));
    while (game->map[y][x] != '\0') {
        game->buff[ind] = game->map[y][x];
        if (game->map[y][x] == '\n') {
            x = -1;
            y++;
        }
        ind++;
        x++;
    }
    game->buff[ind] = '\0';
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

void main_game(game_s *game)
{
    int key;

    initscr();
    clear();
    printw("%s", game->buff);
    key = getch();
    while (key != 32) {
        clear();
        move_player(key, game);
        printw("%s", game->buff);
        if (is_blocked(game) || is_victory(game))
            return;
        key = getch();
    }
    endwin();
}
