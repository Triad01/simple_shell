#include "shell.h"
/**
 * command_executor - executes the command and creates a child process
 * @command: the command to be executed
 */
void command_executor(const char *command)
{
	pid_t child_process_id = fork();
	char **args = NULL;
	char *env[] = { "PATH=/bin", NULL };

	if (child_process_id == -1)
	{
		perror("fork Error");
		exit(EXIT_FAILURE);
	}
	else if (child_process_id == 0)
	{
		args = (char **)malloc(2 * sizeof(char *));
		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		args[0] = (char *)command;
		args[1] = NULL;

		execve(command, args, env);
		perror("execve");
		free(args);
		exit(EXIT_SUCCESS);
	}
	else
		wait(NULL);
}

