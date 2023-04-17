#include<stdio.h>
#include <stdlib.h> 

int fork();
int execv();
int wait();

int main(int argc,char ** argv) {
	int pid;
	char *arg[]={"/bin/ls -l",0}; 
	printf("\nParent process"); 
	pid=fork();
	if(pid==0){
		execv("/bin/ls",arg);
		printf("\nChild process");
	}
	else{
		wait();
		printf("\nParent process"); 
		exit(0);
	}
}
