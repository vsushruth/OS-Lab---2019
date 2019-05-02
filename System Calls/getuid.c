#include<stdio.h>
#include<fcntl.h>
int main()
{
printf("real user id: %d",getuid());
printf("\neffective real user id:%d",geteuid());
printf("\nreal group id is:%d",getgid());
printf("\neffective group id is :%d",getegid());
printf("\nprocess id is:%d",getpid());
printf("\nparent bprocess id is :%d\n",getppid());

}
