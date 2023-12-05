/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** starting screen
** starting_screen
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static void init_start(start_s *start)
{
    start->title1 =
    "                               _         _                 ";
    start->title2 =
    " _ __ ___  _   _     ___  ___ | | _____ | |__   __ _ _ __  ";
    start->title3 =
    "| '_ ` _ \\| | | |   / __|/ _ \\| |/ / _ \\| '_ \\ / _` | '_ \\ ";
    start->title4 =
    "| | | | | | |_| |   \\__ \\ (_) |   < (_) | |_) | (_| | | | |";
    start->title5 =
    "|_| |_| |_|\\__, |___|___/\\___/|_|\\_\\___/|_.__/ \\__,_|_| |_|";
    start->title6 =
    "           |___/_____|    (created by Killian QUINTIN)     ";
    start->instruction1 = "press 'space' to play";
    start->instruction2 = "press 'enter' to leave";
}

static void print_start_title(start_s *start)
{
    mvprintw(LINES / 2 - 3, COLS / 2 - my_strlen(start->title1) / 2,
    "%s", start->title1);
    mvprintw(LINES / 2 - 2, COLS / 2 - my_strlen(start->title2) / 2,
    "%s", start->title2);
    mvprintw(LINES / 2 - 1, COLS / 2 - my_strlen(start->title3) / 2,
    "%s", start->title3);
    mvprintw(LINES / 2 - 0, COLS / 2 - my_strlen(start->title4) / 2,
    "%s", start->title4);
    mvprintw(LINES / 2 + 1, COLS / 2 - my_strlen(start->title5) / 2,
    "%s", start->title5);
    mvprintw(LINES / 2 + 2, COLS / 2 - my_strlen(start->title6) / 2,
    "%s", start->title6);
    mvprintw(LINES - 2, 0, "%s", start->instruction1);
    mvprintw(LINES - 1, 0, "%s", start->instruction2);
}

int starting_screen(void)
{
    start_s start;
    int key;

    init_start(&start);
    clear();
    start_terminal_size_error();
    print_start_title(&start);
    key = getch();
    while (key != 10) {
        start_terminal_size_error();
        clear();
        if (key == 32)
            return 1;
        print_start_title(&start);
        key = getch();
    }
    return 0;
}
