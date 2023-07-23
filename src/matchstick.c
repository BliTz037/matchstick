/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** matchstick
*/

#include "matchstick.h"

int check_winner(int turn)
{
    if (turn == PLAYER) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    if (turn == IA) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
}

int matchstick(int line_stick, int max_match)
{
    int turn = PLAYER;
    char **gb = get_game_board(line_stick);
    if (gb == NULL)
        return (84);
    print_game_board(gb, line_stick);
    while (all_stick_len(gb, line_stick) != 0) {
        if (turn == PLAYER) {
            my_putstr("Your turn:\n");
            gb = read_player_interact(gb, line_stick, max_match);
            if (gb == NULL)
                return (0);
            turn = IA;
        }
        else {
            my_putstr("AI's turn...\n");
            gb = play_ia(gb, line_stick, max_match);
            turn = PLAYER;
        }
    }
    return (check_winner(turn));
}