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
    char **map;
    player_pos_s p_pos;
} game_s;

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_

//destroy.c :
void destroy_buff(game_s *game, int leave);
void destroy_map(game_s *game, int leave);

//file.c :
void convert_buffer_in_str_array(game_s *game);
void get_buffer_file(game_s *game, char *filepath);

#endif
