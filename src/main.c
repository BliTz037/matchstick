/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "matchstick.h"

int main(int ac, char **av)
{
    int line_stick = 0;
    int max_match = 0;

    if (ac != 3)
        return (84);
    line_stick = my_getnbr(av[1]);
    max_match = my_getnbr(av[2]);
    if (check_argument(line_stick, max_match) == 1)
        return (84);
    return (matchstick(line_stick, max_match));
}