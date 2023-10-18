#include "shell.h"

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
	char *myenv[] = {NULL};
	pid_t child_process_id = fork();

	if (child_process_id == -1)
	{
		perror("fork Error");
		exit(EXIT_FAILURE);
	}
	else if (child_process_id == 0)
	{
		char *token = strtok((char *)command_line, delim);
		int input_redirect_fd = -1;

		while (token != NULL)
		{
			if (strcmp(token, "<") == 0)
			{
				token = strtok(NULL, delim);
				if (token != NULL)
				{
					input_redirect_fd = open(token, O_RDONLY);
					if (input_redirect_fd == -1)
					{
						perror("input redirection");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					perror("Missing filename for input redirection");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				args[argument_count++] = token;
			}
			token = strtok(NULL, delim);
		}
		args[argument_count] = NULL;

		if (input_redirect_fd != -1)
		{
			if (dup2(input_redirect_fd, STDIN_FILENO) == -1)
			{
				perror("dup2 for input redirection");
				exit(EXIT_FAILURE);
			}
			close(input_redirect_fd);
		}

		if (strcmp(args[0], "clear") == 0)
		{
			if (system("clear") == -1)
			{
				perror("clear");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}

		if (execve(args[0], args, myenv) == -1)
		{
			char *path_envs = getenv("PATH");
			char *path_copy = strdup(path_envs);
			char *paths = strtok(path_copy, ":");

			free(path_copy);
			while (paths != NULL)
			{
				char full_paths[256];

				snprintf(full_paths, sizeof(full_paths), "%s/%s", paths, args[0]);
				if (execve(full_paths, args, myenv) != -1)
				{
					exit(EXIT_SUCCESS);
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
