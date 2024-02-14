/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-selim.bouasker
** File description:
** intern_com.c
*/

#include "shell_one.h"
#include <stdbool.h>

int cd_command(params_t *params)
{
    if (params->number_token > 2) {
        perror("cd: too many arguments");
        return 1;
    }
    if (params->number_token == 1) {
        if (chdir("/") != 0) {
            perror("cd");
            return 1;
        }
    }
    if (params->number_token == 2) {
        if (chdir(params->token_list[1]) != 0) {
            perror("cd");
            return 1;
        }
    }
    return 0;
}

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

    if (check_args_unsetenv(params) == 1) {
        perror("missing args");
        return 1;
    }
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

int setenv_cmd(params_t *params)
{
    extern char **environ;
    char **env = environ;
    int n = 0;
    char *new_value = malloc(strlen(params->token_list[1])
    + strlen(params->token_list[2]) + 2);

    if (new_value == NULL) {
        return 1;
    }
    strcpy(new_value, params->token_list[1]);
    strcat(new_value, "=");
    strcat(new_value, params->token_list[2]);
    for (int i = 0; env[i] != NULL; i ++) {
        n = i;
    }
    env[n] = new_value;
    return 0;
}
