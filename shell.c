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
	(void) argc;
	(void) argv;

	command = NULL;

	do {
		if (isatty(0) == 1)
			display_prompt();
		read_user_command(&command, &size);
		if (strcasecmp(command, "exit") == 0)
		{
			break;
		}
		if (strcasecmp(command, "env") == 0 || strcasecmp(command, "printenv") == 0)
			print_env(env);
		command_executor(command);
		if (command != NULL)
		{
			free(command);
			command = NULL;
		}
	} while (true);
	return (0);
}
