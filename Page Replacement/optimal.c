#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct frames
{
    int page_id;
    int frame_uses;
    int age;
    int freq;
    bool allotted;
};

struct pages
{
    int page_ref;
    int page_uses;
    bool page_flag;
};


int main()
{
    int frame_number, no_page_refs, inp_page;
    int i, j, temp, temp_age, id;
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
        frame[i].freq = 0;
        frame[i].allotted = false;
    }
    for(j = 0;j < frame_number; j++)
    {
        printf("%d\t",frame[j].page_id);
    }
    printf("\n\n");

    printf("Enter the number of page references : ");
    scanf("%d",&no_page_refs);
    
    struct pages page[no_page_refs];
    for(i = 0; i < no_page_refs; i++)
    {
        printf("%d page reference :",i);
        scanf("%d",&page[i].page_ref);
        page[i].page_uses = 0;
        page[i].page_flag = false;
    }
    
    for( i = 0; i < no_page_refs; i++)
    {
        if(page[i].page_flag == false)
        {   
            for(j = i+1;j < no_page_refs; j++)
            {
                if(page[i].page_ref == page[j].page_ref)
                {
                        page[i].page_uses++;
                }

            }
            page[i].page_flag = true;
        }
    }
    
    for(i = 0;i < no_page_refs; i++)
    {
        printf("%d ",page[i].page_uses);
    }
    
    for(i = 0; i < no_page_refs; i++)
    {
        flag = false;
        temp_age = 999;
        temp = 0;
        id = 0;

        //sleep(1);
        inp_page = page[i].page_ref;

        for(j = 0; j < frame_number; j++)
        {
            if(frame[j].allotted == false)
            {
                printf("\n\nFault for %d \n", inp_page);
                fault++;
                flag = true;
                frame[j].page_id = inp_page;
                frame[j].frame_uses++;
                frame[j].freq = page[i].page_uses;
                frame[j].allotted = true;
                break;
            }
            else if(frame[j].page_id == inp_page)
            {
                printf("\n\nHit for %d \n",inp_page);
                hit++;
                flag = true;
                frame[j].frame_uses++;
                frame[j].freq = page[i].page_uses;
                frame[j].age = 0;
                break;
            }
        }

        if(flag == false)
        {
            for(j = 0; j < frame_number; j++)
            {
                if(frame[j].freq <= temp_age && frame[j].age > temp)
                {
                    temp_age = frame[j].freq;
                    temp = frame[j].age;
                    id = j;
                }
            }
            
            printf("\n\nFault for %d \n%d\n", inp_page,temp);
            fault++;
            frame[id].page_id = inp_page;
            frame[id].frame_uses = 1;
            frame[id].age = 0;
            frame[id].freq = page[i].page_uses; 
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
            printf("%d %d %d\t",frame[j].page_id,frame[j].age,frame[j].freq);
        }

        

        /*else
        {
            for(j = 0;j < frame_number; j++)
            {
                if(frame[j].allotted == true)
                {
                    frame[j].age++;
                }
            }
        }*/
    
    }

    printf("\n\nNumber of hits : %d\nNumber of faults : %d\n\n",hit,fault);
    return 0;
}