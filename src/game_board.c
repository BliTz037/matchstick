/*
** EPITECH PROJECT, 2020
** game_board.c
** File description:
** game_board
*/

#include "matchstick.h"

char **get_game_board(int line_stick)
{
    char **game_board = NULL;
    int line_game_board = line_stick + 2;
    int cols_line = (line_stick * 2 + 1);
    int r = 0;
    int c = 0;

    game_board = (char **) malloc(sizeof(char *) * line_game_board);
    if (game_board == NULL)
        return (NULL);
    for (int i = 0; i != line_game_board; i++)
        game_board[i] = malloc(sizeof(char) * cols_line + 1);

    for (; r < line_game_board; r++) {
        for (c = 0; c < cols_line; c++)
            game_board[r][c] = '*';
        game_board[r][c] = '\0';
    }
    game_board = set_stick(game_board, line_game_board, cols_line - 2);
    return (game_board);
}

char **set_stick(char **game_board, int line_gb, int cols_line)
{
    int i = 1;
    int space = 0;

    for (int r = line_gb - 2; r != 0; r--, space++) {
        for (int s = 0; s != space; s++) {
            game_board[r][i] = ' ';
            i++;
        }
        for (int s = 0; s != cols_line; s++) {
            game_board[r][i] = '|';
            i++;
        }
        for (int s = 0; s != space; s++) {
            game_board[r][i] = ' ';
            i++;
        }
        cols_line -= 2;
        i = 1;
    }
    return (game_board);
}

void print_game_board(char **gb, int line_stick)
{
    for (int i = 0; i < line_stick + 2; i++) {
        my_putstr(gb[i]);
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}

int stick_len(char **game_board, int line)
{
    int len = 0;
    for (int i = 0; game_board[line][i] != '\0'; i++) {
        if (game_board[line][i] == '|')
            len++;
    }
    return (len);
}

int all_stick_len(char **game_board, int line_stick)
{
    int len = 0;

    for (int i = 1; i != line_stick + 1; i++) {
        len += stick_len(game_board, i);
    }
    return (len);
}