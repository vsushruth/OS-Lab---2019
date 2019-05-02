#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
  
int main() 
{
       int fd;
	fd=open("jelwin.txt",O_WRONLY | O_APPEND);
 	int fd1;
	close(fd);
	fd1=dup(fd);
	printf("%d",fd1);	
	write(fd,"original\n",9);
	write(fd1,"duplicate\n",10);
	close(fd);

}	
