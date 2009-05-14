#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

  char *temp = malloc(sizeof(char*));

  char *test = "less ";

  char *s = "insmod.c";

  int len = strlen(test)+strlen(s);

  snprintf(temp,len+1,"%s%s",test,s);

  system(temp);
  return 0;
}

