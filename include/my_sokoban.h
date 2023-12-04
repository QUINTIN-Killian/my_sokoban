/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Header file for my_sokoban project
** my_sokoban
*/

#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct player_pos {
    int x;
    int y;
} player_pos_s;

typedef struct game {
    char *buff;
    char **map_ref;
    char **map;
    player_pos_s p_pos;
    int nb_lines;
    int longest_col;
} game_s;

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_

//my_functions.c :
void terminal_size_error(game_s *game);
char **my_str_array_dup(char **array);
void init_player_pos(game_s *game);

//destroy.c :
void destroy_str(char *str, int leave);
void destroy_str_array(char **array, int leave);

//file.c :
void convert_buffer_in_str_array(game_s *game);
void get_buffer_file(game_s *game, char *filepath);

//main_game.c :
int main_game(game_s *game);

//movements.c :
void is_up_arrow(game_s *game);
void is_down_arrow(game_s *game);
void is_left_arrow(game_s *game);
void is_right_arrow(game_s *game);

//end_game.c :
int is_blocked(game_s *game);
int is_victory(game_s *game);

#endif
