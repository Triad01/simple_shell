#include "shell.h"
/**
* display_prompt - displays a prompt for users to enter command
*
*/
void display_prompt()
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	custom_printf(cwd);
	custom_printf("$ ");
}
