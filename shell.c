#include "shell.h"
/**
* main - main entry into our program
* Return: always an integer
*/
int main(void)
{
	char command[120];

	do
	{
		display_prompt();
		read_user_command(command, sizeof(command));
		command_executor(command);
	}
	while(true);
	return (0);
}
