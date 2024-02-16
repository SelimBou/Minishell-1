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
        cd_command(params);
    if (my_strcmp(params->token_list[0], "setenv") == 0)
        setenv_cmd(params);
    if (my_strcmp(params->token_list[0], "unsetenv") == 0)
        unsetenv_cmd(params);
    if (my_strcmp(params->token_list[0], "env") == 0)
        env_command();
    if (my_strcmp(params->token_list[0], "exit") == 0)
        exit(EXIT_SUCCESS);
}

static int exe_command(pid_t pid, params_t *params, char **env, char *path)
{
    int status = 0;

    if (pid == 0) {
        if (execve(path, params->token_list, env) == -1) {
            perror("Command not found\n");
            exit(0);
        }
    } else
        wait(&status);
}

static int check_built_in(params_t *params)
{
    if (my_strcmp(params->token_list[0], "cd") == 0 ||
        my_strcmp(params->token_list[0], "setenv") == 0 ||
        my_strcmp(params->token_list[0], "unsetenv") == 0 ||
        my_strcmp(params->token_list[0], "env") == 0 ||
        my_strcmp(params->token_list[0], "exit") == 0) {
            return 0;
    }
}

static int verify_command(params_t *params, char **env)
{
    pid_t pid;
    char *path_init = "/bin/";
    char *path;

    if (check_built_in(params) == 0) {
        which_command(params);
    } else {
        pid = fork();
        if (params->token_list[0][0] != '.') {
            path = malloc(sizeof(char) * (my_strlen(params->token_list[0]) +
                my_strlen(path_init) + 1));
            my_strcpy(path, path_init);
            my_strcat(path, params->token_list[0]);
        }
        exe_command(pid, params, env, path);
    }
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

int args_to_token(char *line, char **env)
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
    params.token_list[i - 1][my_strlen(params.token_list[i - 1]) - 1] = '\0';
    params.token_list[i] = NULL;
    verify_command(&params, env);
}

int start_shell(char **env)
{
    char *line = NULL;
    char current_dir[BUF_SIZE];
    size_t len = 0;
    ssize_t read = 0;

    while (1) {
        if (isatty(0) == 1) {
            getcwd(current_dir, sizeof(current_dir));
            my_printf("[$>%s]", current_dir);
        }
        read = getline(&line, &len, stdin);
        if (read == -1)
            return 0;
        args_to_token(line, env);
    }
    return 0;
}

int main(int argc, char **argv, char **env)
{
    if (argc != 1) {
        write(2, "Error in num of args\n", 22);
        return 84;
    } else {
        start_shell(env);
    }
    return 0;
}
