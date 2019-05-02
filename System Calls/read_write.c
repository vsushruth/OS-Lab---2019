#include<stdio.h> 
#include <fcntl.h> 
main() 
{ 
  int sz,sz1; 
  char *c=(char *)calloc(100,sizeof(char));
  int fd = open("jelwin.txt", O_RDWR); 
  if (fd < 0) 
  { 
     perror("r1"); 
     exit(1); 
  } 
  
  sz = write(fd, "happy new year\n", strlen("happy new year\n")); 
  close(fd);
  int fd1=open("jelwin.txt",O_RDWR);

  sz1=read(fd1,c,sz);
  c[sz1]='\0';
  printf("the message is %s\n",c);
  
  close(fd1); 
} 
