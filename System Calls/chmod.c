#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
int z= chmod("jelwin.txt",S_IRUSR);
printf("%d\n",z);
int fd=access("jelwin.txt",W_OK);
if(fd==0)
	printf("file is writable\n");
else
	printf("file is not writable\n");
}
