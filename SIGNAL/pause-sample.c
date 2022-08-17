#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
  int pid = getpid();
  printf("Will wait a signal (process %d)\n", pid);
  //  pause();
  //printf("Signal received\n");
  alarm(10);
  // pause();
  printf("will work \n");
  while(1) {} // run forever... 
}
