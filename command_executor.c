#include "shell.h"
/**
 * command_executor - executes the command and creates a child process
 * @command_line: the command to be executed
 */
void command_executor(const char *command_line)
{
	pid_t child_process_id = fork();
	char *token, *args[128];
	int argument_count;
	char *env[] = { "PATH=/bin", NULL };
	char *delim = " \n";

	if (child_process_id == -1)
	{
		perror("fork Error");
		exit(EXIT_FAILURE);
	}
	else if (child_process_id == 0)
	{
		token = strtok((char *)command_line, delim);
		while (token != NULL)
		{
			args[argument_count++] = token;
			token = strtok(NULL, delim);
		}
		args[argument_count] = NULL;

		if (execve(args[0], args, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}
