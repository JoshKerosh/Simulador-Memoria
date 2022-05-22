#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *newtask(void *null)
{
   printf("Hello world! I'm a new thread\n");
   int i;

   for (i=0; i<10;++i)
     {
       printf (" THREAD: %d\n", i);
       usleep(60);
     }
   printf("Goodbye world! I'm a thread about to die\n");
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t thread;
   int rc;
   int i;

   printf ("Main process just started.\n");
   rc = pthread_create(&thread, NULL, newtask, NULL);
   if (rc)
     {
       printf("ERROR in pthread_create(): %d\n", rc);
       exit(-1);
     }

   for (i=0; i<10;++i)
     {
       usleep(100);
       printf (" MAIN: %d\n", i);
     }
   printf ("Main process about to finish.\n");
   /* Last thing that main() should do */
   pthread_exit(NULL);
}