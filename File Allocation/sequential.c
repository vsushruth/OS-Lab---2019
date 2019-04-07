#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct memory
{
    int fileStoredID;
    bool allocated;
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
    int i, j, k, start, flag = 0;
    int memSize, noFiles;
    
    printf("Enter the size of the memory : ");
    scanf("%d",&memSize);
    struct memory mem[memSize];

    for(i= 0;i < memSize; i++)
    {
        mem[i].allocated = false;
        mem[i].fileStoredID = -1;
    }

    printf("Enter the number of files to be allocated : ");
    scanf("%d", &noFiles);
    struct files file[noFiles];
    
    for(i = 0; i < noFiles; i++)
    {
        flag = 0;

        file[i].ID = i;
        file[i].memReq = -1;
        file[i].startAdd = -1;
        file[i].alloted = false;

        printf("\nEnter the start address of file %d : ", i);
        scanf("%d", &file[i].startAdd);
        printf("Enter the amount of memory file %d requires : ", i);
        scanf("%d", &file[i].memReq);
        
        start = file[i].startAdd;
        if((start + file[i].memReq) > memSize)
        {
            flag = 1;
        }
        else
        {
            for(j = start; j < (start+file[i].memReq); j++)
            {
                if(mem[j].allocated == true)
                {    
                        flag = 1;
                        break;
                }
            }
        }
        
        
        if(flag == 1)
        {
            printf("File CANNOT be allocated in the requested location\n");
            file[i].startAdd = -1;
        }    
        else if(flag == 0)
        {
            file[i].alloted = true;
            for(j = start; j < (start+file[i].memReq); j++)
            {
                mem[j].fileStoredID = file[i].ID;
                mem[j].allocated = true;
            }
            printf("File has been allocated at the requested location\n");
        }
        
        
    }
    
    printf("\n");
    for(i = 0; i < noFiles; i++)
    {
        if(file[i].alloted == true)
        {
            printf("\nFile %d :: File Size : %d :: ",file[i].ID, file[i].memReq);
            for(j = file[i].startAdd; j < (file[i].startAdd + file[i].memReq); j++)
            {
                printf("%d-",j);
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