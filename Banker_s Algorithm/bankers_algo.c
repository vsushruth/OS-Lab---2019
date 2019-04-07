#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int available[50], max[50][50], allocation[50][50], need[50][50], seq[50];
bool finish[50];

void checkSafe(int n, int m)
{
    int i, j, rem_pro, count, flag;
    int work[50];

    for(i = 0; i < m; i++)
        work[i] = available[i];

    for(i = 0; i < 50; i++)
        finish[i] = false;

    i = 0, count = 0;
    rem_pro = 0;
    flag = 0;

    while(rem_pro < n)
    {
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

                finish[i] = true;
                seq[rem_pro++] = i;
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
    }

    printf("\nSystem is in safe state\n");
    printf("Safe sequence : ");
    for(i = 0; i < n; i++)
        printf("%d ",seq[i]);
    printf("\n");

}

void request(int n, int m)
{
    int pro, i, j;
    int req_arr[m];

    printf("\nEnter the process to be requested : ");
    scanf("%d", &pro);

    printf("Enter the resources to be requested for process %d : ",pro);
    for(i = 0; i < m; i++)
    {
        scanf("%d", &req_arr[i]);
    }

    for(j = 0; j < m; j++)
    {
        if( req_arr[j] > need[pro][j])
        {
            printf("ERROR : Process exceeds maximum claim\n");
            break;
        }
        else if(req_arr[j] > available[j])
        {
            printf("ERROR : Resources not available. Process pushed to waiting\n");
            break;
        }
    }
    
    if(j == m)
    {
        for(i = 0; i < m; i++)
        {
            allocation[pro][i] += req_arr[i];
            available[i] -= req_arr[i];
            need[pro][i] -= req_arr[i];
        }   

        checkSafe(n, m);
    }

}


int main()
{
    int i,j,n,m,req;

    printf("Enter number processess : ");
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
        printf("Process %d : ", i);
        for(j = 0; j < m; j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("\nEnter maximum demand matrix :\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d : ", i);
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

    checkSafe(n, m);

    printf("\nEnter the number of requests : ");
    scanf("%d", &req);

    for(i = 0; i < req; i++)
    {
        request(n,m);
        printf("\n");
    }

}