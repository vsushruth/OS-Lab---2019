#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
 
int main()
{
        int fd=0;
        if((fd=open("jelwin.txt",O_RDONLY)) < -1)
                return 1;
 
        char buffer[15];
        read(fd,buffer,15);
        printf("%s\n",buffer);
 
        lseek(fd,10,SEEK_SET);
	read(fd,buffer,9);
	buffer[9]='\0';
	printf("%s\n",buffer);

}

