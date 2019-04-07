#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty;
sem_t fill;
pthread_mutex_t mutex;

int buffer[20];
int counter = 0;

pthread_t produceThread[20], consumeThread[20];

void init()
{
	sem_init(&empty, 1, 20);
	sem_init(&fill, 1, 0);
	pthread_mutex_init(&mutex, NULL);
}

void *producer(int par)
{
   
	int item = rand() % 10;

	sem_wait(&empty);
	pthread_mutex_lock(&mutex);

	buffer[counter++] = item;
	printf("Producer %d produced item %d\n",par,item);

	pthread_mutex_unlock(&mutex);
	sem_post(&fill);

}

void *consumer(int par)
{
	int item = buffer[--counter];

	sem_wait(&fill);
	pthread_mutex_lock(&mutex);

	printf("Consumer %d consumed item %d\n", par, item);

	pthread_mutex_unlock(&mutex);
	sem_post(&empty);

}

int main()
{
	int i, pro, cons;

	printf("Enter number of producers : ");
	scanf("%d",&pro);

	printf("Enter the number of consumers : ");
	scanf("%d",&cons);

	init();

	for(i = 0; i < pro; i++)
	{
		pthread_create(&produceThread[i], NULL, (void *)producer,(int *)i);
	}
	for(i = 0; i < cons; i++)
        {
                pthread_create(&consumeThread[i], NULL, (void *)consumer, (int *)i);
        }

	for(i = 0; i < pro; i++)
        {
                pthread_join(produceThread[i], NULL);
        }
	for(i = 0; i < cons; i++)
        {
                pthread_join(consumeThread[i], NULL);
        }

	return 0;
}





