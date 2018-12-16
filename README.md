# Terminal-Foo

## Members
Anand Idris and Meredith Hu

## Description
Creating a basic shell in C for our high school systems level programming class.

## Features
 - [x] print a command prompt
 - [x] prints the current working directory
 - [x] parse arguments from the command line and executes them
 - [x] have a nonvalid command error message
 - [x] implement cd with error messages
 - [x] implement exit
 - [x] read and parse multiple commands on one line with semicolon

## Attempted Features
 - [ ] simple redirection using > (Stdout) and < (stdin)
 - [ ] simple pipes using popen() or pipe()
 - [ ] stripping whitespace from semicolon-separated commands

## Wishes
 - [ ] catching CTRL+C
 - [ ] colors
 - [ ] tab completion
 - [ ] up key for previous commands
 - [ ] be able to take more than 5 arguments

## Bugs
 * don't enter a command wite whitespace before and after, like 'echo hello ; ls' just do echo hello;ls
 * don't put more than 5 commands in

## Function Headers and Descriptions
``` C
char ** parse_args(char * line, char * parse);
//parses line by whatever is specified in parse

int command_handle(char ** argument_list);
//handles an array of space-separated arguments with cd or execvp and waits for forked child process to finish before returning

void printdir();
//prints out the command prompt which is the current working directory and unique burgershop feature order up

//main handles semicolon parsing and exit
```

## Devlog

### 11-20-18 Meredith
 * Started basic readme
 * Started writing shell

### 11-21-18 Mostly Meredith
 * Did the parse_args.  Now you can enter arguments from the command line.

### 11-25-18 Anand 
 * Parse_args done through semi colons and it does each command per semi-colon.
 * Implements scanf to get command line input (source: https://www.programiz.com/c-programming/c-input-output)
 * Snazzy EarthBound name instead of humble burger restaurant.

### 11-26-18/Morning of 11-27-18 Meredith
 * fixed the issue of the shell "clearing" by fixing the infinite while loop to not call mystery function 'clear'
 * added exit, but it doesn't work
 * made a makefile
 * at least it compiles now instead of returning a bunch of warnings and not doing anything

### 11-27-18 Meredith
 * fixed exit
 * added scanf properly

### 11-29-18 Meredith w/ help from Anand (in class)
 * attempted to implement cd, and it seems to work, but runs into an error when given more than one argument
 * the infinite loop has returned :( something went wrong when we decided to put all the code into the main. modular design > what we have now.

### 11-30-18 Meredith
 * is the command supposed to be stored in a stack variable or a heap variable?

### 12-4-18 Meredith
 * sincerest apologies for neglecting this project. the weekend was a busy one full of college applications.
 * steve should be stored in a heap variable because it gets newly updated every time the loop is run and new stuff is read in from stdin with scanf.
 * why did we put the wait() in an else?? it is not supposed to be there
 * exit seems to be broken again?
 * cd works now
 * the command prompt prints and updates according to your current directory properly
 * the parent waits for the child to finish properly
 * no more infinite loop!
 * can read multiple arguments, great

### 12-6-18 Meredith
 * tried implementing fgets but didn't work
 
### 12-7-18 Meredith
 * implemented fgets correctly
 * made a new print command prompt function
 * cd does not print the error now
 * the command prompt prints if you just hit enter
 * put better cd error handling messages

### 12-12-18 Meredith and Anand
 * I promise I'm fixing this darn thing today, darn it
 * semicolon parsing works fo real now
 * put stuff in another function