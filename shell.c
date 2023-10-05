#include "shell.h"
/**
* main - main entry into our program
* Return: always an integer
*/
int main(void)
{
	char *command;

	command = malloc(sizeof(command));

	if (command == NULL)
	{
		perror("Memory allocatioin fail\n");
		exit(EXIT_FAILURE);
	}



	do {
		display_prompt();
		read_user_command(command, sizeof(command));
		command_executor(command);
	} while (true);

	free(command);
	return (0);
}
