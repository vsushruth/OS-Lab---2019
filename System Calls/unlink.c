#include<stdio.h>
#include<unistd.h>
int main()
{
int f=unlink("jelwin1.txt");
printf("%d",f);
}

