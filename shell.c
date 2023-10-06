#include "shell.h"
/**
* main - main entry into our program
* Return: always an integer
*/
int main(void)
{
	char *command = NULL;
	size_t size;

	do {
		if (isatty(0))
			display_prompt();
		read_user_command(&command, &size);
		command_executor(command);
	} while (true);

	return (0);
}
