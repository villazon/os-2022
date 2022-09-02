#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_THREADS 2

int a=0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void *
funcion_th (void *i)
{
  int *j = (int *)i;

  for (;;)
    {
      pthread_mutex_lock(&mtx);
      if (a == 0)
	       a++;
      else
	       a--;
      fprintf (stderr, "Soy el hilo %d y a=%d\n", *j,  a);
      pthread_mutex_unlock(&mtx);
    }

  return (NULL);
}

int
main()
{
    
    
  pthread_t id[NB_THREADS];
  int i[NB_THREADS];

  for (int j=0; j<NB_THREADS; j++)
    {
      i[j]=j;
      pthread_create (&(id[j]), NULL, funcion_th, (void *)&i[j]);
    }

  for (int j=0; j<NB_THREADS; j++)
    {
      pthread_join (id[j], NULL);
    }

  exit (EXIT_SUCCESS);
}
