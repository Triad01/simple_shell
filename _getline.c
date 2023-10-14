#include "shell.h"
/**
* _getline - reads user input
* @buffer: stores read input
* @static_size: size of buffer to be read
* Return: a signed integer
*/
ssize_t _getline(char **buffer, size_t *static_size)
{
	static char static_buffer[1024];

	ssize_t num_read;

	*buffer = NULL;

	if (*buffer == NULL)
	{
		*buffer = static_buffer;
	}
	*static_size = sizeof(static_buffer);

	num_read = read(0, *buffer, *static_size);

	if (num_read == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (num_read == 0)
	{
		if (isatty(0))
			custom_printf("\n");
		exit(EXIT_SUCCESS);
	}

	return (num_read);
}
