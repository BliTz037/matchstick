/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_check_read_match
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

void redirect_all_std(void);

Test(check_read_match, test_check_read_match1, .init = redirect_all_std)
{
    char *match = "b5";
    int max_match = 5;
    int line = 5;
    char **gb = get_game_board(line);
    char *check = "Error: invalid input (positive number expected)\n";

    check_read_match(match, max_match, line, gb);
    cr_assert_stdout_eq_str(check);
}

Test(check_read_match, test_check_read_match2, .init = redirect_all_std)
{
    char *match = "0";
    int max_match = 5;
    int line = 5;
    char **gb = get_game_board(line);

    check_read_match(match, max_match, line, gb);
    cr_assert_stdout_eq_str("Error: you have to remove at least one match\n");
}

Test(check_read_match, test_check_read_match3, .init = redirect_all_std)
{
    char *match = "6";
    int max_match = 5;
    int line = 5;
    char **gb = get_game_board(line);
    char *check = "Error: you cannot remove more than 5 matches per turn\n";

    check_read_match(match, max_match, line, gb);
    cr_assert_stdout_eq_str(check);
}

Test(check_read_match, test_check_read_match4, .init = redirect_all_std)
{
    char *match = "5";
    int max_match = 5;
    int line = 1;
    char **gb = get_game_board(line);
    char *check = "Error: not enough matches on this line\n";

    check_read_match(match, max_match, line, gb);
    cr_assert_stdout_eq_str(check);
}

Test(check_read_match, test_check_read_match5)
{
    int result;
    char *match = "1";
    int max_match = 5;
    int line = 1;
    char **gb = get_game_board(line);

    result = check_read_match(match, max_match, line, gb);
    cr_assert_eq(result, 0);
}