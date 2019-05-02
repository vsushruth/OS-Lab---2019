#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
	int fd= creat("jelwin.txt",  S_IRWXU );
	printf("%d",fd);
}
