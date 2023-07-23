/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_len_stick
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

Test(stick_len, test_stick_len)
{
    int result;
    int line_stick = 5;
    char **gb = get_game_board(line_stick);
    result = stick_len(gb, line_stick);
    cr_assert_eq(result, 9);
}

Test(all_stick_len, test_all_stick_len)
{
    int result;
    int line_stick = 5;
    char **gb = get_game_board(line_stick);
    result = all_stick_len(gb, line_stick);
    cr_assert_eq(result, 25);
}