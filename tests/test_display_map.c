/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_display_map
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

void redirect_all_std(void);

Test(print_game_board, print_1x1, .init = redirect_all_std)
{
    int line_stick = 1;
    char **gb = get_game_board(line_stick);
    print_game_board(gb, line_stick);
    cr_assert_stdout_eq_str("***\n*|*\n***\n\n");
}

Test(print_game_board, print_2x2, .init = redirect_all_std)
{
    int line_stick = 2;
    char **gb = get_game_board(line_stick);
    print_game_board(gb, line_stick);
    cr_assert_stdout_eq_str("*****\n* | *\n*|||*\n*****\n\n");
}

Test(print_game_board, print_3x3, .init = redirect_all_std)
{
    int line_stick = 3;
    char **gb = get_game_board(line_stick);
    print_game_board(gb, line_stick);
    cr_assert_stdout_eq_str("*******\n*  |  *\n* ||| *\n*|||||*\n*******\n\n");
}