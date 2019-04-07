#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct process
{
    int proID;
    int block_assigned;
    int memory_req;
    int external_fragmentation;
    bool vis;
};

struct partition
{
    int size;
    int partID;
    int internal_fragmentation;
    bool allocated;
};

int main()
{
    int proNum, partNum, totMem;
    int i,j, temp, sum = 0;
    int total_internal_fragmentation = 0, total_external_fragemtation = 0;

    printf("\nEnter the total memory available : ");
    scanf("%d", &totMem);

    printf("\nEnter the number of partitions : ");
    scanf("%d",&partNum);
    struct partition part[partNum];

    for(i = 0; i < partNum; i++)
    {
        part[i].partID = i;
        part[i].internal_fragmentation = 0;
        part[i].allocated = false;

        printf("Enter the size of partition %d : ",i);
        scanf("%d",&temp);

        sum += temp;
        if(sum > totMem)
        {
            part[i].size = totMem - (sum - temp); 
            break;
        }
        else
        {
            part[i].size = temp;
        } 
    }

    if(sum < totMem)
    {
        partNum++;
        part[i].size = totMem - sum;
        part[i].partID = i;
        part[i].internal_fragmentation = 0;
        part[i].allocated = false;
        printf("New partition %d is created of size %d\n",i,part[i].size);
    }

    printf("\nEnter the number of processess : ");
    scanf("%d",&proNum);
    struct process pro[proNum];

    for(i = 0; i < proNum; i++)
    {
        printf("Enter the memory required for process %d : ",i);
        scanf("%d", &pro[i].memory_req);

        pro[i].proID = i;
        pro[i].external_fragmentation = 0;
        pro[i].block_assigned = -1;
        pro[i].vis = false;

        for( j = 0; j < partNum; j++)
        {
            if(part[j].size >= pro[i].memory_req && part[j].allocated == false)
            {
                pro[i].vis = true;
                pro[i].block_assigned = part[j].partID;
                
                part[j].internal_fragmentation = part[j].size - pro[i].memory_req;
                part[j].allocated = true;

                total_internal_fragmentation += part[j].internal_fragmentation;
                break;
            }
        }
    }

    for(j = 0; j < partNum; j++)
    {
        if(part[j].allocated == false)
        {
            printf("%d \t",part[j].size);
            total_external_fragemtation += part[j].size;
            part[j].internal_fragmentation = -1;
        }
    }

    printf("\nProID\tMemReq\tAllocated\tBlockAllocated\n");
    for(i = 0; i < proNum; i++)
    {
        if(pro[i].vis == true)
        {
            printf("%d\t%d\tYES\t\t%d\n",pro[i].proID, pro[i].memory_req, pro[i].block_assigned);
        }
        else
        {
            printf("%d\t%d\tNO\t\t%d\n",pro[i].proID, pro[i].memory_req, pro[i].block_assigned);            
        }
        
    }

    printf("\nInteranl fragmentation : \n");
    for(i = 0; i < partNum; i++)
    {
        if(part[i].internal_fragmentation == -1)
        {
            printf("%d  Not Allocated\n",part[i].partID);
        }
        else
        {
            printf("%d  %d\n",part[i].partID, part[i].internal_fragmentation);
        }
        
    }

    printf("\nTotal internal Fragmentation: %d\n",total_internal_fragmentation);
    printf("Total external Fragmentation: %d\n\n", total_external_fragemtation);
    return 0;
}
