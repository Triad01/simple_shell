#include "shell.h"
/**
* main - main entry into our program
* @argc: argument count
* @argv: argument variables
* @env: environment variables
* Return: always an integer
*/
int main(int argc, char *argv[], char **env)
{
	char *command;
	size_t size;
	(void) argc;
	(void) argv;

	command = NULL;

	do {
		if (isatty(0))
			display_prompt();
		read_user_command(&command, &size);
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}
		if (strcmp(command, "env") == 0 || strcmp(command, "printenv") == 0)
			print_env(env);
		command_executor(command);
	} while (true);

	return (0);
}
