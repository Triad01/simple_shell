#include "shell.h"
extern char **environ;
/**
* command_executor - executes the command and creates a child process
* @command_line: the command to be executed
*/
void command_executor(const char *command_line);
void command_executor(const char *command_line)
{
	char *args[128];
	int argument_count = 0;
	char *delim = " \n";

	pid_t child_process_id = fork();

	if (child_process_id == -1)
	{
		perror("fork Error");
		exit(EXIT_FAILURE);
	}
	else if (child_process_id == 0)
	{
		char *token = strtok((char *)command_line, delim);

		while (token != NULL)
		{
			args[argument_count++] = token;
			token = strtok(NULL, delim);
		}
			args[argument_count] = NULL;

		if (strchr(args[0], '/') != NULL)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *path_envs = getenv("PATH");
			char *paths = strtok(path_envs, ":");
			while (paths != NULL)
			{	
				char full_paths[256];
				snprintf(full_paths, sizeof(full_paths), "%s/%s", paths, args[0]);
				if (execve(full_paths, args, environ) != -1)
				{
					return;
				}
				paths = strtok(NULL, ":");
			}
				perror("execve");
				exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
