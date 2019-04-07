#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

pthread_t readerThread, writerThread;

pthread_mutex_t mutex;
sem_t database;

int buffer[20];
int readerCount, count;
int dataWrite, dataRead;

void init()
{
	pthread_mutex_init(&mutex,NULL);
	sem_init(&database,1,1);
	readerCount = 0;
	count = 0;
	dataWrite = 0;
	dataRead = 0;
}

void *writer(int i)
{
	while(dataWrite < i)
	{
		sem_wait(&database);

		int item = rand()%10;
		buffer[count++] = item;
		printf("Data %d is written\n",item);
		dataWrite++;
//		sleep(1);

		sem_post(&database);
	}
}

void *reader(int i)
{
	while(dataRead < i)
	{
		pthread_mutex_lock(&mutex);
		readerCount++;

		if(readerCount == 1)
			sem_wait(&database);

		pthread_mutex_unlock(&mutex);

		int item = buffer[--count];
		printf("Data %d is read\n",item);
		dataRead++;
//		sleep(1);

		pthread_mutex_lock(&mutex);
		readerCount--;

		if(readerCount == 0)
			sem_post(&database);

		pthread_mutex_unlock(&mutex);
	}
}


int main()
{
	int i, read, write;

	printf("Enter the number of data items to write : ");
	scanf("%d",&write);

	printf("Enter the number of data items to read : ");
	scanf("%d",&read);

	init();


//	for(i = 0; i < write; i++)
		pthread_create(&writerThread, NULL, (void *)writer, write);

//	for(i = 0; i < read; i++)
		pthread_create(&readerThread, NULL, (void *)reader, read);

//	for(i = 0; i < write; i++)
		pthread_join(writerThread,NULL);

//	for(i = 0; i < read; i++)
		pthread_join(readerThread,NULL);

	return 0;
}

