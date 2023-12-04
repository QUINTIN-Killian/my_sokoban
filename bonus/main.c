/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Main file
** main
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map file representing the warehouse map, ");
    my_putstr("containing '#' for walls,\n");
    my_putstr("        'P' for the player, ");
    my_putstr("'X' for boxes and 'O' for storage locations.\n");
    return 0;
}

static void game_loop(game_s *game, char **av)
{
    while (main_game(game)) {
        free_game(game);
        get_buffer_file(game, av[1]);
        convert_buffer_in_str_array(game);
        check_valid_number_of_elements(game);
        check_elements_accessible(game);
    }
}

int main(int ac, char **av)
{
    game_s game;

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0)
        return help();
    initscr();
    noecho();
    get_buffer_file(&game, av[1]);
    convert_buffer_in_str_array(&game);
    check_valid_number_of_elements(&game);
    check_elements_accessible(&game);
    game_loop(&game, av);
    free_game(&game);
    endwin();
    return 0;
}
