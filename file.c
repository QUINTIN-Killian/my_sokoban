/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** get the file content
** file
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static int get_size_col(char *buff, int ind_col)
{
    int enter = 0;
    int ind = 0;
    int ans = 0;

    while (enter != ind_col) {
        while (buff[ind] != '\n' && buff[ind] != '\0') {
            ind++;
        }
        ind++;
        enter++;
    }
    while (buff[ind] != '\n' && buff[ind] != '\0') {
        ans++;
        ind++;
    }
    ans++;
    return ans;
}

static int get_nb_lines(game_s *game)
{
    int ans = 0;

    for (int i = 0; i <= my_strlen(game->buff); i++) {
        if (game->buff[i] == '\n' || game->buff[i] == '\0') {
            ans++;
        }
    }
    return ans;
}

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

static void explore_map(game_s *game)
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

void convert_buffer_in_str_array(game_s *game)
{
    int temp;
    int ind_buff = 0;

    game->longest_col = 0;
    game->nb_lines = get_nb_lines(game);
    game->map = malloc(sizeof(char *) * (game->nb_lines + 1));
    for (int i = 0; i < game->nb_lines; i++) {
        temp = get_size_col(game->buff, i);
        if (temp > game->longest_col)
            game->longest_col = temp;
        game->map[i] = malloc(sizeof(char) * (temp + 1));
        for (int j = 0; j < temp; j++) {
            game->map[i][j] = game->buff[ind_buff];
            ind_buff++;
        }
        game->map[i][temp] = '\0';
    }
    game->map[game->nb_lines] = NULL;
    explore_map(game);
    game->map_ref = my_str_array_dup(game->map);
}

static void check_buffer_content(game_s *game)
{
    for (int i = 0; i < my_strlen(game->buff); i++) {
        if (game->buff[i] != ' ' && game->buff[i] != '\n' &&
        game->buff[i] != '#' && game->buff[i] != 'X' &&
        game->buff[i] != 'O' && game->buff[i] != 'P') {
            destroy_str(game->buff, 1);
        }
    }
}

void get_buffer_file(game_s *game, char *filepath)
{
    struct stat st;
    int file_size = 0;
    int len;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || stat(filepath, &st) == -1) {
        close(fd);
        exit(84);
    }
    file_size = st.st_size;
    game->buff = malloc(sizeof(char) * (file_size + 1));
    game->buff[st.st_size] = '\0';
    len = read(fd, game->buff, file_size);
    close(fd);
    if (len < 0)
        destroy_str(game->buff, 1);
    check_buffer_content(game);
}
