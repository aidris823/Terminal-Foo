#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "burgers.h"
#include <errno.h>
#include <sys/wait.h>
//Things to do:

/* 
1. - Read line at a time.
- Parse line to separate command from arguments.
- Fork and exec a command.
- (Parent process waits until the executed program exits, and then reads next command.
- (Implements exit & cd through chdir() )

2. - Read and separate many commands on one line with ; 
- (Ex: "ls -l; echo hello")

*/

//Semi-coloned parse_args
void s_parse_arg(char * line){
  int counter = 0;
  for (int i = 0; i < strlen(line); i++){
    if (line[i] == ';'){
      counter++;
    }
  }
  char * arguments[counter];
  
}
  
	
	
//Parses arguments.
char ** parse_args(char * line){
  char ** steve = (char **)malloc(5*sizeof(char*));
  int counter = 0;
  char *s;
  while(line){
    s = strsep(&line," ");
    steve[counter] = s;
    counter++;
  }
  return steve;
}

//...Handles the command.  Personal preference that this be done here instead of in the main.
int command_handle(char * command){
  int child1 = fork();
  if (! child1){
    char ** argument_list = parse_args(command);
    if(strcmp(argument_list[0],"cd") == 0){
      if(argument_list[2]){
	printf("Error: cd too many arguments\n");
	exit(1);
      }
      chdir(argument_list[1]);
    }
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
  
int main(){
  int status = 1;
  while(status){
    printf("$PSI Rockin Ω$:");
    char * steve = malloc(5*sizeof(char*));
    scanf("%[^\n]s",steve);
    if(strcmp(steve, "exit") == 0){
      return 0;
    }else{
      status = command_handle(steve);
    }
  }
}

//


