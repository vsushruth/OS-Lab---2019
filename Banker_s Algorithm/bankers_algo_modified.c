#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int available[50], max[50][50], allocation[50][50], need[50][50], seq[50];
bool finish[50];
int work[50];


bool request(int n, int m, int index)
{
    int pro, i, j;
    int req_arr[m], pro_max[m], pro_alloc[m], pro_need[m];
    bool finish = false;
    int pid;

    printf("Enter process ID : ");
    scanf("%d", &pid);

    printf("Enter the maximum demand of process : ");
    for(i = 0; i < m; i++)
        scanf("%d", &pro_max[i]);

    printf("Enter the resources allocation of process : ");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &pro_alloc[i]);
        pro_need[i] = pro_max[i] - pro_alloc[i];
    }

    for(j = 0; j < m; j++)
    {
        if(need[i][j] > work[j])
        {
            break;
        }
    }

    if(j == m)
    {
        for(j = 0; j < m; j++)
        {
            work[j] += need[i][j];
        }

        finish = true;
        seq[index] = pid;
    }
    
    if(finish != true)
    {
        printf("System is NOT in Safe State\n");
        return false;
    }
    return true;
}


void checkSafe(int n, int m, int choice)
{
    int i, j, rem_pro, count, flag;
    int index;

    for(i = 0; i < m; i++)
        work[i] = available[i];

    for(i = 0; i < 50; i++)
        finish[i] = false;

    i = 0, count = 0;
    rem_pro = 0;
    flag = 0;

    while(rem_pro < n)
    {
        index = rem_pro;
        if(finish[i] == false)
        {
            for(j = 0; j < m; j++)
            {
                if(need[i][j] > work[j])
                {
                    break;
                }
            }

            if(j == m)
            {
                for(j = 0; j < m; j++)
                {
                    work[j] += need[i][j];
                }

                rem_pro++;
                index++;
                finish[i] = true;
                seq[index] = i;
                flag++;
            }
        }

        if(i == n-1)
        {
            if(flag == 0)
            {
                printf("\nSystem is NOT in Safe State!!\n");
                return;
            }

            flag = 0;
            i = 0;
        }
        else
        {
            i++;
        }

        printf("Safe sequence : ");
        for(i = 0; i < rem_pro; i++)
        {
            printf("%d ",seq[i]);
        }
        printf("\n");


        if(rem_pro == choice)
        {
            bool ans = request(n, m, rem_pro);
            if(ans == false)
                return;
            else
                index++;
            
        }
    }

    printf("\nSystem is in safe state\n");
    printf("Safe sequence : ");
    
    for(i = 0; i <= n; i++)
    {
        printf("%d ",seq[i]);
    }
    printf("\n");

}




int main()
{
    int i,j,n,m,req;

    printf("\nEnter number processess : ");
    scanf("%d", &n);

    printf("Enter number of types of resources : ");
    scanf("%d", &m);

    printf("Enter the available resources :\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d",&available[i]);
    }

    printf("\nEnter allocation matrix :\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d : ",i);
        for(j = 0; j < m; j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("\nEnter maximum demand matrix :\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d : ",i);
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];    
        }
    }

    int choice;
    printf("\nEnter after how many processes you want input new one : ");
    scanf("%d", &choice);

    checkSafe(n, m, choice);

}