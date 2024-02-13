/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-selim.bouasker
** File description:
** intern_com.c
*/

#include "shell_one.h"
#include <stdbool.h>

void env_command()
{
    extern char **environ;
    char **env = environ;

    for (int i = 0; env[i] != NULL; i ++) {
        my_printf("%s\n", env[i]);
    }
}

int check_args_unsetenv(params_t *params)
{
    int num_of_args = 0;

    for (int i = 0; params->token_list[i] != NULL; i++) {
        num_of_args++;
    }
    if (num_of_args != 2 || my_str_isalpha(params->token_list[1]) == 1)
        return 1;
    return 0;
}

int unsetenv_cmd(params_t *params)
{
    extern char **environ;
    char **env = environ;

    if (params->number_token > 1)
        params->token_list[1][my_strlen(params->token_list[1]) - 1] = '\0';
    if (check_args_unsetenv(params) == 1)
        exit(84);
    for (int i = 0; env[i] != NULL; i++) {
            if (my_strncmp(env[i], params->token_list[1],
                my_strlen(params->token_list[1])) == 0) {
                env[i] = NULL;
                return 0;
            }
    }
    my_printf("unsetenv: %s: variable not found\n", params->token_list[1]);
    return 1;
}
