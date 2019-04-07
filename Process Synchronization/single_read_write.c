#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t database;
pthread_t read, write;
int item = 0;
int dataWrite, dataRead;

void *writer(void * par)
{
    pthread_mutex_lock(&database);
    
    item = rand()%10;
	printf("Data %d is written\n",item);	
    dataWrite++;
	sleep(1);

    pthread_mutex_unlock(&database);
}

void *reader(void *par)
{
    pthread_mutex_lock(&database);

    printf("\tData %d is read\n",item);
    dataRead++;
    sleep(1);

    pthread_mutex_unlock(&database);
}

int main()
{
    int readCount, writeCount, temp;

    printf("Enter the number of elements to read and write : ");
    scanf("%d %d",&readCount, &writeCount);

    pthread_mutex_init(&database,NULL);
    dataRead = 0; 
    dataWrite = 0;
    
    while( dataRead < readCount || dataWrite < writeCount)
    {
        temp = rand() % 10;
        temp /= 5; 
        if(temp == 0 && dataRead < readCount)
        {
            pthread_create(&read, NULL, (void *)reader, NULL);
            pthread_join(read, NULL);
        }
        else if(dataWrite < writeCount)
        {
            pthread_create(&write, NULL, (void *)writer, NULL);
            pthread_join(write, NULL);
        }            
    }
}