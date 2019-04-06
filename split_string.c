#include "holberton.h"

/**
 * isSpace - determines if char is a space
 * @c: input char
 * Return: true or false
 */
_Bool isSpace(char c)
{
	return (c == ' ');
}

/**
 * countWords - count number of words in a string
 * @str: input string
 * Return: number of words
 */
unsigned int countWords(char *str)
{
	register int words = 0;
	_Bool wordOn = false;

	while (*str)
	{
		if (isSpace(*str) && wordOn)
			wordOn = false;
		else if (!isSpace(*str) && !wordOn)
		{
			wordOn = true;
			words++;
		}
		str++;
	}
	return (words);
}

/**
 * splitString - splits string into an array of strings
 * separated by spaces
 * @str: input string
 * Return: array of strings
 */
char **splitString(char *str)
{
	register unsigned int i = 0;
	char *tok, *cpy = _strdup(str);
	char **res;

	res = malloc((countWords(str) + 1) * sizeof(char *));
	if (!res)
	{
		free(cpy);
		return (NULL);
	}
	tok = strtok(cpy, " ");
	while (tok != NULL)
	{
		res[i] = _strdup(tok);
		tok = strtok(NULL, " ");
		i++;
	}
	res[i] = NULL;
	free(cpy);
	return (res);
}
