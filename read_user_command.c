#include "shell.h"
/**
* read_user_command - parses the command entered by the user
* @command: the command to be parsed
* @size: size of the command to be read
*/
void read_user_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			custom_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			custom_printf("Error while trying to parse input\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
