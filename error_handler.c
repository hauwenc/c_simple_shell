#include "holberton.h"

/**
 * errorHandler - prints error message for shell()
 * @num: nth command entered into shell
 * @cmd: command that could not be executed
 * @arg: arguments
 */
void errorHandler(int num, char *cmd, char *arg)
{
	register int len;
	static char error[BUFSIZE];
	char *alpha;
	char *ptr;

	alpha = itoa(num);
	_strcat(error, SHELLNAME);
	_strcat(error, ": ");
	_strcat(error, alpha);
	_strcat(error, ": ");
	_strcat(error, cmd);
	_strcat(error, getErrorMessage());
	if (arg)
		_strcat(error, arg);
	_strcat(error, "\n");
	ptr = _strchr(error, '\n');
	len = ptr - error;
	insertNullByte(error, len + 1);
	write(STDOUT_FILENO, error, len + 1);
	free(alpha);
	insertNullByte(error, 0);
}

/**
 * getErrorMessage - print correct error message
 * Return: string
 */
char *getErrorMessage()
{
	char *str;

	switch (errno)
	{
		case ENOENT:
			str = ": not found";
			break;
		case ENOSTRING:
			str = ": bad variable name";
			break;
		default:
			str = "no error number assigned";
	}
	return (str);
}

/**
 * countDigits - count number of digits in a number
 * @num: input number
 * Return: number of digits
 */
unsigned int countDigits(int num)
{
	register int digits = 0;

	while (num > 0)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

/**
 * itoa - converts integer to string
 * @num: input integer
 * Return: string type of number
 */
char *itoa(unsigned int num)
{
	register int digits = 0;
	char *str;

	digits += countDigits(num);
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		exit(errno);
	insertNullByte(str, digits);
	while (num > 0)
	{
		str[digits - 1] = num % 10 + '0';
		num = num / 10;
		digits--;
	}
	return (str);
}
