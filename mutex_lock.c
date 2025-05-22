#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *fun1();
void *fun2();

int shared=1;
pthread_mutex_t l;

int main()
{
    pthread_mutex_init(&l,NULL);
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,fun1,NULL);
    pthread_create(&thread2,NULL,fun2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Final value of shared is %d\n",shared);


}

 void *fun1()
{
   int x;
   printf("Thread1 trying to acquire lock\n");
   pthread_mutex_lock(&l);
   printf("Thread1  acquired lock\n");
   x=shared;
   printf("Thread1 reads the value of shared is %d\n",x);
   x++;
   printf("Local updation  by thread1 is %d\n",x);
   sleep(1);
   shared=x;
   printf("Value of shared varaible updated by thread1 is %d\n",shared);
   pthread_mutex_unlock(&l);
   printf("Thread1 release the lock\n"); }    void *fun2()
{
   int y;
   printf("Thread2 trying to acquire lock\n");
   pthread_mutex_lock(&l);
   printf("Thread2  acquired lock\n");
   y=shared;
   printf("Thread2 reads the value of shared is %d\n",y);
   y--;
   printf("Local updation  by thread2 is %d\n",y);
   sleep(1);
   shared=y;
   printf("Value of shared varaible updated by thread2 is %d\n",shared);
   pthread_mutex_unlock(&l);
   printf("Thread2 release the lock\n");

}
