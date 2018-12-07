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

//...Handles the command.  Personal preference that this be done here instead of in the main.

int command_handle(char ** argument_list){
  int child1 = fork();
  if (! child1){

    execvp(argument_list[0],argument_list);
    if (execvp(*argument_list,argument_list) < 0){
      printf("ERROR MESSAGE: Zoo Wee Mama!  Invalid command!\n");
      exit(1);
    }
  }
  else{
    int status = 0;
    wait(&status);
    return (WEXITSTATUS(status));
  }
}

void printdir(){
  char dir[500];
  getcwd(dir, sizeof(dir));
  printf("[ORDER UP]:%s$",dir);
}
  
int main(){
  
  while(1){
    printdir();
    char * steve = calloc(100,sizeof(char));
    fgets(steve, 100, stdin);
    size_t len = strlen(steve);
    if (len <= 1) printdir();
    if(steve[len-1] == '\n') steve[len-1]= '\0';

    char ** argument_list = parse_args(steve," ");

    if(strcmp(steve, "exit") == 0){return 0;}
    
    if(strcmp(argument_list[0],"cd") == 0){chdir(argument_list[1]);}
    
    if (!fork()){
      if (execvp(argument_list[0],argument_list)<0){
	printf("ERROR MESSAGE: Zoo Wee Mama!  Invalid command!\n");
      }
      exit(1);
    }
    
    int status;
    wait(&status);
    //return (WEXITSTATUS(status));

  }
}

//


