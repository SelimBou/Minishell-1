/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-selim.bouasker
** File description:
** shell_one.h
*/

#ifndef SHELL_ONE
    #define SHELL_ONE
    #include <stdbool.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #include <fcntl.h>
typedef struct params {
    char **token_list;
    int number_token;
} params_t;
int unsetenv_cmd(params_t *params);
int cd_command(params_t *params);
void env_command(void);
int ls_command(params_t *params);
int pwd_command(void);
char my_putchar(char c);
int my_printf(const char *format, ...);
int my_putstr(char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char *src);
int my_strcmp(const char *str1, const char *str2);
char *my_strdup(char *str);
bool my_str_isalpha(const char *str);
int my_strncmp(const char *s1, const char *s2, size_t n);
#endif
