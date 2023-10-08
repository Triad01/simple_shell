#include "shell.h"
/**
* main - main entry into our program
* Return: always an integer
*/
int main(void)
{
	char *command;
	size_t size;

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
		command_executor(command);
	} while (true);

	return (0);
}
