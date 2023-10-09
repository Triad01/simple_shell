#include "shell.h"
#include <unistd.h>
/**
* _putchar - prints a character to the stdout
* @character: character to be printed out
* Return: always an integer
*/
int _putchar(char character)
{
	return (write(STDOUT_FILENO, &character, 1));
}
