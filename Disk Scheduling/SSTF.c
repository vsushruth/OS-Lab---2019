#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct request
{
    int request_track_number;
    bool assigned;
};

int main()
{
    int i, no_of_requests, seek_time, initial_head, temp_track, id, min;

    printf("Enter the number of requests : ");
    scanf("%d",&no_of_requests);
    
    struct request req[no_of_requests];
    printf("Enter the requested track for %d processess : \n", no_of_requests);
    for(i = 0;i < no_of_requests; i++)
    {
        printf("Request %d : ",i);
        scanf("%d",&req[i].request_track_number);
        req[i].assigned = false;
    }

    printf("Enter the initial position of the disk head : ");
    scanf("%d", &initial_head);

    int n = no_of_requests;
    seek_time = 0;
    printf("%d - ",initial_head);

    while(n)
    {
        min = 999;
        id = 999; 
        for(i = 0; i < no_of_requests; i++)
        {
            if(min > abs(initial_head - req[i].request_track_number) && req[i].assigned == false)
            {
                min = abs(initial_head - req[i].request_track_number);
                temp_track = req[i].request_track_number;
                id = i;
            } 
        }
        if(min != 999)
        {
            initial_head = req[id].request_track_number;
            req[id].assigned = true;
            seek_time += min;
            if(n != 1)
            {
                printf("%d - ",initial_head);
            }
            else
            {
                printf("%d ",initial_head);
            }
            
            n--;
        }
    }

    printf("\nDistance travelled : %d\n\n", seek_time);

    return 0;
}