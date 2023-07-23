/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** check_argument
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

void redirect_all_std(void);

Test(check_argument, test_check_args)
{
    int result;
    result = check_argument(101, 5);
    cr_assert_eq(result, 1);
}

Test(check_argument, test_check_args2)
{
    int result;
    result = check_argument(5, -1);
    cr_assert_eq(result, 1);
}

Test(check_argument, test_check_args3)
{
    int result;
    result = check_argument(5, 5);
    cr_assert_eq(result, 0);
}