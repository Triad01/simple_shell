#include "shell.h"
/**
 * _strtok - tokenization of string
 * @string: string to be tokenized
 * @delimiter: parsing of eaching string
 * Return: tokenptr
 */

char *_strtok(char *string, char *delimiter)
{
	static char *last_token;
	char *token_start;
	char *tokenptr;
	int i = 0;

	if (string != NULL)
	{
		last_token = string;
	}

	while (*last_token != '\0' && strchr(delimiter, *last_token) != NULL)
	{
		last_token++;
	}

	if (*last_token == '\0')
	{
		return (NULL);
	}

	token_start = last_token;

	while (*last_token != '\0' && strchr(delimiter, *last_token) == NULL)
	{
		last_token++;
	}

	tokenptr = malloc(last_token - token_start + 1);

	if (tokenptr == NULL)
	{
		perror("memory allocation error");
		exit(EXIT_FAILURE);
	}

	strncpy(tokenptr, token_start, last_token - token_start);
	tokenptr[last_token - token_start] = '\0';

	return (tokenptr);
}
