#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t philosopher[50];
pthread_mutex_t chopsticks[50];

int n;

void *pholosiphise(int i)
{
    printf("%d is thinking\n", i+1);
    
    pthread_mutex_lock(&chopsticks[i]);
    pthread_mutex_lock(&chopsticks[(i+1)%n]);

    printf("  %d is eating\n", i+1);
    
    sleep(1);

    printf("    %d finished eating\n", i+1);
    
    pthread_mutex_unlock(&chopsticks[i]);
    pthread_mutex_unlock(&chopsticks[(i+1)%n]);

    return NULL;
}

int main()
{
    int i;

    printf("Enter the number of philosophers : ");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        pthread_mutex_init(&chopsticks[i],NULL);
    }

    for(i = 0; i < n; i++)
    {
        pthread_create(&philosopher[i], NULL, (void *)pholosiphise, (int *)i);
    }

    for(i = 0; i < n; i++)
    {
        pthread_join(philosopher[i],NULL);
    }

    return 0;
}