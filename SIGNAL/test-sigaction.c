#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

char *foo;

void cleanup(int s) {
  printf("sighandler called signal(%d)\n", s);
  free(foo);
}

struct sigaction sa; // special struct!!

void install_signal_handler() {
  sa.sa_handler = cleanup;// handler addr
  sigemptyset(&sa.sa_mask); // reset
  sigaddset(&sa.sa_mask, SIGUSR1); //mask itself
  sa.sa_flags = 0; 
  sigaction(SIGUSR1, &sa, NULL);
  
}
int main() {
  printf("PID %i\n", getpid());
  foo = strndup("foo", strlen("foo"));
  install_signal_handler();
  pause();
}
