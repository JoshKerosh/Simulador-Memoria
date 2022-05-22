#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

struct thread_vars_t
{
  int ready;
  int number;
  char string[50];
};

void *newtask(void *_number)
{
  struct thread_vars_t *vars = _number;

  printf("The number I was asked for: %d\n", vars->number);
  vars->number = 10;
  strcpy(vars->string, "Hello world from thread");
  vars->ready = 1;
  pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t thread;
   int rc;
   int i;
   struct thread_vars_t *vars = malloc (sizeof(struct thread_vars_t));

   vars->ready = 0;
   vars->number = 99;

   printf ("Main process just started.\n");
   rc = pthread_create(&thread, NULL, newtask, vars);
   if (rc)
     {
       printf("ERROR in pthread_create(): %d\n", rc);
       exit(-1);
     }

   //   usleep(100000);
   while (!vars->ready);
   printf (" Before exiting. Number = %d\n", vars->number);
   printf (" Before exiting. String = %s\n", vars->string);

   printf ("Main process about to finish.\n");
   /* Last thing that main() should do */
   pthread_exit(NULL);
}