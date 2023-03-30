#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	int pid,status,exitch;
	if((pid=fork())==-1){
		perror("error\n");
		exit(0);
	}
	if(pid == 0){
		sleep(1);
		printf("child process\n");
		exit(0);
	}
	printf("parent process\n");
	if((exitch=wait(&status))==-1){
		perror("during wait()");
		exit(0);
	}
	printf("parent exiting\n");
	exit(0);
}

