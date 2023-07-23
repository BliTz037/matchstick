/*
** EPITECH PROJECT, 2020
** matchstick.h
** File description:
** matchstick
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

enum turn {PLAYER, IA};
int check_argument(int line_stick, int max_match);
int check_read_line(char *line, int line_stick);
int check_read_match(char *match, int max_match, int line, char **gb);
int check_winner(int turn);
int matchstick(int line_stick, int max_match);
int stick_len(char **game_board, int line);
int all_stick_len(char **game_board, int line_stick);
int total_xor(char **gb, int line_stick);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int str_isnum(char *str);
char **get_game_board(int line_stick);
char **set_stick(char **game_board, int line_gb, int cols_line);
char **print_updated_gb(char **gb, int line_stick, int line, int nb_matches);
char **play_ia(char **gb, int line_stick, int max_match);
char **read_player_interact(char **gb, int line_stick, int max_match);
char **get_game_board(int line_stick);
void print_player_action(int nb_line, int nb_match);
void print_ia_action(int nb_line, int nb_match);
void print_game_board(char **gb, int line_stick);
void my_putchar(char c);
void my_putstr(char const *str);
#endif
