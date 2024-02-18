#include<stdio.h>

#include<assert.h>

#include<stdlib.h>

#include<errno.h>

#include<pthread.h>

#include<unistd.h>



pthread_mutex_t arr_mutex;



int arr[]={1,2,3,4,5,6};



static void* thread_fn_callback_sum()

{

	int i;

	int sum;

	int arraySize = sizeof(arr)/sizeof(arr[0]);

	do{

		sum=0;

		i=0;

		pthread_mutex_lock(&arr_mutex);

		while(i<arraySize){

			sum+=arr[i];

			i++;

		}

		printf("sum = %d\n",sum);

		pthread_mutex_unlock(&arr_mutex);

	}while(1);



}

static void* thread_fn_callback_swap()

{

	int temp;

	int arraySize = sizeof(arr)/sizeof(arr[0]);

	do{

		pthread_mutex_lock(&arr_mutex);

		temp=arr[0];

		arr[0]=arr[arraySize-1];

		arr[arraySize-1]=temp;

		pthread_mutex_unlock(&arr_mutex);

	}while(1);

	





}



void sum_create_thread()

{

	pthread_t pthread1;

	int rc=pthread_create(&pthread1,NULL,thread_fn_callback_sum,NULL);

	

	if(rc!=0)

	{

		printf("could not create thread ...Error occured Errno=%d\n",rc);

		exit(0);

	}



}

void swap_create_thread()

{

	pthread_t pthread2;

	int rc=pthread_create(&pthread2,NULL,thread_fn_callback_swap,NULL);

	

	if(rc!=0)

	{

		printf("could not create thread ...Error occured Errno=%d\n",rc);

		exit(0);

	}



}



void display()

{

	int i=0;

	int arraySize = sizeof(arr)/sizeof(arr[0]);

	for(;i<arraySize-1;i++)

	{

	printf("%d",arr[i]);

	}

	printf("\n");



}









int main(int argc,char **argv)

{

	pthread_mutex_init(&arr_mutex,0);

	sum_create_thread();

	swap_create_thread();

	pthread_exit(0);

return 0;





}