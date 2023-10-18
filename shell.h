#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MY_EOF (-1)
int _putchar(char chararter);
int custom_printf(const char *output_string);
void display_prompt(void);
void command_executor(const char *command);
void read_user_command(char **command, size_t *size);
void print_env(char **env);
void _cd_check(char *commands);
ssize_t _getline(char **lineptr, size_t *n, int fd);
#endif
