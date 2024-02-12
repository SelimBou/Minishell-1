/*
** EPITECH PROJECT, 2023
** cpoolday04
** File description:
** Infos
*/
#include "shell_one.h"

int my_putstr(char *str)
{
    int c = 0;

    while (str[c] != '\0') {
        my_putchar(str[c]);
        c = c + 1;
    }
    return 0;
}
