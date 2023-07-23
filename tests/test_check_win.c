/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_check_win
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

Test(check_winner, test_check_win_ia)
{
    int result;
    int turn = IA;
    result = check_winner(turn);
    cr_assert_eq(result, 2);
}

Test(check_winner, test_check_win_player)
{
    int result;
    int turn = PLAYER;
    result = check_winner(turn);
    cr_assert_eq(result, 1);
}