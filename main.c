/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Main file
** main
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map file representing the warehouse map, ");
    my_putstr("containing '#' for walls,\n");
    my_putstr("        'P' for the player, ");
    my_putstr("'X' for boxes and 'O' for storage locations.\n");
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        help();
        return 0;
    }
    return 0;
}
