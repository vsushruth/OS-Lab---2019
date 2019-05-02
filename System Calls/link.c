#include<stdio.h>
#include<unistd.h>
int main(){
	int f;
	
	f=link("jelwin.txt","jelwin1.txt");
	printf("%d",f);
}
