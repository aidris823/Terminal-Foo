#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "burgers.h"
#include <errno.h>
#include <sys/wait.h>

/* 

//Simple redirection
void redirect(){
  return;
}
//...CLASS NOTES DONT MENTION HOW TO REDIRECT STDOUT AND STDIN!?  (I think?)
//Keep calm and carry on.
/*
void pipe_redirect(){
  int c = fork();
  int fd[2];
  if (c == 0){
    dup2(fd[1],1);
  }
  dup2(fd[0],0);
  execvp(parsed[2],2);
}
*/
/*
//Semi-coloned parse_args
char ** s_parse_arg(char * line){
  char ** steve = (char**)malloc(5*sizeof(char*));
  
  int counter = 0;
  for (int i = 0; i < strlen(line); i++){
    if (!strcmp(line[i],';')){
      counter++;
    }
  }
  for (int i = 0; i < counter; i++){
    steve[i] = strsep(&line,';');
  }
  return steve;
}
*/
	
	
//Parses arguments.
char ** parse_args(char * line, char * parse){
  char ** steve = (char **)malloc(5*sizeof(char*));
  int counter = 0;
  char *s;
  while(line){
    s = strsep(&line,parse);
    steve[counter] = s;
    counter++;
  }
  return steve;
}

//Handles the command.
int command_handle(char ** argument_list){
  if (!fork()){
    if (execvp(argument_list[0],argument_list)<0){
      printf("ERROR MESSAGE: Zoo Wee Mama!  Invalid command!\n");
    }
    exit(1);
  }
}

void printdir(){
  char dir[500];
  getcwd(dir, sizeof(dir));
  printf("[ORDER UP]:%s$",dir);
}
  
int main(){
  
  while(1){
    printdir(); //prints out the command prompt

    //gets input, allocates memory
    char * steve = calloc(100,sizeof(char));
    fgets(steve, 100, stdin);

    //gets rid of newline at end for command handling later on
    size_t len = strlen(steve);
    if(steve[len-1] == '\n') steve[len-1]= '\0';

    if(strcmp(steve, "exit") == 0){return 0;} //if exit, exit main

    char ** argument_list = parse_args(steve," "); // parses arguments 
    else if(strcmp(argument_list[0],"cd") == 0){
      if(!argument_list[2]) chdir(argument_list[1]);
      else{printf("Condiments spilled: too many arguments given to cd\n");}
      if(!argument_list[1]) printf("Please give cd an argument, or your order will not arrive!\n");
    } //if chdir, change directory

    //child process spawning
    else if(len > 1){
      command_handle(argument_list);
    }

    //waits for child to terminate
    int status;
    wait(&status);
  }
  
  return 0;
}

//


