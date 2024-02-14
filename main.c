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
    if (my_strcmp(params->token_list[0], "ls") == 0)
        ls_command(params);
    if (my_strcmp(params->token_list[0], "pwd") == 0)
        pwd_command();
    if (my_strcmp(params->token_list[0], "echo") == 0)
        return 0;
}

static int verify_command(params_t *params)
{
    if (my_strcmp(params->token_list[0], "cd") == 0 ||
        my_strcmp(params->token_list[0], "setenv") == 0 ||
        my_strcmp(params->token_list[0], "unsetenv") == 0 ||
        my_strcmp(params->token_list[0], "env") == 0 ||
        my_strcmp(params->token_list[0], "exit") == 0 ||
        my_strcmp(params->token_list[0], "ls") == 0 ||
        my_strcmp(params->token_list[0], "pwd") == 0 ||
        my_strcmp(params->token_list[0], "echo") == 0) {
            which_command(params);
        } else {
            perror("Invalid command");
            return 1;
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
    params.token_list[i - 1][my_strlen(params.token_list[i - 1]) - 1] = '\0';
    params.token_list[i] = NULL;
    verify_command(&params);
}

int start_shell(void)
{
    char *line = NULL;
    char current_dir[BUF_SIZE];
    size_t len = 0;
    size_t read;

    getcwd(current_dir, sizeof(current_dir));
    my_printf("[$>%s]", current_dir);
    read = getline(&line, &len, stdin);
    while (read != -1) {
        args_to_token(line);
        getcwd(current_dir, sizeof(current_dir));
        my_printf("[$>%s]", current_dir);
        read = getline(&line, &len, stdin);
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 1) {
        write(2, "Error in num of args\n", 22);
        return 84;
    } else {
        start_shell();
    }
    return 0;
}
