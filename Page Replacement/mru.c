#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct frames
{
    int page_id;
    int frame_uses;
    int age;
    bool allotted;
};

int main()
{
    int frame_number, no_page_refs, inp_page;
    int i, j, temp, temp_age, id, point;
    int hit = 0, fault = 0;
    bool flag = false;

    printf("Enter the number of frames : ");
    scanf("%d",&frame_number);
    
    struct frames frame[frame_number];
    for(i = 0; i < frame_number; i++)
    {
        frame[i].page_id = -1;
        frame[i].frame_uses = 0;
        frame[i].age = 0;
        frame[i].allotted = false;
    }
    for(j = 0;j < frame_number; j++)
    {
        printf("%d\t",frame[j].page_id);
    }
    printf("\n\n");

    printf("Enter the number of page references : ");
    scanf("%d",&no_page_refs);
    int pages[no_page_refs];

    for(i = 0; i < no_page_refs; i++)
    {
        flag = false;
        point = 0;
        temp_age = 999;
        id = 0;

        printf("\n\n%d page reference :",i);
        scanf("%d",&inp_page);
        pages[i] = inp_page;

        for(j = 0; j < frame_number; j++)
        {
            if(frame[j].allotted == false)
            {
                printf("Fault for %d \n", inp_page);
                fault++;
                flag = true;
                frame[j].page_id = inp_page;
                frame[j].frame_uses++;
                point = 999;
                frame[j].allotted = true;
                break;
            }
            else if(frame[j].page_id == inp_page)
            {
                printf("Hit for %d \n",inp_page);
                hit++;
                flag = true;
                frame[j].frame_uses++;
                frame[j].age = 0;
                break;
            }
        }

        if(flag == false)
        {
            for(j = 0; j < frame_number; j++)
            {
                if(frame[j].age <= temp_age)
                {
                    temp = frame[j].frame_uses;
                    temp_age = frame[j].age;
                    id = j;
                }
            }
            
            printf("Fault for %d \n", inp_page);
            fault++;
            frame[id].page_id = inp_page;
            frame[id].frame_uses = 1;
            frame[id].age = 0;
            frame[id].allotted = true;
        }
        
        for(j = 0;j < frame_number; j++)
        {
            if(frame[j].allotted == true)
            {
                frame[j].age++;
            }
        }
            

        for(j = 0;j < frame_number; j++)
        {
            printf("%d\t",frame[j].page_id);
        }

       
    }

    printf("\nNumber of hits : %d\nNumber of faults : %d\n\n",hit,fault);
    return 0;
}