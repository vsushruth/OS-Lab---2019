#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct memory
{
    int fileStoredID;
    bool allocated;
    int next;
};

struct files
{
    int ID;
    int startAdd;
    int memReq;
    bool alloted;
};

int main()
{
    int i, j, k, flag = 0, temp = 0;
    unsigned int nextAdd, start;
    int memSize, noFiles;
    
    printf("Enter the size of the memory : ");
    scanf("%d",&memSize);
    struct memory mem[memSize];

    for(i= 0;i < memSize; i++)
    {
        mem[i].allocated = false;
        mem[i].fileStoredID = -1;
        mem[i].next = -1;
    }

    printf("Enter the number of files to be allocated : ");
    scanf("%d", &noFiles);
    struct files file[noFiles];
    
    for(i = 0; i < noFiles; i++)
    {
        flag = 0;
        temp = 0;

        file[i].ID = i;
        file[i].memReq = -1;
        file[i].startAdd = -1;
        file[i].alloted = false;

        printf("\nEnter the start address of file %d : ", i);
        scanf("%d", &file[i].startAdd);
        printf("Enter the amount of memory file %d requires : ", i);
        scanf("%d", &file[i].memReq);
        
        start = file[i].startAdd;
        if((start + file[i].memReq) > memSize || file[i].alloted == true)
        {
            flag = 1;
        }
        else
        {
            for(j = 0; j < memSize; j++)
            {
                if(mem[j].allocated == false)
                    temp++;
            }
            if(temp < file[i].memReq)
                flag = 1;
        }
        
        temp = file[i].memReq;
        if(flag == 1)
        {
            printf("File CANNOT be allocated in the requested location\n");
            file[i].startAdd = -1;
        }    
        else if(flag == 0)
        {
            srand(time(0));
            file[i].alloted = true;
            
            nextAdd = start;
            while(temp)
            {
                nextAdd = (int)(rand() % memSize);
                if(mem[nextAdd].allocated == false && temp > 1)
                {
                    mem[start].allocated = true;
                    mem[start].fileStoredID = file[i].ID;
                    mem[start].next = nextAdd;
                    start = nextAdd;
                    temp--;
                }
                else if(temp == 1)
                {
                    mem[start].allocated = true;
                    mem[start].fileStoredID = file[i].ID;
                    mem[start].next = -1;
                    temp--;
                }
            }
           printf("File has been allocated at the requested location\n");
        }
        
        
    }
    
    printf("\n");
    for(i = 0; i < noFiles; i++)
    {
        if(file[i].alloted == true)
        {
            nextAdd = file[i].startAdd;
            printf("\n\nFile %d\nFile Size : %d :: Start Address : %d \n",file[i].ID, file[i].memReq, file[i].startAdd);
            for(j = file[i].startAdd; j < (file[i].startAdd + file[i].memReq); j++)
            {
                printf("%d-",nextAdd);
                nextAdd = mem[nextAdd].next;
            }
        }
        else
        {
            printf("\nFile %d cannot allocated",file[i].ID);
        }
        
    }
    printf("\n\n");
    
    
    
    return 0;
}