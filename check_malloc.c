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

int return_signal(int status)
{
    if (WTERMSIG(status) == SIGSEGV && __WCOREDUMP(status)) {
        my_printf("Segmentation fault (core dumped)\n");
        return 139;
    }
    if (WTERMSIG(status) == SIGSEGV && !__WCOREDUMP(status)) {
        my_printf("Segmentation fault\n");
        return 139;
    }
}
