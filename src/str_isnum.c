/*
** EPITECH PROJECT, 2020
** str_isnum.c
** File description:
** str_isnum
*/

#include "matchstick.h"

int str_isnum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[0] == '-')
            i++;
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '\n')
            i++;
        else
            return (1);
    }
    return (0);
}