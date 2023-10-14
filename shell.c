#include "shell.h"

/**
 * main - main entry into our program
 * @argc: argument count
 * @argv: argument variables
 * @env: environment variables
 * Return: always returns an integer
 */
int main(int argc, char *argv[], char **env)
{
	char *command;
	size_t size;
	int exit_status;
	size_t newline_pos;

	(void)argc;
	(void)argv;

	command = NULL;
	exit_status = 0;

	do {
		if (isatty(0) == 1)
			display_prompt();
		read_user_command(&command, &size);

		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else if (strncmp(command, "exit ", 5) == 0)
		{
			exit_status = atoi(command + 5);
			break;
		}
		else if (strcmp(command, "env") == 0 || strcmp(command, "printenv") == 0)
			print_env(env);
		command_executor(command);


		newline_pos = strcspn(command, "\n");
		if (newline_pos < size)
			command[newline_pos] = '\0';

		if (command != NULL)
			command = NULL;
	} while (true);

	return (exit_status);
}

