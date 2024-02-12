/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-selim.bouasker
** File description:
** shell_one.h
*/

#ifndef SHELL_ONE
    #define SHELL_ONE
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
char my_putchar(char c);
int my_printf(const char *format, ...);
int my_putstr(char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char *src);
int my_strcmp(const char *str1, const char *str2);
char *my_strdup(char *str);
#endif
