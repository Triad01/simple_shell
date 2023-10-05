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
<<<<<<< HEAD
	custom_printf((cwd);
=======
	custom_printf(cwd);
	custom_printf("$ ");
>>>>>>> be49444093001eb6e929dd1979643886c660692c
}
