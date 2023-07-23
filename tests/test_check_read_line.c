/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_check_read_line
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

void redirect_all_std(void);

Test(check_read_line, test_check_read_line)
{
    int result;
    char *line = "5b";

    result = check_read_line(line, 5);
    cr_assert_eq(result, 1);
}

Test(check_read_line, test_check_read_line2)
{
    int result;
    char *line = "6";

    result = check_read_line(line, 5);
    cr_assert_eq(result, 1);
}

Test(check_read_line, test_check_read_line3)
{
    int result;
    char *line = "5";

    result = check_read_line(line, 5);
    cr_assert_eq(result, 0);
}