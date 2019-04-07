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
    int i, j ,no_of_requests, seek_time, initial_head, previous_head, max_disk; 
    int temp_track, id, min;

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

    printf("Enter the previous position of disk head : ");
    scanf("%d",&previous_head);

    printf("Enter the maximum number of tracks on the disk : ");
    scanf("%d", &max_disk);

    seek_time = 0;
    printf("%d - ", initial_head);
    
    int n = 0;
    if((initial_head - previous_head) > 0)
    {
        for(j = initial_head; j < max_disk; j++)
        {
            for(i = 0; i < no_of_requests; i++)
            {
                if(j == req[i].request_track_number && req[i].assigned == false)
                {
                    n++;                    
                    seek_time += abs(initial_head - req[i].request_track_number);
                    initial_head = req[i].request_track_number;
                    req[i].assigned = true;
                    printf("%d - ",initial_head);
                }
            }
        }
        
        printf("%d - ",max_disk-1);
        seek_time += abs(max_disk - 1 - initial_head);
        initial_head = max_disk -1;
        
        for(j = initial_head; j >= 0; j--)
        {
            for(i = 0; i < no_of_requests; i++)
            {
                if(j == req[i].request_track_number && req[i].assigned == false)
                {
                    n++;
                    seek_time += abs(initial_head - req[i].request_track_number);
                    initial_head = req[i].request_track_number;
                    req[i].assigned = true;
                    printf("%d - ",initial_head);
                }
            }
        }
            
    }
    else
    {
        for(j = initial_head; j >=0; j--)
        {
            for(i = 0; i < no_of_requests; i++)
            {
                if(j == req[i].request_track_number && req[i].assigned == false)
                {
                    n++;
                    seek_time += abs(initial_head - req[i].request_track_number);
                    initial_head = req[i].request_track_number;
                    req[i].assigned = true;
                    printf("%d - ",initial_head);
                }
            }
        }
        
        printf("%d - ",0);
        seek_time += abs(initial_head);
        initial_head = 0;
        
        for(j = initial_head; j < max_disk; j++)
        {
            for(i = 0; i < no_of_requests; i++)
            {
                if(j == req[i].request_track_number && req[i].assigned == false)
                {
                    n++;
                    seek_time += abs(initial_head - req[i].request_track_number);
                    initial_head = req[i].request_track_number;
                    req[i].assigned = true;
                    printf("%d - ",initial_head);
                }
            }
        }
    }
        
    printf("\nDistance travelled : %d\n\n", seek_time);

    return 0;
}