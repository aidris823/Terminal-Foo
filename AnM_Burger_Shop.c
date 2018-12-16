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

  if(strcmp(argument_list[0],"cd")== 0){
    printf("argument_list in cd case: %s\n", *argument_list);
    if(!argument_list[2]) chdir(argument_list[1]);
    else{printf("Condiments spilled: too many arguments given to cd\n");}
    if(!argument_list[1]) printf("Please give cd an argument, or your order will not arrive!\n");
  }else{
    if (!fork()){
      if (execvp(argument_list[0],argument_list)<0){
	printf("ERROR MESSAGE: Zoo Wee Mama!  Invalid command!\n");
      }
      exit(1);
    }
  } //if chdir, change directory. else, execute command
      
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
      //printf("block, parsed by semicolon: %s\n",block);

      /*
      //parse by pipe
      char ** unepipe = (char **)calloc(2,sizeof(char*));
      while((cur = strsep(&block, "|"))){
	strcpy(*unepipe, cur);
	printf("what's in two ends of pipe: %s\n",*unepipe);
	unepipe++;
	printf("cur, parsed by pipe: %s\n",cur);
	int stdout = dup(STDOUT_FILENO);
	int stdin = dup(STDIN_FILENO);
	int des[2];
	des[0] = stdout;
	des[1] = stdin;
      }
      */

      //printf("what's at steve rn %s\n",steve);
	//steve is null when the loop is in the cycle before finishes, therefore you get a segfault
	char ** argument_list = parse_args(cur, " ");
	if(strcmp(argument_list[0], "exit") == 0){return 0;} //if exit, exit main
	else{command_handle(argument_list);}
    }
  }
  
  return 0;
}

//


