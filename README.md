# Josef and Tu's Shell
***
### Description
Josef and Tu's Shell is a shell that replicates functionalities of the simple shell. Additional functions are also included.

### Installation
Clone this repository into your working directory. For best results, files should be compiled with GCC and the following flags: -Wall -Wextra -Werror -pedantic -Wno-format.

### Usage
After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode. 

#### Interactive Mode
In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.

#### Non-Interactive Mode
In non-interactive mode, echo your desired command and pipe it into the program like this:
```sh
echo "ls" | ./shell
```
In non-interactive mode, the program will exit after finishing your desired command(s).

#### Included Built-Ins
Our shell has support for the following built-in commands:

Command | Definition
--------|---------------
exit [n] | Exit the shell, with an optional exit status, n.
env      | Print the environment.
setenv [var] [value] | Set an environment variable and value. If the variable exists, the value will be updated.
unsetenv [var] | Remove an environment variable.
cd [dir] | Change the directory.
help [built-in] | Read documentation for a built-in.

The following built-in commands may be supported in future versions:

Command | Definition
--------|---------------
Alias   | Set an Alias.
history | View the history of the shell.


#### Outside Programs
Our shell can run outside programs by typing their absolute paths (/bin/ls) or the executable name (ls), IF their directory is included in the PATH. 

### Included Files and Functions
*main.c - functions for calling the shell and initializing the shell struct
  *main
  *configInit
*shell.c - functions for running the basic shell logic
  *shell
  *checkAndGetLine
  *stripComments
  *forkAndExecute
*shell_helpers.c - functions for helping the shell run
  *insertNullByte
  *displayPrompt
  *displayNewLine
  *sigintHandler
*split_string.c - functions for splitting string from the user
  *splitString
  *countWords
  *isSpace
*string_helpers1.c - functions for manipulating strings
  *_strlen
  *_strcat
  *_strcmp
  *_strdup
  *_strcpy
*string_helpers2.c - functions for manipulating strings
  *_strtok
  *_strcspn
  *_strchr
*built_ins.c - functions for built-ins
  *findBuiltIns
  *exitFunc
  *historyFunc
  *aliasFunc
*built_in_helpers.c - functions for helping the built-in functions
  *countArgs
  *_atoi
*help.c - functions for the help built-in
  *helpFunc
  *displayHelpMenu
  *helpExit
  *helpEnv
  helpHistory
*help2.c - functions for the help built-in

*cd.c - functions for the cd built-in

*cd2.c - functions for the cd built-in

*_getenv.c - functions for getting elements from the environment

*env.c - functions for the env, setenv, and unsetenv built-ins

*llfuncs1.c - linked list functions

*llfuncs2.c - linked list functions

*expansions.c - functions for dealing with the $? and $$ expansions

*check_path.c - functions for checking the path of an executable

*error_handler.c - functions for dealing with errors

*free.c - functions for freeing allocated memory

*holberton.h - header file


### Credits
All code written by [Tu Vo](https://github.com/tuvo1106) and [Josef Goodyear](https://github.com/JosefGoodyear).

