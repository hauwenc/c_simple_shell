#include "holberton.h"
/**
* builtIns - find the right built in to use
* @args: parsed strings
*
* Return: 1 if found, 0 if not found
*/
int builtIns(config *build)
{
	type_b getBuiltIns[] = {
	{"exit", exitFunc},
	{"env", envFunc},
	{"history", historyFunc},
	{"alias", aliasFunc},
	{"cd", cdFunc},
	{"setenv", setenvFunc},
	{"unsetenv", unsetenvFunc},
	{NULL, NULL}
	};

	register int index = 0;

	while (getBuiltIns[index].command)
	{
		if (_strcmp(build->args[0], getBuiltIns[index].command) == 0)
		{
			getBuiltIns[index].func(build);
			return (1);
		}
		index++;
	}
	return (0);
}

/**
* exitFunc - exit.
* @args: the parsed exit string
*
* Return: 1
*/
int exitFunc(config *build)
{
	int argCount, exitStatus;

	argCount = countArgs(build->args);
	freeAlltheThings(build);
	free(build);
	if (argCount == 1)
		exit(0);
	else if (argCount > 1)
	{
		/* check for valid string */
		exitStatus = _atoi(build->args[1]);
		exit(exitStatus);
	}
	return (0);
}
int historyFunc(config *build)
{
	(void)build;
	printf("history placeholder\n");
	return (1);
}

int aliasFunc(config *build)
{
	(void)build;
	printf("alias placeholder\n");
	return (1);
}

