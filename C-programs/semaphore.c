

#include<stdio.h>

#include<assert.h>

#include<stdlib.h>

#include<errno.h>

#include<pthread.h>

#include<unistd.h>

#include<semaphore.h>

sem_t sem;

pthread_t threads[5];

#define PERMIT_COUNT 2

void* thread_fn_call_back(void *arg)

{

	int i;

	char *threadName=(char*) arg;

	sem_wait(&sem);

	for(i=0;i<5;i++)

	{

		printf("%s executing in Critical Section\n",threadName);

		sleep(2);

	}

	sem_post(&sem);

}



void thread_create(pthread_t *thread_handle,void *arg)

{

	int rc=pthread_create(thread_handle,NULL,thread_fn_call_back,arg);	

	if(rc!=0)

	{

		printf("could not create thread ...Error occured Errno=%d\n",rc);

		exit(0);

	}

}

int main()

{

	sem_init(&sem,0,PERMIT_COUNT);

	thread_create(&threads[0],"thread1");

	thread_create(&threads[1],"thread2");

	thread_create(&threads[2],"thread3");

	thread_create(&threads[3],"thread4");

	thread_create(&threads[4],"thread5");

	

	int i;

	for(i=0;i<5;i++)

	{

	pthread_join(threads[i],NULL);

	}

	sem_destroy(&sem);

	return 0;



}