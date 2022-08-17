#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *foo;
void cleanup (int s) { 
   /* free memory allocated by a malloc() */
  printf("cleaning up...%d (signal) \n", s);
  free(foo); 
}

int main() {
  int pid = getpid();
  printf("pid: %i\n", pid);
  /* copies a string using malloc */
  foo = strndup("foo", strlen("foo"));
  /* installs a signal handler for the process */
  signal (SIGUSR1, cleanup);
  signal (SIGUSR2, cleanup);
  pause();
  while(1) {
    sleep(2);
    printf("Doing something...\n");
  }
}
