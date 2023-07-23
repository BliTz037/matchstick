/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
}
