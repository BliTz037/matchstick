/*
** EPITECH PROJECT, 2020
** error.c
** File description:
** error
*/

#include "matchstick.h"

int check_argument(int line_stick, int max_match)
{
    if (line_stick < 1 || line_stick > 100)
        return (1);
    if (max_match <= 0)
        return (1);
    return (0);
}

int check_read_line(char *line, int line_stick)
{
    int nb_line = 0;

    if (str_isnum(line) == 1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    nb_line = my_getnbr(line);
    if (nb_line > line_stick || nb_line < 1) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int check_read_match(char *match, int max_match, int line, char **gb)
{
    if (str_isnum(match) == 1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (my_getnbr(match) < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (my_getnbr(match) > max_match) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(max_match);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (my_getnbr(match) > stick_len(gb, line)) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}