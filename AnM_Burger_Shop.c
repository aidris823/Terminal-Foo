#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "burgers.h"

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

int main(int argc, char** argv){
  /*
  //char line[100] = arguments;
  //char ** args = parse_args(arguments);
  int counter = 0;
  while (args != NULL){
    printf("%s\n",*args);
    //counter++;
    args++;
  }
  */
  //char* program = argv[0];
  execvp(argv[0],argv);
  return 0;
}


