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
int _putchar(char chararter);
int custom_printf(const char *output_string);
void display_prompt(void);
void command_executor(const char *command);
void read_user_command(char **command, size_t *size);
void print_env(char **env);
ssize_t _getline(char **buffer, size_t *static_size);
#endif
