/*
** EPITECH PROJECT, 2020
** interaction.c
** File description:
** interaction
*/

#include "matchstick.h"

void print_player_action(int nb_line, int nb_match)
{
    my_putstr("Player removed ");
    my_put_nbr(nb_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(nb_line);
    write(1, "\n", 1);
}

char **print_updated_gb(char **gb, int line_stick, int line, int nb_matches)
{
    int stick_remove = 0;

    for (int i = (2 * line_stick + 1); stick_remove != nb_matches; i--) {
        if (gb[line][i] == '|') {
            gb[line][i] = ' ';
            stick_remove++;
        }
    }
    print_game_board(gb, line_stick);
    return (gb);
}

char **read_player_interact(char **gb, int line_stick, int max_match)
{
    char *line = NULL;
    char *match = NULL;
    size_t len = 0;
    int nb_line = 0;
    int nb_match = 0;

    my_putstr("Line: ");
    if (getline(&line, &len, stdin) == -1)
        return (NULL);
    if (check_read_line(line, line_stick) == 1)
        return (read_player_interact(gb, line_stick, max_match));
    my_putstr("Matches: ");
    if (getline(&match, &len, stdin) == -1)
        return (NULL);
    if (check_read_match(match, max_match, my_getnbr(line), gb) == 1)
        return (read_player_interact(gb, line_stick, max_match));
    nb_line = my_getnbr(line);
    nb_match = my_getnbr(match);
    print_player_action(nb_line, nb_match);
    return (print_updated_gb(gb, line_stick, nb_line, nb_match));
}
