/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-selim.bouasker
** File description:
** intern_com.c
*/

#include "shell_one.h"

int env_command()
{
    extern char **environ;
    char **env = environ;

    for (int i = 0; env[i] != NULL; i ++) {
        printf("%s\n", env[i]);
    }
}
