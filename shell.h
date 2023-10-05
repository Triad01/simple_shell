#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
int custom_printf(const char *output_string);
void display_prompt(void);
void command_executor(const char *command);
void read_user_command(char **command, size_t *size);
#endif
