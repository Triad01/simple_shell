#include "shell.h"
/**
 * read_user_command - parses the command entered by the user
 * @command: the command to be parsed
 * @size: size of the command to be read
 */
void read_user_command(char **command, size_t *size)
{
	ssize_t read;

	read = _getline(command, size);

	if (read == -1)
	{
		if (*command == NULL)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		if (feof(stdin))
		{
			custom_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	if ((*command)[read - 1] == '\n')
	{
		(*command)[read - 1] = '\0';
		*size = strlen(*command);
	}
}
