/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-selim.bouasker
** File description:
** extern_com.c
*/

#include "shell_one.h"

int pwd_command()
{
    char buffer[4096];

    if (getcwd(buffer, sizeof(buffer)) == NULL) {
        return 1;
    }
    my_printf("%s\n", getcwd(buffer, sizeof(buffer)));
    return 0;
}

int ls_command(params_t *params)
{
    char *ls_path = "/bin/ls";
    pid_t pid = fork();

    if (pid < 0) {
        my_printf("Invalid pid\n");
        return 2;
    }
    if (pid == 0) {
        if (execve(ls_path, params->token_list, NULL) == -1) {
            return 2;
        }
    } else {
        waitpid(pid, NULL, 0);
    }
    return 0;
}
