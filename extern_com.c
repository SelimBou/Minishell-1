/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-selim.bouasker
** File description:
** extern_com.c
*/

#include "shell_one.h"

int pwd_command(void)
{
    char buffer[4096];

    if (getcwd(buffer, sizeof(buffer)) == NULL) {
        perror("getcwd");
        return 1;
    }
    printf("%s\n", getcwd(buffer, sizeof(buffer)));
    return 0;
}

int ls_command(params_t *params)
{
    char *ls_path = "/bin/ls";
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 84;
    }
    if (pid == 0) {
        if (execve(ls_path, params->token_list, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
    return 0;
}
