/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-selim.bouasker
** File description:
** intern_com.c
*/

#include "shell_one.h"

int cd_command(params_t *params)
{
    if (params->number_token > 2) {
        my_printf("cd: Trop d'arguments.\n");
        return 1;
    }
    if (params->number_token == 1) {
        if (chdir("/") != 0) {
            return 1;
        }
    }
    if (params->number_token == 2) {
        if (chdir(params->token_list[1]) != 0) {
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
    if (num_of_args != 2 || is_alpha(params->token_list[1][0]) == 1 ||
        alpha_num(params->token_list[1]) == 1)
        return 1;
    return 0;
}

int unsetenv_cmd(params_t *params)
{
    extern char **environ;
    char **env = environ;

    if (check_args_unsetenv(params) == 1) {
        my_printf("wrong args\n");
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

static int check_malloc(params_t *params)
{
    if (params->new_value == NULL)
        return 1;
}

static int check_args_setenv(params_t *params)
{
    if (params->number_token > 3 || params->number_token < 2 ||
        is_alpha(params->token_list[1][0]) == 1 ||
        alpha_num(params->token_list[1]) == 1)
        return 1;
    return 0;
}

static void verif(params_t *params)
{
    if (params->number_token == 2) {
        params->new_value = malloc(my_strlen(params->token_list[1]) + 2);
        check_malloc(params);
        my_strcpy(params->new_value, params->token_list[1]);
        my_strcat(params->new_value, "=");
        my_strcat(params->new_value, "\0");
    } else {
        params->new_value = malloc(my_strlen(params->token_list[1])
        + my_strlen(params->token_list[2]) + 2);
        check_malloc(params);
        my_strcpy(params->new_value, params->token_list[1]);
        my_strcat(params->new_value, "=");
        my_strcat(params->new_value, params->token_list[2]);
    }
}

int setenv_cmd(params_t *params)
{
    extern char **environ;
    char **env = environ;
    int n = 0;

    if (check_args_setenv(params) == 1) {
        my_printf("wrong args\n");
        return 1;
    }
    verif(params);
    for (int i = 0; env[i] != NULL; i ++) {
        if (my_strncmp(env[i], params->token_list[1],
            my_strlen(params->token_list[1])) == 0) {
            env[i] = params->new_value;
            return 0;
        }
        n = i;
    }
    env[n + 1] = params->new_value;
    env[n + 2] = NULL;
    return 0;
}
