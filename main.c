/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Main file
** main
*/
/*
NOTES ET OBJECTIFS :
    - réactualisation map avec espace
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static void free_game(game_s *game)
{
    destroy_str(game->buff, 0);
    destroy_str_array(game->map, 0);
    destroy_str_array(game->map_ref, 0);
}

static void print_map(char **map)
{
    for (int i = 0; i < my_strlen_array(map); i++)
        write(1, map[i], my_strlen(map[i]));
}

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

int main(int ac, char **av)
{
    game_s game;

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0)
        return help();
    get_buffer_file(&game, av[1]);
    convert_buffer_in_str_array(&game);
    main_game(&game);
    free_game(&game);
    return 0;
}
