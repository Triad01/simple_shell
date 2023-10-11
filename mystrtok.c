#include "shell.h"
/**
 * mystrtok - tokenization of string
 * @string: string to be tokenized
 * @delim: parsing of eaching string
 * Return: tokenptr
 */

char *mystrtok(char *string, const char *delim)
{
	static char *last_token;
	char *token_start;
	char *tokenptr;

	if (string != NULL)
	{
		last_token = string;
	}

	while (*last_token != '\0' && strchr(delim, *last_token) != NULL)
	{
		last_token++;
	}

	if (*last_token == '\0')
	{
		return (NULL);
	}

	token_start = last_token;

	while (*last_token != '\0' && strchr(delim, *last_token) == NULL)
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

