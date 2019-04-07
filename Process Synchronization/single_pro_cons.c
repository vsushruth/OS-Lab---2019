#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_t produce, consume;
int buffer[30];
int count = 0;
int dataPro, dataCons;

void *producer(void *par)
{
    pthread_mutex_lock(&mutex);

    int item = rand() % 10;
    buffer[count++] = item;
    printf("Producer is producing %d\n", item);
    dataPro++;
    sleep(1);

    pthread_mutex_unlock(&mutex);
}

void *consumer(void *par)
{
    pthread_mutex_lock(&mutex);
    int item = 0;
    if(count > 0)
    {
        item = buffer[--count];
    }

    printf("Consumer is consuming %d\n", item);
    dataCons++;
    sleep(1);

    pthread_mutex_unlock(&mutex);
}

int main()
{
    int proCount, consCount, temp;

    printf("Enter the number of elements to produce and conusme : ");
    scanf("%d %d",&proCount, &consCount);

    pthread_mutex_init(&mutex,NULL);
    dataPro = 0; dataCons = 0;
    //printf("%d %d\n",readCount, writeCount);

    while(dataPro < proCount || dataCons < consCount)
    {
        temp = rand() % 10;
        if(temp / 5 == 0 && dataCons < consCount)
        {
            pthread_create(&consume, NULL, (void *)consumer, NULL);
            pthread_join(consume, NULL);
        }
        else if(dataPro < proCount)
        {
            pthread_create(&produce, NULL, (void *)producer, NULL);
            pthread_join(produce, NULL);
        }        
    }
}