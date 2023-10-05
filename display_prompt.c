#include "shell.h"
/**
* display_prompt - displays a prompt for users to enter command
*
*/
void display_prompt(void)
{
	char cur_working_dir[1024];

	if (getcwd(cur_working_dir, sizeof(cur_working_dir)) == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	custom_printf(cur_working_dir);
	custom_printf("$ ");
}
