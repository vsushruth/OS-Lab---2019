#include<stdio.h>
#include<fcntl.h>
int main()
{
int f;
f=chown("jelwin.txt",1000,27);
printf("%d\n",f);
}
