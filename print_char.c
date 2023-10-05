#include "shell.h"
/**
  * printchar - prints a character
  * @c: Takes a parameter c, which is a char
  * Return: number of bytes/characters written
  */
int printchar(char c)
{
	return (write(1, &c, 1));
}

