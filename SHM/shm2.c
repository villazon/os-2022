#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

// based on:
// http://rahulraina09.blogspot.com/2015/06/shared-memory-linux-c-program.html

int main(int argc, char **argv)
{
  int shmid; //to be passed to shmget()
  char *shm, *s;
  key_t key = 2022;
  if((shmid = shmget(key, 2048, 0666 | IPC_CREAT)) == -1)
    {
      fprintf(stderr, "shmget() error.. cannot get shared memory...");
      exit(1);
    }
  printf("SHMID: %d\n", shmid);
  shm = shmat(shmid, NULL, 0);
  if(shm == (char*)-1)
    {
      fprintf(stderr, "shmat() error...");
      exit(1);
    }
  for(s = shm; *s != 0; s++) 
    printf("%c",*s); 
  printf("\n");
  *shm = '*';
  printf("Dettaching SHM\n"); 
  shmdt(shm);
  return 0;
}
