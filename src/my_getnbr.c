/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int a = 0;
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            i++;
        }
        if (str[i] < '0' || str[i] > '9') {
            break;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            a = str[i] - '0';
            nb = nb * 10;
            nb = nb + a;
        }
    }
    if (str[0] == '-') {
        nb = nb * -1;
    }
    return (nb);
}
