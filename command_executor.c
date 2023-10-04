#include "shell.h"
/**
* command_executor - executes the command and creates a child process
* @command: the command to be executed
*/
void command_executor(const char *command)
{
	pid_t child_process_id = fork();

	if (child_process_id == -1)
	{
		perror("fork Error");
		exit(EXIT_FAILURE);
	}
	else if (child_process_id == 0)
	{
		execlp(command, command, (char *)NULL);
		perror("execlp");
		exit(EXIT_SUCCESS);
	}
	else
		wait(NULL);
}
