/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** end screen
** end_screen
*/

#include "include/my.h"
#include "include/my_sokoban.h"

static void print_win_title(void)
{
    char *title1 = " _   _  ___  _   _  __      _____  _ __  ";
    char *title2 = "| | | |/ _ \\| | | | \\ \\ /\\ / / _ \\| '_ \\ ";
    char *title3 = "| |_| | (_) | |_| |  \\ V  V / (_) | | | |";
    char *title4 = " \\__, |\\___/ \\__,_|   \\_/\\_/ \\___/|_| |_|";
    char *title5 = " |___/                                   ";
    char *instruction =
    "press 'space' to go back to the main menu or 'enter' to leave";

    mvprintw(LINES / 2 - 2, COLS / 2 - my_strlen(title1) / 2, "%s", title1);
    mvprintw(LINES / 2 - 1, COLS / 2 - my_strlen(title2) / 2, "%s", title2);
    mvprintw(LINES / 2 - 0, COLS / 2 - my_strlen(title3) / 2, "%s", title3);
    mvprintw(LINES / 2 + 1, COLS / 2 - my_strlen(title4) / 2, "%s", title4);
    mvprintw(LINES / 2 + 2, COLS / 2 - my_strlen(title5) / 2, "%s", title5);
    mvprintw(LINES - 1, 0, "%s", instruction);
}

static void print_lose_title(void)
{
    char *title1 = "                     _           _   ";
    char *title2 = " _   _  ___  _   _  | | ___  ___| |_ ";
    char *title3 = "| | | |/ _ \\| | | | | |/ _ \\/ __| __|";
    char *title4 = "| |_| | (_) | |_| | | | (_) \\__ \\ |_ ";
    char *title5 = " \\__, |\\___/ \\__,_| |_|\\___/|___/\\__|";
    char *title6 = " |___/                               ";
    char *instruction =
    "press 'space' to go back to the main menu or 'enter' to leave";

    mvprintw(LINES / 2 - 3, COLS / 2 - my_strlen(title1) / 2, "%s", title1);
    mvprintw(LINES / 2 - 2, COLS / 2 - my_strlen(title2) / 2, "%s", title2);
    mvprintw(LINES / 2 - 1, COLS / 2 - my_strlen(title3) / 2, "%s", title3);
    mvprintw(LINES / 2 - 0, COLS / 2 - my_strlen(title4) / 2, "%s", title4);
    mvprintw(LINES / 2 + 1, COLS / 2 - my_strlen(title5) / 2, "%s", title5);
    mvprintw(LINES / 2 + 2, COLS / 2 - my_strlen(title6) / 2, "%s", title6);
    mvprintw(LINES - 1, 0, "%s", instruction);
}

int end_screen(int i)
{
    int key;

    clear();
    if (i)
        print_win_title();
    else
        print_lose_title();
    key = getch();
    while (key != 10) {
        // terminal_size_error(game);
        clear();
        if (key == 32)
            return 1;
        if (i)
            print_win_title();
        else
            print_lose_title();
        key = getch();
    }
    return 0;
}
