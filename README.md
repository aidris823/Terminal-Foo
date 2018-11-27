# Terminal-Foo

## Members
Anand Idris and Meredith Hu

## Description
Creating a basic shell in C for our high school systems level programming class.

## Features
 - [x] print a command prompt
 - [ ] parse arguments from the command line
 - [x] have a nonvalid command error message
 - [ ] implement cd
 - [ ] implement exit
 - [ ] be able to take more than five arguments
 - [ ] read and parse multiple commands on one line with semicolon
 - [ ] simple redirection using > (stdout) and < (stdin)
 - [ ] simple pipes using popen()

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