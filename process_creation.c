#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t q;
    q=fork();
    if(q<0)
    printf("ERROR");

    else if(q==0)
    {
      printf("Child having pid is %d\n",getpid());
      printf("My parent id is %d\n",getppid());
    }

      else
      {
          wait(NULL);
         printf("My child pid is %d\n",q);
        printf("Parent having pid is %d\n",getpid());

         }
}
