#include<stdio.h>
#include<fcntl.h>
int main()
{
char * args[]={"./access",NULL};
execl("./access",args);
}

