/*
** EPITECH PROJECT, 2020
** ia.c
** File description:
** ia
*/

#include "matchstick.h"

void print_ia_action(int nb_line, int nb_match)
{
    my_putstr("AI removed ");
    my_put_nbr(nb_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(nb_line);
    write(1, "\n", 1);
}

int total_xor(char **gb, int line_stick)
{
    int x = 0;
    int len_stick = 0;

    for (int i = 1; i != line_stick + 1; i++)
        len_stick = stick_len(gb, i);
    x = x ^ len_stick;
    len_stick = 0;
    return (x);
}

char **play_ia(char **gb, int line_stick, int max_match)
{
    int xor = total_xor(gb, line_stick);
    int line_rm = 0;
    int result = 0;
    int len_stick = 0;
    int stick_rm = 0;

    for (int i = 1; i != line_stick + 1; i++) {
        len_stick = stick_len(gb, i);
        result = len_stick ^ xor;
        if (result <= len_stick && len_stick != 0)
            line_rm = i;
    }
    len_stick = stick_len(gb, line_rm);
    stick_rm = len_stick - (xor ^ len_stick);
    if (stick_rm == 0)
        stick_rm++;
    if (stick_rm > max_match)
        stick_rm = max_match;
    print_ia_action(line_rm, stick_rm);
    return (print_updated_gb(gb, line_stick, line_rm, stick_rm));
}
