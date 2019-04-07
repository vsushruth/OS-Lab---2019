#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct process
{
    int proID;
    int arrival_time;
    int burst_time;
    int rem_time;
    int comp_time;
    int wait_time;
    int tat;
    bool fin;
};

int main() {
    int noPro, loc_time = 0, idle = 0;
    double tot_wait = 0, tot_tat = 0;
    int swap_var, temp, id, flag;
    int i,j;
    
    printf("Enter the number of processess : ");
    scanf("%d",&noPro);
    struct process pro[noPro];
    
    printf("Enter the details of processess : ");
    for(i = 0;i < noPro; i++)
    {
        printf("\nProcess %d : ",i);
        printf("Arrival time : ");
        scanf("%d",&pro[i].arrival_time);
        
        printf("Burst time : ");
        scanf("%d",&pro[i].burst_time);
        
        pro[i].fin = false;
        pro[i].rem_time = pro[i].burst_time;
        pro[i].proID = i;
    }
    
    for(i = 0; i < noPro; i++)
    {
        temp = i;
        for(j = i+1; j < noPro; j++)
        {
            if(pro[temp].arrival_time > pro[j].arrival_time)
                temp = j;
            else if((pro[temp].arrival_time == pro[j].arrival_time) && (pro[temp].burst_time > pro[j].burst_time))
                temp = j;
        }
        
        if(temp != i)
        {
            swap_var = pro[temp].arrival_time;
            pro[temp].arrival_time = pro[i].arrival_time;
            pro[i].arrival_time = swap_var;
            
            swap_var = pro[temp].burst_time;
            pro[temp].burst_time = pro[i].burst_time;
            pro[i].burst_time = swap_var;
            
            swap_var = pro[temp].proID;
            pro[temp].proID = pro[i].proID;
            pro[i].proID = swap_var;
            
            pro[i].rem_time = pro[i].burst_time;
            pro[temp].rem_time = pro[temp].burst_time;
        }
        
    }
    
    printf("\n");
    /*for(i = 0; i < noPro; i++)
    {
        printf("%d %d\n",pro[i].arrival_time,pro[i].burst_time);
    }*/
    
    temp = noPro;
    i = 0; loc_time = 0;
    while(temp)
    {
        swap_var = 999;
        id = 999;
        
        for(i = 0; i < noPro; i++)
        {
            if(pro[i].arrival_time <= loc_time && pro[i].rem_time < swap_var && pro[i].fin == false)
            {
                swap_var = pro[i].rem_time;
                id = i;
            }
        }
        
        if(id != 999)
        {
            pro[id].rem_time--;
            loc_time++;
            
            if(pro[id].rem_time == 0)
            {
                pro[id].fin = true;
                pro[id].comp_time = loc_time;
                pro[id].wait_time = loc_time - (pro[id].arrival_time + pro[id].burst_time);
                pro[id].tat = loc_time - pro[id].arrival_time;
                
                tot_wait += pro[id].wait_time;
                tot_tat += pro[id].tat;
                i++;
                temp--;
            }
                
        }
        else
        {
            loc_time++;
            idle++;
        }
    
    }
    
    printf("ProID\tArrival\tBurst\tComp\tWait\tTAT\n");
    for(i = 0; i < noPro; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pro[i].proID, pro[i].arrival_time, pro[i].burst_time, pro[i].comp_time, pro[i].wait_time, pro[i].tat);
    }
    
    tot_wait /= noPro;
    tot_tat /= noPro;
    printf("\n\nAvg Wait time : %f\nAvg Turn Arount Time : %f\nTotal CPU idle time : %d\n",tot_wait, tot_tat, idle);
	
	return 0;
}

