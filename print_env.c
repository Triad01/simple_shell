#include "shell.h"
/**
* print_env - prints environment variable to stdout
* @env: null terminated string of environment variables
*/
void print_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		custom_printf(env[i]);
		_putchar('\n');
	}
}
