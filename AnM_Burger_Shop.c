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
  argv++;
  if(execvp(*argv,argv) < 0){
    printf("ERROR MESSAGE: You fool who gets their burgers Well Done?\n");
    exit(1);
  }
  return 0;
}


