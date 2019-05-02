#include<stdio.h>
#include<fcntl.h>
int main()
{ 
    if (fork()== 0) 
        printf(" hello from child\n"); 
    else
    { 
        printf(" hello from parent\n"); 
        wait(NULL); 
        printf(" child has terminated\n"); 
    } 
  
    printf("Bye\n"); 
    return 0; 
} 

