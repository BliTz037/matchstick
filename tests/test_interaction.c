/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_interaction
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

void redirect_all_std(void);

Test(print_player_action, test_print_player_action, .init = redirect_all_std)
{
    int nb_line = 5;
    int nb_match = 3;
    print_player_action(nb_line, nb_match);
    cr_assert_stdout_eq_str("Player removed 3 match(es) from line 5\n");
}

Test(print_ia_action, test_print_ia_action, .init = redirect_all_std)
{
    int nb_line = 5;
    int nb_match = 3;
    print_ia_action(nb_line, nb_match);
    cr_assert_stdout_eq_str("AI removed 3 match(es) from line 5\n");
}