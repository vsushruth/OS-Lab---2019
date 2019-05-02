#include<stdio.h>
#include<unistd.h>
int main()
{
int fd;
fd=access("jelwin.txt",F_OK);
if(fd==0)
	printf("file exists\n");
else
	printf("file does not exist\n");

int fd1=access("jelwin.txt",R_OK);
if(fd1==0)
	printf("file is readable\n");
else
	printf("file is not readable\n");
int fd2=access("jelwin.txt",W_OK);
if(fd2==0)
	printf("file is writable\n");
else
	printf("file is not readable\n");
}
