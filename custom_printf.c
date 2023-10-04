#include "shell.h"
/**
* custom_printf - prints strings/characters to stdout
* @output_string: the string to be out be printed
* Return: always an integer
*/
int custom_printf(const char *output_string)
{
	return (write(STDOUT_FILENO, output_string, strlen(output_string)));
}
