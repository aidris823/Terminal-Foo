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

  //wait for child to terminate
  int status;
  wait(&status);
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

    char * cur;
    //parse by semicolon (with while loop you don't have to allocate a specific amount of memory)
    while((cur = strsep(&steve, ";"))){
      char * block = cur;
      printf("block, parsed by semicolon: %s\n",block);

      /*
      //parse by pipe
      while((cur = strsep(&block, "|"))){
	printf("cur, parsed by pipe: %s\n",cur);
	//int stdout = dup(STDOUT_FILENO);
	//int stdin = dup(STDIN_FILENO);
	*/

	printf("what's at steve rn %s\n",steve);
	//steve is null when the loop is in the cycle before finishes, therefore you get a segfault
	if(strcmp(cur, "exit") == 0){return 0;} //if exit, exit main
	else{
	  //else if(strcmp(cur,"cd") == 0){
	  char ** argument_list = parse_args(cur, " "); //parses arguments
	  if(strcmp(argument_list[0],"cd")== 0){
	      printf("argument_list in cd case: %s\n", *argument_list);
	      if(!argument_list[2]) chdir(argument_list[1]);
	      else{printf("Condiments spilled: too many arguments given to cd\n");}
	      if(!argument_list[1]) printf("Please give cd an argument, or your order will not arrive!\n");
	  }else{command_handle(argument_list);}
	} //if chdir, change directory

      
    }

    /*
    char ** argument_list = parse_args(steve," "); // parses arguments
    if(strcmp(steve, "exit") == 0){return 0;} //if exit, exit main 
    else if(strcmp(argument_list[0],"cd") == 0){
      if(!argument_list[2]) chdir(argument_list[1]);
      else{printf("Condiments spilled: too many arguments given to cd\n");}
      if(!argument_list[1]) printf("Please give cd an argument, or your order will not arrive!\n");
    } //if chdir, change directory
   
    
    //child process spawning
    else if(len > 1){
      command_handle(argument_list);
    }
    */

  }
  
  return 0;
}

//


