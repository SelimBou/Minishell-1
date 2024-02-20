/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-selim.bouasker
** File description:
** check_malloc.c
*/

#include "shell_one.h"

int is_malloc_correct(params_t *params)
{
    if (params->token_list == NULL)
        return -1;
}

int check_return(params_t *params)
{
    if (check_args_setenv(params) == 1) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    }
    if (check_args_setenv(params) == 2) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (check_args_setenv(params) == 3) {
        my_printf("setenv: Variable name must contain alphanumeric ");
        my_printf("characters.\n");
        return 1;
    }
}
