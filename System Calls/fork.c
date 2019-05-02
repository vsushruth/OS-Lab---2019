#include<stdio.h>
#include<fcntl.h>
int main()
{
if(fork()==0)
	printf("child process\n");
else
	printf("parent process\n");
}
