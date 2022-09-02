#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define NB_PROC 1000
int main(){

  int pid;
  for(int i=0; i<NB_PROC; i++) {
    pid = fork();
    if(pid == 0) {
      printf("proc %d\n", i);
      exit(0);
    }
  }

  for(int i=0; i<NB_PROC; i++) {
    wait(NULL); // wait all
  }

  printf("ALL PROCESSES ENDED..\n");
  
}
