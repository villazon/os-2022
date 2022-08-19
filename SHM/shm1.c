#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

// based on :
// http://rahulraina09.blogspot.com/2015/06/shared-memory-linux-c-program.html

int main(int argc, char **argv)
{
  int shmid; 
  char *shm, *s;
  key_t key = 2022;
  if((shmid = shmget(key, 2048, 0666 | IPC_CREAT)) == -1)
    {
      fprintf(stderr, "shmget() error... cannot get shared memory...");
      exit(-1);
    }
  printf("SHMID: %d\n", shmid);
  shm = shmat(shmid, NULL, 0);
  if(shm == (char*)-1)
    {
      fprintf(stderr, "shmat() error...");
      exit(-1);
    }
  printf("Writting message on SHM\n");
  memcpy(shm, "Hello World", 11);
  s = shm;
  s += 11;
  *s = 0; // add \0 at the end of the string...
  while(*shm != '*'){
    printf("Waiting for '*' to be written in SHM\n");
    sleep(2);
  }
  return 0;
}
