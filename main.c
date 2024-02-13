/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-selim.bouasker
** File description:
** main.c
*/

#include "shell_one.h"

static int which_command(params_t *params)
{
    if (my_strcmp(params->token_list[0], "cd") == 0)
        return 0;
    if (my_strcmp(params->token_list[0], "setenv") == 0)
        return 0;
    if (my_strcmp(params->token_list[0], "unsetenv") == 0)
        unsetenv_cmd(params);
    if (my_strcmp(params->token_list[0], "env") == 0)
        env_command();
    if (my_strcmp(params->token_list[0], "exit") == 0)
        exit(EXIT_SUCCESS);
    if (my_strcmp(params->token_list[0], "ls") == 0)
        ls_command(params);
    if (my_strcmp(params->token_list[0], "pwd") == 0)
        pwd_command();
    if (my_strcmp(params->token_list[0], "echo $?") == 0)
        return 0;
}

static int num_of_tok(char *line)
{
    int number_token = 0;
    char *copy = my_strdup(line);
    char *token = strtok(copy, " ");

    while (token != NULL) {
        number_token++;
        token = strtok(NULL, " ");
    }
    return number_token;
}

static int args_to_token(char *line)
{
    params_t params;
    char *copy;
    char *token;
    int i = 0;

    params.number_token = num_of_tok(line);
    params.token_list = malloc(sizeof(char *) * params.number_token);
    copy = my_strdup(line);
    token = strtok(copy, " ");
    if (params.token_list == NULL)
        return -1;
    while (token != NULL) {
        params.token_list[i] = my_strdup(token);
        token = strtok(NULL, " ");
        i ++;
    }
    if (params.number_token == 1)
        params.token_list[0][my_strlen(params.token_list[0]) - 1] = '\0';
    params.token_list[i] = NULL;
    which_command(&params);
}

int start_shell(void)
{
    char *line = NULL;
    size_t len = 0;
    size_t read;

    my_printf("$> ");
    read = getline(&line, &len, stdin);
    while (read != -1) {
        args_to_token(line);
        my_printf("$> ");
        read = getline(&line, &len, stdin);
    }
    return 0;
}

int main(int argc, char **argv, char **env)
{
    if (argc != 1) {
        write(2, "Error in num of args\n", 22);
        return 84;
    } else {
        start_shell();
    }
    return 0;
}
